/*
 * @file: python/classes/map.cpp
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <python/classes/map.h>
#include <components/spawn.h>

void PyMap::Spawn(PyEntity &entity, uint32_t x, uint32_t y)
{
	auto p = SpawnComponent(handle_.get<SpawnComponent>());
	p.spawns.pushBack(SpawnInfo(x, y, entity.GetId()));
	handle_.replace<SpawnComponent>(p);
}

void PyMap::Start()
{
	// todo
}
