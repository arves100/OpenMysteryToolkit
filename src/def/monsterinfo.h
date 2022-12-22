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

/*!
* Definition of a monster
*/
struct MonsterInfo
{
	/*!
	* ID of the monster
	*/
	MonsterId id;

	/*!
	* Base monster stats
	*/
	Stats baseStats;

	/*!
	* Base monster IQ
	*/
	uint8_t iq;

	/*!
	* Sprite size in tiles of the monster
	*/
	uint8_t tileSize; // 1,2,3,...

	/*!
	* Default abilities of the monster
	*/
	Ability abilities[ABILITY_MAX];

	/*!
	* Curve that defines the EXP of this monster
	*/
	Curve expCurve;

	/*!
	* Flags that contains the allowed genders for this monster
	*/
	uint8_t allowedGenders; // AllowedGenders

	/*!
	* Percent rateo of which the monster is recluitable
	* @note 0 means not recluitable, 100 means always recluatable if conditions are met
	*/
	uint8_t recluitRateo;

	/*!
	* Percent rateo of whenever the monster will be male of female
	* @note 0 means the monster will only be a MALE, 100 means the monster will only be a FEMALE. This value will be ignored if allowedGenders doesn't contain both the genders.
	*/
	uint8_t genderSpawnPct;

	/*!
	* Default attributes of the monster
	*/
	Attribute attributes[ATTRIBUTE_MAX];

	/*!
	* Default level of the monster when initially created
	*/
	uint8_t baseLevel;
};
