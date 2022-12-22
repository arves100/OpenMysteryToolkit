/*
* @file: def/cycleinfo.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <cstdint>

/*!
* Definition of the type of informations that something has to do inside a cycle
*/
struct CycleInfo
{
	uint64_t done;
	//uint64_t start;
	uint64_t end;
	uint64_t each;
};
