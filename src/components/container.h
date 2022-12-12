/*
 * @file: components/container.h
 * @author: Arves100
 * @date: 10/15/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <entt/entt.hpp>
#include <nctl/Array.h>

struct ContainerComponent
{
	nctl::Array<entt::entity> entities;
};
