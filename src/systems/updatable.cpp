/*
* @file: systems/updatable.cpp
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include <systems/updatable.h>
#include <components/updatable.h>

void UpdateSystem::Update(uint64_t cycles, entt::registry& reg)
{
	auto view = reg.view<UpdatableComponent>();

	view.each([](const auto entity, auto& update)	
	{
		update.link.Call(entity);
	});
}
