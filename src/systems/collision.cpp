/*
* @file: systems/collision.cpp
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include <systems/collision.h>
#include <components/contact.h>

void CollisionSystem::Update(uint64_t cycles, entt::registry& reg)
{
	// TODO!

	auto view = reg.view<ContactComponent>();

	view.each([&reg](const auto entity, const auto& contact) {
		reg.remove<ContactComponent>(entity);
	});
}
