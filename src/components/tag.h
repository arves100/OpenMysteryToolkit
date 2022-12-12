/*
* @file: components/tag.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <string>

struct TagComponent
{
	std::string tag;

	TagComponent(std::string tag)
	    : tag(tag) {}
};
