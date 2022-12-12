/*
 * @file: def/ability.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <python/link.h>

struct Ability
{
	// def on_cycle(entity: Entity, map: Entity)
	PythonLink on_cycle;

	// def on_atk(attacker: Entity, defender: Entity, move: Move, map: Entity)
	PythonLink on_atk;

	// def on_def(attacker: Entity, defender: Entity, move: Move, map: Entity)
	PythonLink on_def;

	// def on_kill(killer: Entity, victim: Entity, move: Move, map: Entity)
	PythonLink on_kill;

	// def on_die(killer: Entity, victim: Entity, move: Move, map: Entity)
	PythonLink on_die;
};
