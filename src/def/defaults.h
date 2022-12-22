/*
* @file: def/defaults.h
* @author: Arves100
* @date: 10/14/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <cstdint>

/*!
* @typedef DEFAULT_GAME_NAME
* Default game name
*/
static constexpr auto DEFAULT_GAME_NAME = "Open Mystery Toolkit";

/*!
* @typedef SwitchId
* Type that defines the ID of switchs
*/
using SwitchId = uint16_t;

/*!
* @typedef SWITCH_MAX
* Maximum switches allowed
*/
static constexpr auto SWITCH_MAX = 1000;

/*!
* @typedef FlagId
* Type that defines the ID of flags
*/
using FlagId = uint16_t;

/*!
* @typedef Flag
* Type that defines the value of a flag
*/
using Flag = int64_t;

/*!
* @typedef FLAG_MAX
* Maximum flags allowed
*/
static constexpr auto FLAG_MAX = 1000;

/*!
* @typedef AbilityId
* Type that defines the ID of the abilities
*/
using AbilityId = uint16_t;

/*!
* @typedef ABILITY_MAX
* Maximum abilities allowed
*/
static constexpr auto ABILITY_MAX = 3;

/*!
 * @typdef ABILITY_MAX_TBL
 * Maximum number of abilities that the game can contain
 */
static constexpr auto ABILITY_MAX_TBL = UINT8_MAX;

/*!
* @typedef MonsterId
* Type that defines the ID of the monsters
*/
using MonsterId = uint16_t;

/*!
 * @typdef MONSTER_MAX_TBL
 * Maximum number of monsters that the game can contain
 */
static constexpr auto MONSTER_MAX_TBL = UINT16_MAX;

/*!
* @typedef ItemId
* Type that defines the ID of the items
*/
using ItemId = uint16_t;

/*!
 * @typdef ITEM_MAX_TBL
 * Maximum number of items that the game can contain
 */
static constexpr auto ITEM_MAX_TBL = UINT16_MAX;

/*!
* @typedef DungeonId
* Type that defines the ID of the dungeons
*/
using DungeonId = uint16_t;

/*!
 * @typdef DUNGEON_MAX_TBL
 * Maximum number of dungeons that the game can contain
 */
static constexpr auto DUNGEON_MAX_TBL = UINT16_MAX;

/*!
* @typedef MapId
* Type that defines the ID of the maps
*/
using MapId = uint16_t;

/*!
 * @typdef MAP_MAX_TBL
 * Maximum number of maps that the game can contain
 */
static constexpr auto MAP_MAX_TBL = UINT16_MAX;

/*!
 * @typedef SpellId
 * Type that defines the ID of the spells
 */
using SpellId = uint16_t;

/*!
* @typdef SPELL_MAX_TBL
* Maximum number of spells that the game can contain
*/
static constexpr auto SPELL_MAX_TBL = UINT16_MAX;

/*!
 * @typedef AttributeId
 * Type that defines the ID of the attributes
 */
using AttributeId = uint8_t;

/*!
 * @typedef Attribute
 * Type that defines the value of an attribute
 */
using Attribute = uint8_t;

/*!
* @typedef ATTRIBUTE_MAX
* Maximum numbers of attributes allowed
*/
static constexpr auto ATTRIBUTE_MAX = 2;

/*!
 * @typdef ATTRIBUTE_MAX_TBL
 * Maximum number of attributes that the game can contain
 */
static constexpr auto ATTRIBUTE_MAX_TBL = UINT8_MAX;

/*!
 * @typedef CurveId
 * Type that defines the ID of the curves
 */
using CurveId = uint16_t;

/*!
 * @typdef CURVE_MAX_TBL
 * Maximum number of curves that the game can contain
 */
static constexpr auto CURVE_MAX_TBL = UINT16_MAX;

/*!
 * @typedef ControlId
 * Type that defines the ID of the controls
 */
using ControlId = uint8_t;

/*!
 * @typedef FormId
 * Type that defines the ID of the forms
 */
using FormId = uint8_t;

/*!
 * @typdef FORM_MAX_TBL
 * Maximum number of forms that the game can contain
 */
static constexpr auto FORM_MAX_TBL = UINT8_MAX;

/*!
 * @typedef UniqueId
 * Type that defines the ID of the unique forms
 */
using UniqueId = uint16_t;

/*!
 * @typdef UNIQUE_MAX_TBL
 * Maximum number of unique forms that the game can contain
 */
static constexpr auto UNIQUE_MAX_TBL = UINT16_MAX;
