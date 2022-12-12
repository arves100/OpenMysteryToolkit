/*
 * @file: python/classes/player.h
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <python/classes/monster.h>

class PyPlayer : public PyMonster
{
  public:
	PyPlayer(entt::handle h)
	    : PyMonster(h) {}

	void SetControllable(ControlId id);
};
