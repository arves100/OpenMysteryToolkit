/*
* @file: systems/spawn.cpp
* @author: Arves100
* @date: 10/16/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include <systems/spawn.h>
#include <components/transform.h>
#include <components/spawn.h>

void SpawnSystem::Init(entt::registry &reg)
{
	reg.on_update<SpawnComponent>().connect<&SpawnSystem::OnUpdate>(this);
}

void SpawnSystem::DeInit(entt::registry &reg)
{
	reg.on_update<SpawnComponent>().disconnect<&SpawnSystem::OnUpdate>(this);
}

void SpawnSystem::OnUpdate(entt::registry &reg, entt::entity entity)
{
	// ENTITY MUST BE A MAP!
	auto &data = reg.get<SpawnComponent>(entity);
	auto &transform = reg.get<TransformComponent>(entity);

	for (const auto& s : data.spawns)
	{
		if (!reg.valid(s.e))
		{
			LOGW_X("Unable to spawn non-existant entity %llu", s.e);
			reg.remove<SpawnComponent>(entity);
		}
		else
		{
			auto t = reg.get<TransformComponent>(s.e);

			// todo: transform x/y position based from tiles
			// todo: perform check if x/y are ok
			t.node->setPosition(s.x, s.y);

			transform.node->addChildNode(t.node);

			// todo: add spawn callback
		}
	}

	data.spawns.clear();
}
