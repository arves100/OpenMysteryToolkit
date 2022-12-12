/*
* @file: components/updatable.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <python/link.h>

// entity
struct UpdatableComponent
{
    // def on_update(entity: Entity) -> None
    PythonLink link;
};
