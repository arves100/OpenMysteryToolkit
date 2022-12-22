/*
* @file: python/omt.cpp
* @author: Arves100
* @date: 10/14/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include <python/modules.h>
#include <python/omt.h>
#include <python/link.h>

PYBIND11_EMBEDDED_MODULE(omt, m)
{
	auto system = m.def_submodule("system", "Generic functionality of the engine");
	MOD_CALL(system, system);

	auto switches = m.def_submodule("switches", "Switches");
	MOD_CALL(switches, switches);

	auto flags = m.def_submodule("flags");
	MOD_CALL(flags, flags);

	auto logs = m.def_submodule("log", "Defines logging utilities for the game");
	MOD_CALL(log, logs);

	auto ent = m.def_submodule("entity", "Entity functionalities");
	MOD_CALL(entity, ent);
}

// static declaration!
pybind11::module_ PythonLink::inspect_ = pybind11::module_();
