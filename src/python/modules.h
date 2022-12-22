/*
* @file: python/modules.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <python/inc.h>

/*!
* Defines a module function
*/
#define MOD_FUNC(x) void mod_init_##x (pybind11::module& m)

/*!
* Calls a defined module
*/
#define MOD_CALL(x, m) mod_init_##x (m);

/*!
* The system module contains all the core functionalities of the engine
*/
MOD_FUNC(system);

/*!
* The constants module defines all the constants of the engine (such as directions)
*/
MOD_FUNC(constants);

/*!
* The entity module defines all the Entity related functions and classes
*/
MOD_FUNC(entity);

/*!
* The switches module defines all the functions that access the developer's switches for game events
*/
MOD_FUNC(switches);

/*!
 * The flags module defines all the functions that access the developer's flags for game events
 */
MOD_FUNC(flags);

/*!
* The logs module defines all the functions related for logging
*/
MOD_FUNC(log);
