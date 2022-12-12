/*
* @file: def/defaults.h
* @author: Arves100
* @date: 10/14/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <cstdint>

static constexpr auto DEFAULT_GAME_NAME = "Open Mystery Toolkit";

using SwitchId = uint16_t;
static constexpr auto SWITCH_MAX = 1000;

using FlagId = uint16_t;
using Flag = int64_t;
static constexpr auto FLAG_MAX = 1000;

using AbilityId = uint16_t;
static constexpr auto ABILITY_MAX = 3;
static constexpr auto ABILITY_MAX_TBL = UINT8_MAX;

using MonsterId = uint16_t;
static constexpr auto MONSTER_MAX_TBL = UINT16_MAX;

using ItemId = uint16_t;
static constexpr auto ITEM_MAX_TBL = UINT16_MAX;

using DungeonId = uint16_t;
static constexpr auto DUNGEON_MAX_TBL = UINT16_MAX;

using MapId = uint16_t;
static constexpr auto MAP_MAX_TBL = UINT16_MAX;

using SpellId = uint16_t;
static constexpr auto SPELL_MAX_TBL = UINT16_MAX;

using AttributeId = uint8_t;
using Attribute = uint8_t;
static constexpr auto ATTRIBUTE_MAX = 2;
static constexpr auto ATTRIBUTE_MAX_TBL = UINT8_MAX;

using CurveId = uint16_t;
static constexpr auto CURVE_MAX_TBL = UINT16_MAX;

using ControlId = uint8_t;

using FormId = uint8_t;
static constexpr auto FORM_MAX_TBL = UINT8_MAX;

using UniqueId = uint16_t;
static constexpr auto UNIQUE_MAX_TBL = UINT16_MAX;
