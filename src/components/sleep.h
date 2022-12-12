/*
* @file: components/sleep.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <def/statuslink.h>
#include <def/cycleinfo.h>

struct SleepComponent
{
    CycleInfo cycles;
    StatusLink link;
};
