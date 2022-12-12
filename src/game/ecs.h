/*
 * @file: game/ecs.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <def/defaults.h>
#include <abstract/ISystem.h>

#include <nctl/Array.h>
#include <entt/entt.hpp>

#include <game/db.h>

class ECS
{
  public:
	ECS(const Db &db)
	    : db_(db) {}

	template <typename T, typename... Args>
	void Attach(entt::entity entity, Args... args)
	{
		reg_.emplace<T>(entity, args...);
	}

	template <typename T, typename... Args>
	void Patch(entt::entity entity, Args... args)
	{
		reg_.patch<T>(entity, args...);
	}

	template <typename T>
	void Deattach(entt::entity entity)
	{
		reg_.remove<T>(entity);
	}

	entt::handle GetHandleOf(entt::entity entity)
	{
		return entt::handle(reg_, entity);
	}

	entt::entity CreateMap(MapId id);
	entt::entity CreatePlayer(MonsterId id, FormId form, UniqueId unique);
	entt::entity CreateMonster(MonsterId id, FormId form, UniqueId unique);

	template <typename T>
	void AddSystem()
	{
		auto sys = std::make_shared<T>();
		auto down = std::dynamic_pointer_cast<ISystem>(sys);
		systems_.pushBack(down);
		if (down->Updatable())
		{
			updatable_.pushBack(down);
		}
	}

  protected:
	void UpdateSystems(uint64_t cycles)
	{
		for (auto& sys : updatable_)
		{
			auto sp = sys.lock();
			if (sp)
				sp->Update(cycles, reg_);
		}
	}

	entt::registry reg_;

	nctl::Array<std::shared_ptr<ISystem>> systems_;
	nctl::Array<std::weak_ptr<ISystem>> updatable_;

	const Db &db_;
};
