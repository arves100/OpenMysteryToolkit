/*
 * @file: def/deftable.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <cstdint>

/*
    [MAGIC] [SIZE] [DATA]
*/
struct TableHeader
{
	uint32_t magic;
	uint32_t size;
};
