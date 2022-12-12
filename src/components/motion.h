/*
* @file: components/motion.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <def/direction.h>
#include <python/link.h>

#include <cstdint>

struct MotionComponent
{
    uint8_t velocity;
    Direction direction;

    // def on_change(entity: Entity, x: int, y: int) -> None
    PythonLink on_change;
};
