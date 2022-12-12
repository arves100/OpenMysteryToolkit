/*
 * @file: python/classes/entity.cpp
 * @author: Arves100
 * @date: 10/17/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <python/classes/entity.h>
#include <components/tag.h>

void PyEntity::SetTag(std::string tag)
{
	tag_ = tag;
	handle_.replace<TagComponent>(tag);
}

bool PyEntity::IsShow()
{
	return true;
}

void PyEntity::Show()
{

}

void PyEntity::Hide()
{

}
