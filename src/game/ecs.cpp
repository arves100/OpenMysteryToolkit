/*
 * @file: game/ecs.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <game/ecs.h>
#include <components/transform.h>
#include <components/monster.h>
#include <components/spawn.h>
#include <ncine/Application.h>

entt::entity ECS::CreateMap(MapId id)
{
	auto entity = reg_.create();
	if (entity != entt::null)
	{
		auto& root = ncine::theApplication().rootNode();
		auto map = new ncine::SceneNode(&root);

		reg_.emplace<TransformComponent>(entity, map);
		reg_.emplace<SpawnComponent>(entity);
	}

	return entity;
}

entt::entity ECS::CreatePlayer(MonsterId id, FormId form, UniqueId uniq)
{
	auto entity = CreateMonster(id, form, uniq);
	if (entity != entt::null)
	{

	}

	return entity;
}

entt::entity ECS::CreateMonster(MonsterId id, FormId form, UniqueId uniq)
{
	auto o = db_.GetEntities().Query(id);
	if (!o.has_value())
		return entt::null;

	auto entity = reg_.create();
	auto node = new ncine::SceneNode();
	reg_.emplace<TransformComponent>(entity, node);
	reg_.emplace<MonsterComponent>(entity, o.value());

	return entity;
}
