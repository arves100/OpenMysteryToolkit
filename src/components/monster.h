/*
 * @file: components/monster.h
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <def/monsterinfo.h>

#include <string>

struct MonsterComponent : public MonsterInfo
{
	std::string name;
	Stats stats;
	uint8_t level;
	bool alive;

	// def spawn(entity: Monster, map: Map) -> None
	PythonLink on_spawn;

	// def move(entity: Monster, x: int, y: int) -> None
	PythonLink on_move;

    // def dead(entity: Monster, cause: CauseId, attacker: Monster) -> None
	//  attacker may be null if the death is caused by a status or an external event
	PythonLink on_die;

	MonsterComponent(MonsterInfo info)
	    : MonsterInfo(info)
	{
		name = "";
		stats = info.baseStats;
		level = info.baseLevel;
		alive = true;
	}
};
