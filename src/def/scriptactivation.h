/*
* @file: def/scriptactivation.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

/*!
* Types of events when the script will be activated
*/
enum class ScriptActivation
{
	NextShot,
	EnableAfterMapChange,
	DisableUntilGameRestart,
	Disable,
};
