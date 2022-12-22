/*
 * @file: python/classes/map.h
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <string>

#include <python/classes/entity.h>

/*!
* Python implementation of a map
*/
class PyMap : public PyEntity
{
  public:
	/*!
	* Default constructor
	* @param handle Entity handle
	*/
	explicit PyMap(entt::handle handle)
	    : PyEntity(handle) {}

	void Spawn(PyEntity &entity, uint32_t x, uint32_t y);
	void Start();
};

