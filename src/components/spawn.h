/*
* @file: components/spawn.h
* @author: Arves100
* @date: 10/16/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <def/spawninfo.h>
#include <nctl/Array.h>

struct SpawnComponent
{
	nctl::Array<SpawnInfo> spawns;
};
