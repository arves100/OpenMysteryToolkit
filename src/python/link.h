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
		catch (std::exception& ex)
		{
			LOGW_X("Unable to link attribute %s@%s: %s", attr.data(), mod.data(), ex.what());
			return false;
		}

		return Link(module, attr);
	}

	bool Link(pybind11::module_ mod, nctl::String attr)
	{
		try
		{
			if (!pybind11::hasattr(mod, attr.data()))
				return false;
		}
		catch (std::exception &ex)
		{
			LOGW_X("Unable to link attribute %s: %s", attr.data(), ex.what());
			return false;
		}

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
		catch (std::exception &ex)
		{
			LOGW_X("Unable to execute %s callback! Error:\n%s", name_.data(), ex.what());
		}
	}

  protected:
    nctl::String name_;
	pybind11::module_ module_;
	bool useFunction_;
	pybind11::function function_;
};
