/*
 * @file: abstract/IDb.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <nctl/String.h>
#include <optional>

class IDb
{
  public:
	virtual std::optional<EntityInfo> Query(EntityId id) const = 0;
	virtual bool Init(nctl::String path) = 0;

  protected:
	IDb() = default;
};
