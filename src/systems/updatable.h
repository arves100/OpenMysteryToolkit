/*
* @file: systems/updatable.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <abstract/ISystem.h>

class UpdateSystem final : public UpdatableSystem
{
public:
	void Update(uint64_t cycles, entt::registry& reg);
};
