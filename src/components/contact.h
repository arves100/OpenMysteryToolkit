/*
* @file: components/contact.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <def/statuslink.h>
#include <vector>

struct ContactComponent
{
	// def on_crash
    PythonLink crash;

	// def on_enter
    PythonLink enter;

	// def on_exit
    PythonLink exit;

    //std::vector<Entity&> contacts;
};
