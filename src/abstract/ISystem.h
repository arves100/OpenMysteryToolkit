/*
* @file: abstract/ISystem.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <entt/entt.hpp>

class ISystem
{
public:
	virtual void Init(entt::registry &reg) = 0;
	virtual void DeInit(entt::registry &) = 0;
	virtual bool Updatable() const = 0;
    virtual void Update(uint64_t cycles, entt::registry& reg) = 0;
};

class UpdatableSystem : public ISystem
{
  public:
	virtual void Init(entt::registry &) {}
	virtual void DeInit(entt::registry &) {}
	bool Updatable() const { return true; }
	virtual void Update(uint64_t cycles, entt::registry &reg) = 0;
};

class InitOnlySystem : public ISystem
{
  public:
	virtual void Init(entt::registry &reg) = 0;
	virtual void DeInit(entt::registry &reg) = 0;
	bool Updatable() const { return false; }
	void Update(uint64_t, entt::registry &) {}
};
