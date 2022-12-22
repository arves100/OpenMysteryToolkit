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

/*!
* This class manages the Entity-Component-System
* @note Used EnTT
*/
class ECS
{
  public:
	/*!
	* Default constructor
	* @param db Database reference
	*/
	explicit ECS(const Db &db)
	    : db_(db) {}

	/*!
	* Adds a component to an entity
	* @param entity Entity reference
	* @param args Component data
	*/
	template <typename T, typename... Args>
	void Attach(entt::entity entity, Args... args)
	{
		reg_.emplace<T>(entity, args...);
	}

	/*!
	* Modifies a coponent of an entity
	* @param entity Entity reference
	* @param args Component data
	*/
	template <typename T, typename... Args>
	void Patch(entt::entity entity, Args... args)
	{
		reg_.patch<T>(entity, args...);
	}

	/*!
	* Removes a component from an entity
	* @param entity Entity reference
	*/
	template <typename T>
	void Deattach(entt::entity entity)
	{
		reg_.remove<T>(entity);
	}

	/*!
	* Creates a reference of the entity
	* @param entity Entity reference
	* @return Handle of the entity
	*/
	entt::handle GetHandleOf(entt::entity entity)
	{
		return entt::handle(reg_, entity);
	}

	/*!
	* Creates a new map
	* @param id ID of the map
	* @return The newly created map entity
	*/
	entt::entity CreateMap(MapId id);

	/*!
	* Creates a new player
	* @param id ID of the monster to use for the player
	* @param form ID of the form for the player
	* @param unique ID of the unique type for the player to use
	* @return The newly created player entity
	*/
	entt::entity CreatePlayer(MonsterId id, FormId form, UniqueId unique);

	/*!
	* Creates a new monster
	* @param id ID of the monster to use for the monster
	* @param form ID of the form for the monster
	* @param unique ID of the unique type for the monster to use
	* @return The newly created monster entity
	*/
	entt::entity CreateMonster(MonsterId id, FormId form, UniqueId unique);

	/*!
	* Adds a new system to the ECS registry
	*/
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
	/*!
	* Updates the updatable systems contained inside the ECS registry
	* @param cycles Current cycle
	*/
	void UpdateSystems(uint64_t cycles)
	{
		for (auto& sys : updatable_)
		{
			auto sp = sys.lock();
			if (sp)
				sp->Update(cycles, reg_);
		}
	}

	/*!
	* Registry component
	*/
	entt::registry reg_;

	/*!
	* Container of all ECS systems
	*/
	nctl::Array<std::shared_ptr<ISystem>> systems_;

	/*!
	* Container of all updatable ECS systems (weak pointers)
	*/
	nctl::Array<std::weak_ptr<ISystem>> updatable_;

	/*!
	* Database reference
	*/
	const Db &db_;
};
