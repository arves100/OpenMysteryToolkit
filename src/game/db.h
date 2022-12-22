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

/*!
* This class contains all the databases loaded by the game
*/
class Db final
{
  public:
	/*!
	* Default constructor
	*/
	explicit Db()
	    : ability_(), monster_(ability_) {}

	/*!
	* Loads the databases
	* @param gamePath Directory of the game
	*/
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

	/*!
	* Gets the entity database
	* @return Reference to the entity database
	*/
	const MonsterDb &GetEntities() const { return monster_; }

	/*!
	* Gets the ability database
	* @return Reference to the ability database
	*/
	const AbilityDb &GetAbilities() const { return ability_; }

  private:
	/*!
	* Ability database
	*/
	AbilityDb ability_;

	/*!
	* Monster database
	*/
	MonsterDb monster_;
};
