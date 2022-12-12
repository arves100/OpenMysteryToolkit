/*
* @file: systems/stats.cpp
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <systems/stats.h>

// components
#include <components/monster.h>
#include <components/poison.h>
#include <components/sleep.h>
#include <components/statsmod.h>
#include <components/paralysis.h>

void StatsSystem::Update(uint64_t cycles, entt::registry& reg)
{
	auto view = reg.view<PoisonComponent, MonsterComponent>();
	view.each([cycles, &reg](const auto entity, auto& poison, auto& battle) {
		if (poison.cycles.done == poison.cycles.end)
		{
			poison.link.on_end.Call(entity);
			reg.remove<PoisonComponent>(entity);
		}
		else if (!(cycles % poison.cycles.each))
		{
			battle.stats.hp -= uint32_t((battle.stats.hp * poison.pct) / 100);
			poison.link.on_cycle.Call(entity);
			poison.cycles.done++;

			if (battle.stats.hp <= 0)
			{
				battle.alive = false;
				battle.on_die.Call(entity, entt::null);
			}
		}
	});

	auto view2 = reg.view<SleepComponent, MonsterComponent>();
	view2.each([cycles, &reg](const auto entity, auto& sleep, auto& stats) {
		if (sleep.cycles.done == sleep.cycles.end)
		{
			sleep.link.on_end.Call(entity);
			reg.remove<SleepComponent>(entity);
		}
		else if (!(cycles % sleep.cycles.each))
		{
			sleep.link.on_cycle.Call(entity);
			sleep.cycles.done++;
		}
	});

	auto view3 = reg.view<ParalysisComponent, MonsterComponent>();
	view3.each([cycles, &reg](const auto entity, auto& p, auto& stats) {
		if (p.cycles.done == p.cycles.end)
		{
			p.link.on_end.Call(entity);
			reg.remove<ParalysisComponent>(entity);
		}
		else if (!(cycles % p.cycles.each))
		{
			p.link.on_cycle.Call(entity);
			p.cycles.done++;
		}
	});

	auto view4 = reg.view<StatsModComponent, MonsterComponent>();
	view4.each([cycles, &reg](const auto entity, auto& p, auto& stats) {
		if (p.cycles.done == p.cycles.end)
		{
			p.link.on_end.Call(entity);
			reg.remove<StatsModComponent>(entity);
		}
		else
		{
			p.cycles.done++;
		}
	});
}
