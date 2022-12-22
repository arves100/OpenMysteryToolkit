/*
* @file: def/item.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <cstdint>
#include <string>

#include <def/defaults.h>

/*!
* Definition of an item
*/
struct Item
{
	/*!
	* Item ID
	*/
    ItemId id;

	/*!
	* Item name
	*/
    std::string name;

	/*!
	* If the item is stackable
	*/
	bool stackable;
};
