/*
* @file: components/statsmod.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <def/statuslink.h>
#include <def/cycleinfo.h>
#include <def/stats.h>

struct StatsModComponent
{
    // cycles.each is not used as it will always be 1
    // link.on_cycle because status mod doesn't tick

    CycleInfo cycles;
    StatusLink link;
    Stats mod;
    bool malus;
};
