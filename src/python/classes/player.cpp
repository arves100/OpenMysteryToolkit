/*
 * @file: python/classes/player.cpp
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <python/classes/player.h>
#include <components/controllable.h>

void PyPlayer::SetControllable(ControlId id)
{
	handle_.emplace<ControllableComponent>(id);
}
