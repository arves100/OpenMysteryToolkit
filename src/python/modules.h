/*
* @file: python/modules.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <python/inc.h>

#define MOD_FUNC(x) void mod_init_##x (pybind11::module& m)
#define MOD_CALL(x, m) mod_init_##x (m);

MOD_FUNC(system);
MOD_FUNC(constants);
MOD_FUNC(entity);
MOD_FUNC(switches);
MOD_FUNC(flags);
MOD_FUNC(log);
