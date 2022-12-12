/*
 * @file: db/mapdb.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <def/mapinfo.h>

#include <nctl/String.h>
#include <nctl/HashMap.h>
#include <optional>

class MapDb final
{
  public:
    MapDb();

    std::optional<MapInfo> Query(MapId id) const;
    bool Init(nctl::String path);

  private:
    nctl::HashMap<MapId, MapInfo> table_;
};
