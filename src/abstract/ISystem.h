/*
* @file: abstract/ISystem.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <entt/entt.hpp>

/*!
* Interface for a system
*/
class ISystem
{
public:
	/*!
	* Called when the system is initialized
	* @param reg Entity registry
	*/
	virtual void Init(entt::registry &reg) = 0;

	/*!
	* Called when the system is destroyed
	* @param reg Entity registry
	*/
	virtual void DeInit(entt::registry &reg) = 0;

	/*!
	* Checks if the system has to be updated
	* @return true if the system should be updated with the cycles
	*/
	virtual bool Updatable() const = 0;

	/*!
	* Updates the system
	* @param cycles Current game cycles
	* @param reg Entity registry
	*/
    virtual void Update(uint64_t cycles, entt::registry &reg) = 0;
};

/*!
* Implementation of an abstract system that can be updated
*/
class UpdatableSystem : public ISystem
{
  public:
	/*!
	* Called when the system is initialized
	*/
	virtual void Init(entt::registry &) {}

	/*!
	 * Called when the system is destroyed
	 */
	virtual void DeInit(entt::registry &) {}

	/*!
	 * Checks if the system has to be updated
	 * @return true if the system should be updated with the cycles
	 */
	bool Updatable() const { return true; }

	/*!
	* Updates the system
	* @param cycles Current game cycles
	* @param reg Entity registry
	*/
	virtual void Update(uint64_t cycles, entt::registry &reg) = 0;
};

/*!
* Implementation of an abstract system that cannot be updated
*/
class InitOnlySystem : public ISystem
{
  public:
	/*!
	 * Called when the system is initialized
	 * @param reg Entity registry
	 */
	virtual void Init(entt::registry &reg) = 0;

	/*!
	 * Called when the system is destroyed
	 * @param reg Entity registry
	 */
	virtual void DeInit(entt::registry &reg) = 0;

	/*!
	 * Checks if the system has to be updated
	 * @return true if the system should be updated with the cycles
	 */
	bool Updatable() const { return false; }

	/*!
	* Updates the system
	* @note This function does nothing as this system cannot be updated
	*/
	void Update(uint64_t, entt::registry &) {}
};
