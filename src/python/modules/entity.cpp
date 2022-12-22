/*
 * @file: python/modules/entity.cpp
 * @author: Arves100
 * @date: 10/15/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <python/modules.h>
#include <python/classes/player.h>
#include <python/classes/map.h>
#include <game/game.h>

#include <entt/entt.hpp>

/*!
* Creates a new player
* @param id ID of the monster to use for the player
* @param form ID of the form for the player
* @param unique ID of the unique type for the player to use
* @return The newly created player entity
*/
static auto createPlayer(MonsterId id, FormId form, UniqueId unique)
{
	auto e = theGame().CreatePlayer(id, form, unique);
	if (e == entt::null)
		throw std::runtime_error("Specified player does not exist");

	return PyPlayer(theGame().GetHandleOf(e));
}

/*!
* Creates a new monster
* @param id ID of the monster to use for the monster
* @param form ID of the form for the monster
* @param unique ID of the unique type for the monster to use
* @return The newly created monster entity
*/
static auto createMonster(MonsterId id, FormId form, UniqueId unique)
{
	auto e = theGame().CreateMonster(id, form, unique);
	if (e == entt::null)
		throw std::runtime_error("Specified player does not exist");

	return PyMonster(theGame().GetHandleOf(e));
}

/*!
* Creates a new map
* @param id ID of the map
* @return The newly created map entity
*/
static auto createMap(MapId id)
{
	auto e = theGame().CreateMap(id);
	if (e == entt::null)
		throw std::runtime_error("Specified map does not exist");

	return PyMap(theGame().GetHandleOf(e));
}

MOD_FUNC(entity)
{
	pybind11::class_<PyEntity>(m, "Entity")
	    .def_property("tag", &PyEntity::GetTag, &PyEntity::SetTag)
	    .def_property_readonly("shown", &PyEntity::IsShow)
	    .def("show", &PyEntity::Show)
	    .def("hide", &PyEntity::Hide)
		;

	pybind11::class_<PyMonster, PyEntity>(m, "Monster")
	    .def_property("hp", &PyMonster::GetHp, &PyMonster::SetHp)
	    .def_property("mp", &PyMonster::GetMp, &PyMonster::SetMp)
	    .def_property("meleeAtk", &PyMonster::GetMeleeAtk, &PyMonster::SetMeleeAtk)
	    .def_property("meleeDef", &PyMonster::GetMeleeDef, &PyMonster::SetMeleeDef)
	    .def_property("magicAtk", &PyMonster::GetMagicAtk, &PyMonster::SetMagicAtk)
	    .def_property("magicDef", &PyMonster::GetMagicDef, &PyMonster::SetMagicDef)
	    .def_property("speed", &PyMonster::GetSpeed, &PyMonster::SetSpeed)
	    .def_property("level", &PyMonster::GetSpeed, &PyMonster::SetSpeed)
	    .def_property("name", &PyMonster::GetName, &PyMonster::SetName)
	    .def_property_readonly("baseHp", &PyMonster::GetBaseHp)
	    .def_property_readonly("baseMp", &PyMonster::GetBaseMp)
	    .def_property_readonly("baseMeleeAtk", &PyMonster::GetBaseMeleeAtk)
	    .def_property_readonly("baseMeleeDef", &PyMonster::GetBaseMagicDef)
	    .def_property_readonly("baseMagicAtk", &PyMonster::GetBaseMagicAtk)
	    .def_property_readonly("baseMagicDef", &PyMonster::GetBaseMagicDef)
	    .def_property_readonly("baseSpeed", &PyMonster::GetBaseSpeed)
	    .def_property_readonly("baseLevel", &PyMonster::GetBaseLevel)
	    .def("levelup", &PyMonster::LevelUp)
	    .def("linkOnDie", &PyMonster::LinkOnDie)
	    .def("linkOnSpawn", &PyMonster::LinkOnSpawn)
	    .def("linkOnMove", &PyMonster::LinkOnMove)
		;

	pybind11::class_<PyPlayer, PyMonster>(m, "Player")
	    .def("setControllableBy", &PyPlayer::SetControllable)
		;

	pybind11::class_<PyMap, PyEntity>(m, "Map")
	    .def("spawn", &PyMap::Spawn)
	    .def("start", &PyMap::Start)
		;

	m.def("createPlayer", createPlayer);
	m.def("createMap", createMap);
	m.def("createMonster", createMonster);
}
