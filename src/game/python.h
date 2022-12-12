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

class Python
{
  public:
	Python()
	    : pyInit_(false)
	{}

	~Python() {
		Destroy();
	}

	bool IsInit() { return pyInit_; }
	bool Init(nctl::String gamePath, nctl::String ep) {
		try
		{
			pybind11::initialize_interpreter();

			// append the script path
			nctl::String app = "import sys\nsys.path.append(\"";
			app += ncine::fs::joinPath(gamePath, "scripts");
			app += "\")";
			pybind11::exec(app.data());

			entrypoint_ = pybind11::module_::import(ep.data());
		}
		catch (...)
		{
			return false;
		}

		return true;
	}

	void Destroy() {

		// dereference ep to fix crash
		entrypoint_ = pybind11::module_();

		if (pyInit_)
			pybind11::finalize_interpreter();

		pyInit_ = false;
	}

	template <typename... Args>
	void Call(nctl::String name, Args... args)
	{
		PythonLink link;
		if (link.Link(entrypoint_, name))
			link.Call(args...);
	}

  protected:
	pybind11::module_ entrypoint_;
	bool pyInit_;
};
