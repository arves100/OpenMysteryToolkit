/*
* @file: components/paralysis.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <def/cycleinfo.h>
#include <def/statuslink.h>

struct ParalysisComponent
{
    CycleInfo cycles;
    StatusLink link;
};
