/*
 * @file: python/classes/monster.cpp
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <python/classes/monster.h>
#include <components/monster.h>

MonsterId PyMonster::GetDbId() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.id;
}

int64_t PyMonster::GetHp() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.stats.hp;
}

int64_t PyMonster::GetMp() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.stats.mp;
}

uint16_t PyMonster::GetMeleeAtk() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.stats.melee_atk;
}

uint16_t PyMonster::GetMeleeDef() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.stats.melee_def;
}

uint16_t PyMonster::GetMagicDef() const
{
	const auto& info = handle_.get<MonsterComponent>();
	return info.stats.magic_def;
}

uint16_t PyMonster::GetMagicAtk() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.stats.magic_atk;
}

uint8_t PyMonster::GetSpeed() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.stats.speed;
}

int64_t PyMonster::GetBaseHp() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.baseStats.hp;
}

int64_t PyMonster::GetBaseMp() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.baseStats.mp;
}

uint16_t PyMonster::GetBaseMeleeAtk() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.baseStats.melee_atk;
}

uint16_t PyMonster::GetBaseMeleeDef() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.baseStats.melee_def;
}

uint16_t PyMonster::GetBaseMagicDef() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.baseStats.magic_def;
}

uint16_t PyMonster::GetBaseMagicAtk() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.baseStats.magic_atk;
}

uint8_t PyMonster::GetBaseSpeed() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.baseStats.speed;
}

uint8_t PyMonster::GetLevel() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.level;
}

uint8_t PyMonster::GetBaseLevel() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.baseLevel;
}

void PyMonster::SetName(std::string name)
{
	auto& info = handle_.get<MonsterComponent>();
	info.name = name;
}

const std::string& PyMonster::GetName() const
{
	const auto &info = handle_.get<MonsterComponent>();
	return info.name;
}

void PyMonster::SetHp(int64_t hp)
{
	auto &info = handle_.get<MonsterComponent>();
	info.stats.hp = hp;
}

void PyMonster::SetMp(int64_t mp)
{
	auto& info = handle_.get<MonsterComponent>();
	info.stats.mp = mp;
}

void PyMonster::SetMeleeAtk(uint16_t atk)
{
	auto& info = handle_.get<MonsterComponent>();
	info.stats.melee_atk = atk;
}

void PyMonster::SetMagicAtk(uint16_t atk)
{
	auto& info = handle_.get<MonsterComponent>();
	info.stats.magic_atk = atk;
}

void PyMonster::SetMeleeDef(uint16_t def)
{
	auto& info = handle_.get<MonsterComponent>();
	info.stats.melee_def = def;
}

void PyMonster::SetMagicDef(uint16_t def)
{
	auto& info = handle_.get<MonsterComponent>();
	info.stats.magic_def = def;
}

void PyMonster::SetSpeed(uint8_t spd)
{
	auto& info = handle_.get<MonsterComponent>();
	info.stats.speed = spd;
}

void PyMonster::SetLevel(uint8_t lvl)
{
	auto& info = handle_.get<MonsterComponent>();
	info.level = lvl;
}

void PyMonster::LevelUp()
{
	// todo
}

bool PyMonster::LinkOnSpawn(pybind11::function &fnc)
{
	auto &info = handle_.get<MonsterComponent>();
	return info.on_spawn.Link(fnc);
}

bool PyMonster::LinkOnDie(pybind11::function &fnc)
{
	auto &info = handle_.get<MonsterComponent>();
	return info.on_die.Link(fnc);
}

bool PyMonster::LinkOnMove(pybind11::function &fnc)
{
	auto &info = handle_.get<MonsterComponent>();
	return info.on_move.Link(fnc);
}
