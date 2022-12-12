/*
 * @file: def/monsterinfo.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <def/stats.h>
#include <def/ability.h>
#include <def/curve.h>
#include <def/defaults.h>

struct MonsterInfo
{
	MonsterId id;
	Stats baseStats;
	uint8_t iq;
	uint8_t tileSize; // 1,2,3,...
	Ability abilities[ABILITY_MAX];
	Curve expCurve;
	uint8_t allowedGenders; // AllowedGenders
	uint8_t recluitRateo; // 0 = not recluitable
	uint8_t genderSpawnPct; // spawn of female% (used when allowedGenders & MALE && allowedGenders & FEMALE)
	Attribute attributes[ATTRIBUTE_MAX];
	uint8_t baseLevel;
};
