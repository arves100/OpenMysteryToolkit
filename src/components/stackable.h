/*
* @file: components/stackable.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <python/link.h>

struct StackableComponent
{
    // def on_stack(entity: Entity, stacked_item: Entity) -> None
    PythonLink on_stack;

    // def on_unstack(entity: Entity, unstacked_item: Entity) -> None
    PythonLink on_unstack;

    uint16_t count;
};
