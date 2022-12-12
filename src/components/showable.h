/*
* @file: def/showable.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <python/link.h>

struct ShowableComponent
{
    bool show;

    // def on_show(Entity: entity) -> None
    PythonLink on_show;

    // def on_hide(Entity: entity) -> None
    PythonLink on_hide;
};
