/*
 * @file: python/classes/monster.h
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <python/inc.h>
#include <python/classes/entity.h>
#include <def/defaults.h>

class PyMonster : public PyEntity
{
  public:
	PyMonster(entt::handle h)
	    : PyEntity(h) {}

	MonsterId GetDbId() const;

	// stats
	int64_t GetHp() const;
	int64_t GetBaseHp() const;
	void SetHp(int64_t hp);

	int64_t GetMp() const;
	int64_t GetBaseMp() const;
	void SetMp(int64_t mp);

	uint16_t GetMeleeAtk() const;
	uint16_t GetBaseMeleeAtk() const;
	void SetMeleeAtk(uint16_t atk);

	uint16_t GetMeleeDef() const;
	uint16_t GetBaseMeleeDef() const;
	void SetMeleeDef(uint16_t def);

	uint16_t GetMagicAtk() const;
	uint16_t GetBaseMagicAtk() const;
	void SetMagicAtk(uint16_t atk);

	uint16_t GetMagicDef() const;
	uint16_t GetBaseMagicDef() const;
	void SetMagicDef(uint16_t def);

	uint8_t GetSpeed() const;
	uint8_t GetBaseSpeed() const;
	void SetSpeed(uint8_t spd);

	uint8_t GetLevel() const;
	uint8_t GetBaseLevel() const;
	void SetLevel(uint8_t lvl);
	void LevelUp();

	const std::string &GetName() const;
	void SetName(std::string name);

	bool LinkOnSpawn(pybind11::function& fnc);
	bool LinkOnDie(pybind11::function &fnc);
	bool LinkOnMove(pybind11::function &fnc);
};
