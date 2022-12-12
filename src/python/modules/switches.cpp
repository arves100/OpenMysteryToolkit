/*
* @file: python/modules/switches.cpp
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include <python/modules.h>
#include <game/game.h>
#include <def/defaults.h>

static auto get(SwitchId id)
{
	return theGame().GetSwitch(id);
}

static void set(SwitchId id, bool value)
{
	theGame().SetSwitch(id, value);
}

MOD_FUNC(switches)
{
	m.def("get", get);
	m.def("set", set);
}
