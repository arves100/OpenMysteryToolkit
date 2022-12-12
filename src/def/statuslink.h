/*
* @file: components/statuslink.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <python/link.h>

struct StatusLink
{
    // def status_start(entity: Entity, attacker: Entity) -> None
    PythonLink on_start;

    // def status_end(entity: Entity) -> None
    PythonLink on_end;

    // def status_cycle(entity: Entity) -> None
    PythonLink on_cycle;
};
