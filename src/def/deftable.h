/*
 * @file: def/deftable.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <cstdint>

/*!
* Definition of a simple table header
* @note [MAGIC] [SIZE] [DATA]
*/
struct TableHeader
{
	/*!
	* Magic value
	*/
	uint32_t magic;

	/*!
	* Data count
	*/
	uint32_t size;
};
