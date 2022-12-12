/*
* @file: systems/motion.cpp
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include <systems/motion.h>
#include <components/motion.h>
#include <components/transform.h>

void MotionSystem::Update(uint64_t cycles, entt::registry& reg)
{
	auto view = reg.view<MotionComponent, TransformComponent>();

	view.each([&reg](const auto entity, auto& motion, auto& transform) {
		// todo: get map parent and perform stuff with it...
		auto p = transform.node->position();

		switch (motion.direction)
		{
		case Direction::Down:
			p.y -= motion.velocity;
			break;
		case Direction::DownLeft:
			p.y -= motion.velocity;
			p.x += motion.velocity;
			break;
		case Direction::DownRight:
			p.y -= motion.velocity;
			p.x -= motion.velocity;
			break;
		case Direction::Up:
			p.y += motion.velocity;
			break;
		case Direction::UpLeft:
			p.y += motion.velocity;
			p.x += motion.velocity;
			break;
		case Direction::UpRight:
			p.y += motion.velocity;
			p.x -= motion.velocity;
			break;
		case Direction::Left:
			p.x -= motion.velocity;
			break;
		case Direction::Right:
			p.x += motion.velocity;
			break;
		}

		// todo: transform x/y position based from tiles
		// todo: perform check if x/y are ok
		transform.node->setPosition(p);
		motion.on_change.Call(entity, p.x, p.y);
		reg.remove<MotionComponent>(entity);
	});
}
