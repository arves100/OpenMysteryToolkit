/*
* @file: def/spawninfo.h
* @author: Arves100
* @date: 10/16/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <stdint.h>
#include <entt/entt.hpp>

struct SpawnInfo
{
	uint32_t x;
    uint32_t y;
    entt::entity e;

	SpawnInfo(uint32_t x, uint32_t y, entt::entity e)
	    : x(x), y(y), e(e) {}
};
