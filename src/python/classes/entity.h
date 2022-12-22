/*
 * @file: python/classes/entity.h
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <entt/entt.hpp>

/*!
* Python implementation of an entity
*/
class PyEntity
{
  public:
	/*!
	* Default constructor
	* @param h Entity handle
	*/
	explicit PyEntity(entt::handle h)
	    : handle_(h) {}

	/*!
	* Gets the ID of this entity
	*/
	entt::entity GetId() const { return handle_.entity(); }

	// tag (we suppose name will never be changed by the C++ code)

	/*!
	* Gets the current tag
	* @return Tag
	*/
	const std::string &GetTag() const { return tag_; }

	/*!
	* Sets a tag for this entity
	* @param tag Tag to set
	*/
	void SetTag(std::string tag);

	bool IsShow();
	void Show();
	void Hide();

  protected:
	/*!
	* Entity handle
	*/
	entt::handle handle_;

	/*!
	* Tag cache
	*/
	std::string tag_;
};
