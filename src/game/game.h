/*
 * @file: game/game.h
 * @author: Arves100
 * @date: 10/15/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <db/gameinfo.h>
#include <game/ecs.h>
#include <game/vari.h>
#include <game/python.h>
#include <game/db.h>

/*
 * @class Game Main game
 * Concepts:
 *	1. Once all characters have updated a cycle ticks (different from a render cycle)
 *	2. There must an ncine components for entities (Transformable)
 *	3. Game must be shared for having availability on the Python API
 * @note very big blobbed container
 */
class Game final : public ECS, public Vari
{
  public:
	explicit Game();

	/*!
	* Default deconstructor
	*/
	~Game();

	/*!
	 * Creates a new game instance and begin it's loading phase
	 * @param name Name of the game
	 */
	void Load(nctl::String name);

	/*!
	* Checks if the game has been loaded
	* @return true in case the game has been successfully loaded, oterwise false.
	*/
	bool IsLoaded() const { return loaded_; }

	/*!
	* Updates the game components
	* @param delta Delta time
	*/
	void Update(float delta);

	/*!
	* Gets the current cycles of the game
	* @return Total cycles
	*/
	uint64_t GetCycles() const { return cycles_; }

	/*!
	* Advances to the next game cycle
	*/
	void Advance();




  private:
	nctl::String name_;
	GameInfo info_;
	bool loaded_;

	uint64_t cycles_;

	Db db_;
	Python python_;
};

/*!
* Global instance of the game
* @return A instance of the game
*/
extern Game &theGame();
