/*
 * @file: db/monsterdb.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <def/monsterinfo.h>
#include <db/abilitydb.h>

#include <nctl/String.h>
#include <nctl/HashMap.h>
#include <optional>

class MonsterDb final
{
  public:
	MonsterDb(AbilityDb &adb);

	std::optional<MonsterInfo> Query(MonsterId id) const;
	bool Init(nctl::String path);

  private:
	nctl::HashMap<MonsterId, MonsterInfo> table_;
	AbilityDb &abi_;
};
