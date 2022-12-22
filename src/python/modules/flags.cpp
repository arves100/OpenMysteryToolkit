/*
* @file: python/modules/flags.cpp
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include <python/modules.h>
#include <game/game.h>
#include <def/defaults.h>

/*!
* Gets a flag
* @param id Flag ID
* @return The flag value
*/
static auto get(FlagId id)
{
	return theGame().GetFlag(id);
}

/*!
* Sets a flag
* @param id Flag ID
* @param value Flag value
*/
static void set(FlagId id, Flag value)
{
	theGame().SetFlag(id, value);
}

MOD_FUNC(flags)
{
	m.def("get", get);
	m.def("set", set);
}
