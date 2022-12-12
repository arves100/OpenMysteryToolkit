/*
 * @file: python/classes/entity.h
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <entt/entt.hpp>

class PyEntity
{
  public:
	PyEntity(entt::handle h)
	    : handle_(h) {}

	entt::entity GetId() const { return handle_.entity(); }

	// tag (we suppose name will never be changed by the C++ code)
	const std::string &GetTag() const { return tag_; }
	void SetTag(std::string tag);

	bool IsShow();
	void Show();
	void Hide();

  protected:
	entt::handle handle_;

	// cache
	std::string tag_;
};
