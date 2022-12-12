/*
* @file: systems/stats.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <abstract/ISystem.h>

class StatsSystem final : public UpdatableSystem
{
public:
	void Update(uint64_t cycles, entt::registry& reg) override;
};
