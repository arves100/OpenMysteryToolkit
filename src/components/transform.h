/*
* @file: components/transform.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <cstdint>

#include <ncine/SceneNode.h>
#include <nctl/SharedPtr.h>

// entity
struct TransformComponent
{
	ncine::SceneNode* node;
};
