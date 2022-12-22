/*
 * @file: python/classes/player.h
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <python/classes/monster.h>

/*!
* Python implementation of the player
*/
class PyPlayer : public PyMonster
{
  public:
	/*!
	* Default constructor
	* @param h Entity handle
	*/
	explicit PyPlayer(entt::handle h)
	    : PyMonster(h) {}

	/*!
	* Sets who can control this player
	* @param id ID of the controller
	*/
	void SetControllable(ControlId id);
};
