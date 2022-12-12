/*
* @file: components/poison.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <def/statuslink.h>
#include <def/cycleinfo.h>

struct PoisonComponent
{
    CycleInfo cycles;
    StatusLink link;
    uint8_t pct;
};
