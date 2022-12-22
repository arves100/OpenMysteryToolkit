/*
 * @file: game/python.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <python/inc.h>
#include <python/link.h>

#include <ncine/FileSystem.h>

/*!
* This class manages the basics of the Python interpreter integration
*/
class Python final
{
  public:
	/*!
	* Default constructor
	*/
	explicit Python()
	    : pyInit_(false)
	{}

	/*!
	* Default deconstructor
	*/
	~Python() {
		Destroy();
	}

	/*!
	* Check if the interpreter was initialized or not
	* @return true if the interpreter was initialized, otherwise false
	*/
	bool IsInit() const { return pyInit_; }


	/*!
	* Initializes the Python interpreter
	* @param gamePath Directory of where the game content it is
	* @param ep Main script entrypoint
	* @return true if the interpreter was initialized, otherwise false
	*/
	bool Init(nctl::String gamePath, nctl::String ep) {
		try
		{
			// TODO: Sandboxing with Py_InitializeEx?
			pybind11::initialize_interpreter();

			// append the script path
			nctl::String app = "import sys\nsys.path.append(\"";
			app += ncine::fs::joinPath(gamePath, "scripts");
			app += "\")";
			pybind11::exec(app.data());

			PythonLink::inspect_ = pybind11::module_::import("inspect");
		}
		catch (const pybind11::error_already_set& e)
		{
			LOGE_X("Unable to start the Python interpreter\n%s", e.what());
			return false;
		}
		catch (const std::exception &e)
		{
			LOGE_X("Unable to start the Python interpreter\n%s", e.what());
			return false;
		}

		try
		{
			entrypoint_ = pybind11::module_::import(ep.data());
		}
	    catch (const pybind11::error_already_set& e)
		{
			LOGE_X("Unable to import the script %s!\n%s", ep.data(), e.what());
			return false;
		}

		epname_ = ep;
		return true;
	}

	/*!
	* Shuts down the Python interpreter
	*/
	void Destroy() {

		// dereference modules to fix python shutdowns
		entrypoint_ = pybind11::module_();
		PythonLink::inspect_ = pybind11::module_(); // static!

		if (pyInit_)
			pybind11::finalize_interpreter();

		pyInit_ = false;
	}

	/*!
	* Calls a Python attribute from the entrypoint
	* @param name Name of the attribute to call
	* @param args Variadic arguments
	*/
	template <typename... Args>
	void Call(nctl::String name, Args... args)
	{
		PythonLink link;
		if (link.Link(epname_, entrypoint_, name))
			link.Call(args...);
	}

  protected:
	/*!
	* Name of the main entrypoint script
	*/
	nctl::String epname_;

	/*!
	* Pointer to the main script
	*/
	pybind11::module_ entrypoint_;

	/*!
	* If the interpreter was initialized
	*/
	bool pyInit_;
};
