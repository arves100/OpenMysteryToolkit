/*
* @file: systems/spawn.h
* @author: Arves100
* @date: 10/16/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <abstract/ISystem.h>

class SpawnSystem final : public InitOnlySystem
{
public:
	void Init(entt::registry &reg) override;
	void DeInit(entt::registry &reg) override;

private:
	void OnUpdate(entt::registry & reg, entt::entity entity);
};
