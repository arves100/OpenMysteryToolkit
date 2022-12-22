/*
* @file: python/modules/switches.cpp
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include <python/modules.h>
#include <game/game.h>
#include <def/defaults.h>

/*!
* Gets a switch
* @param id Switch ID
* @return The switch value
*/
static auto get(SwitchId id)
{
	return theGame().GetSwitch(id);
}

/*!
* Sets a switch
* @param id Switch ID
* @param value Switch value
*/
static void set(SwitchId id, bool value)
{
	theGame().SetSwitch(id, value);
}

MOD_FUNC(switches)
{
	m.def("get", get);
	m.def("set", set);
}
