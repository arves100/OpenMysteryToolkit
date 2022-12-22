/*
 * @file: game/vari.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <def/defaults.h>

#include <nctl/Array.h>

/*!
* This class manages all the variables that a game developer can use, in a similar
* style of RPG Maker it contains switches (booleans) and flags (numbers)
*/
class Vari
{
  public:
	/*!
	* Default constructor
	*/
	explicit Vari()
	    : switches_(SWITCH_MAX, nctl::ArrayMode::FIXED_CAPACITY),
	      flags_(FLAG_MAX, nctl::ArrayMode::FIXED_CAPACITY)
	{}

	/*!
	 * Gets an user defined switch
	 * @param id ID of the switch
	 * @return The switch
	 * @note Default value is false
	 */
	bool GetSwitch(SwitchId id) const
	{
		if (id > SWITCH_MAX)
			return false;

		return switches_[id];
	}

	/*!
	 * Gets an user defined flag
	 * @param id ID of the flag
	 * @return The flag
	 * @note Default value is 0
	 */
	Flag GetFlag(FlagId id) const
	{
		if (id > FLAG_MAX)
			return false;

		return flags_[id];
	}

	/*!
	 * Sets an user defined switch
	 * @param id ID of the switch
	 * @param val Switch value
	 */
	void SetSwitch(SwitchId id, bool val)
	{
		if (id < SWITCH_MAX)
			switches_[id] = val;
	}

	/*!
	 * Sets an user defined switch
	 * @param id ID of the switch
	 * @param val Switch value
	 */
	void SetFlag(FlagId id, Flag val)
	{
		if (id < FLAG_MAX)
			flags_[id] = val;
	}

  private:
	/*!
	* Flags container
	*/
	nctl::Array<Flag> flags_;

	/*!
	* Switches container
	*/
	nctl::Array<bool> switches_;
};
