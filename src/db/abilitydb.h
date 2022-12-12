/*
 * @file: db/abilitydb.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <def/ability.h>
#include <def/defaults.h>

#include <nctl/HashMap.h>

class AbilityDb final
{
  public:
	AbilityDb();

	std::optional<Ability> Query(AbilityId id) const;
	bool Init(nctl::String path);

  protected:
	nctl::HashMap<AbilityId, Ability> abilities_;
};
