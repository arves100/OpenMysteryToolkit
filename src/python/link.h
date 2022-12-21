/*
* @file: python/link.h
* @author: Arves100
* @date: 10/14/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <python/inc.h>

#include <nctl/String.h>

class PythonLink
{
public:
	explicit PythonLink() = default;

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

		modname_ = modname;
		module_ = mod;
		name_ = attr;
		useFunction_ = false;
		return true;
	}

	bool Link(pybind11::function fnc)
	{
		function_ = fnc;
		useFunction_ = true;
		return true;
	}

	bool IsValid() const { return !name_.isEmpty(); }

	template <typename... Args>
	inline void Call(Args&&... args)
	{
		try
		{
			if (useFunction_)
				function_(args...);
			else
				module_.attr(name_.data())(args...);
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
    nctl::String name_;
	pybind11::module_ module_;
	bool useFunction_;
	pybind11::function function_;
	nctl::String modname_;
};
