/*
* @file: def/gender.h
* @author: Arves100
* @date: 10/14/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

/*!
* All types of genders
*/
enum class Gender
{
    Male,
    Female,
    Unknown,
};

namespace AllowedGenders {
	/*!
	* Bitwise flags for the allowed genders
	*/
	enum _
	{
		Unknown = 0,
		Male = 1 << 0,
		Female = 1 << 1,
	};
}
