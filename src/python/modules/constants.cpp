/*
* @file: python/modules/constants.cpp
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include <python/modules.h>

#include <def/gender.h>
#include <def/scriptactivation.h>
#include <def/direction.h>

MOD_FUNC(constants)
{
	pybind11::enum_<Direction>(m, "Directions")
		.value("up", Direction::Up)
		.value("down", Direction::Down)
		.value("left", Direction::Left)
		.value("right", Direction::Right)
		.value("downleft", Direction::DownLeft)
		.value("downright", Direction::DownRight)
		.value("upleft", Direction::UpLeft)
		.value("upright", Direction::UpRight);

	pybind11::enum_<Gender>(m, "Gender")
		.value("male", Gender::Male)
		.value("female", Gender::Female)
		.value("unknown", Gender::Unknown);

	pybind11::enum_<ScriptActivation>(m, "ScriptActivation")
		.value("nextshot", ScriptActivation::NextShot)
		.value("enableaftermapchange", ScriptActivation::EnableAfterMapChange)
		.value("disable", ScriptActivation::Disable)
		.value("disableuntilgamerestart", ScriptActivation::DisableUntilGameRestart);
}
