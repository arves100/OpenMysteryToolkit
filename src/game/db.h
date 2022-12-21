/*
 * @file: game/db.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <db/monsterdb.h>
#include <db/abilitydb.h>

#include <ncine/FileSystem.h>
#include <nctl/String.h>

class Db final
{
  public:
	Db()
	    : ability_(), monster_(ability_) {}

	bool Load(nctl::String gamePath)
	{
		nctl::String db = ncine::fs::joinPath(gamePath, "db");

		if (!ability_.Init(ncine::fs::joinPath(db, "abilities.db")))
		{
			LOGE("Unable to load abilities database!");
			return false;
		}

		if (!monster_.Init(ncine::fs::joinPath(db, "entities.db")))
		{
			LOGE("Unable to load monster database!");
			return false;
		}

		return true;
	}

	const MonsterDb &GetEntities() const { return monster_; }
	const AbilityDb &GetAbilities() const { return ability_; }

  private:
	AbilityDb ability_;
	MonsterDb monster_;
};
