/*
* @file: def/item.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <cstdint>
#include <string>

#include <def/gender.h>

struct Item
{
    uint64_t id;
    std::string name;
    bool compressable;
};
