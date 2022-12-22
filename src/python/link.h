/*
* @file: python/link.h
* @author: Arves100
* @date: 10/14/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <python/inc.h>

#include <nctl/String.h>

class Python; // forward decl

/*!
* This class manages a connection between a Python function and the C++ code
*/
class PythonLink
{
	friend Python; // violates oop...

  public:
	/*!
	* Default constructor
	*/
	explicit PythonLink() = default;

	/*!
	* Links a function contained inside a module
	* @param mod Name of the module
	* @param attr Name of the function
	* @return true if the link succeeded, otherwise false
	*/
	bool Link(nctl::String mod, nctl::String attr)
	{
		pybind11::module module;

		try
		{
			module = pybind11::module_::import(mod.data());
		}
		catch (const pybind11::error_already_set& ex)
		{
			LOGW_X("Unable to link attribute %s for module %s: %s", attr.data(), mod.data(), ex.what());
			return false;
		}

		return Link(mod, module, attr);
	}

	/*!
	* Links a function contained inside a module
	* @param modname Name of the module
	* @param mod Module reference
	* @param attr Name of the function
	* @return true if the link succeeded, otherwise false
	*/
	bool Link(nctl::String modname, pybind11::module_ mod, nctl::String attr)
	{
		try
		{
			if (!pybind11::hasattr(mod, attr.data()))
			{
				LOGW_X("Module %s doesn't have attribute %s", modname.data(), attr.data());
				return false;
			}
		}
		catch (const pybind11::error_already_set &ex)
		{
			LOGW_X("Unable to link attribute %s for module %s: %s", attr.data(), modname.data(), ex.what());
			return false;
		}

		try
		{
			isAsync_ = inspect_.attr("iscoroutinefunction")(mod.attr(attr.data())).cast<bool>();
		}
		catch (const pybind11::error_already_set &ex)
		{
			LOGW_X("Unable to check function awaitable info for function %s inside module: %s", attr.data(), modname.data(), ex.what());
			return false;
		}

		modname_ = modname;
		module_ = mod;
		name_ = attr;
		useFunction_ = false;
		return true;
	}

	/*!
	* Links a raw python function
	* @param fnc Function reference
	*/
	bool Link(pybind11::function fnc)
	{
		try
		{
			name_ = fnc.attr("__name__").cast<std::string>().c_str();
			isAsync_ = inspect_.attr("iscoroutinefunction")(fnc).cast<bool>();
		}
		catch (const pybind11::error_already_set &ex)
		{
			LOGW_X("Unable to get function info: %s", ex.what());
			return false;
		}

		function_ = fnc;
		useFunction_ = true;
		return true;
	}

	/*!
	* Checks if the link is valid or not
	* @return true if the link is valid, otherwise false
	*/
	bool IsValid() const { return !name_.isEmpty(); }

	/*!
	* Calls the linked Python function
	* @param args Arguments of the function
	*/
	template <typename... Args>
	inline void Call(Args&&... args)
	{
		try
		{
			if (!isAsync_)
			{
				// normal python functions
				if (useFunction_)
					function_(args...);
				else
					module_.attr(name_.data())(args...);

				return;
			}

			// async functions (coroutine object)
			pybind11::object co_obj;

			if (useFunction_)
				co_obj = function_(args...);
			else
				co_obj = module_.attr(name_.data())(args...);



		}
		catch (const pybind11::error_already_set &ex)
		{
			if (useFunction_)
				LOGW_X("Unable to execute function %s! Error:\n%s", name_.data(), ex.what());
			else
				LOGW_X("Unable to execute %s callback from module %s! Error:\n%s", name_.data(), modname_.data(), ex.what());
		}
	}

  protected:
	/*!
	* Static reference of the inspect module, used for investigating if a linked function is async or not
	*/
	static pybind11::module_ inspect_;

	/*!
	* Function name
	*/
    nctl::String name_;

	/*!
	* Link of the Python module
	*/
	pybind11::module_ module_;

	/*!
	* If the linked function is a raw function or a module
	*/
	bool useFunction_;

	/*!
	* Raw function reference
	*/
	pybind11::function function_;

	/*!
	* Module name
	*/
	nctl::String modname_;

	/*!
	* If the function is async or not
	*/
	bool isAsync_;
};
