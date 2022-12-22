/*
 * @file: game/main.h
 * @author: Arves100
 * @date: 10/15/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <ncine/IAppEventHandler.h>
#include <ncine/IInputEventHandler.h>

#include <nctl/String.h>

#include <game/game.h>

namespace ncine {

class AppConfiguration;

}

/*!
* The actual nCine videogame
*/
class OpenMysteryToolkit final :
    public ncine::IAppEventHandler,
    public ncine::IInputEventHandler
{
  public:
	/// Called once before initialization to setup the application
	/*! \warning At this stage it is only safe to modify the `config` object.
	 *  No other engine API calls should be made. */
	void onPreInit(ncine::AppConfiguration &config) override;

	/// Called once on application initialization
	void onInit() override;

	/// Callback function called every time a key is released
	void onKeyReleased(const ncine::KeyboardEvent &event) override;

	/// Called at the start of each frame
	void onFrameStart() override;

  private:
	/*!
	* Game name
	*/
	nctl::String game_;

	/*!
	* Physics accumulator
	*/
	float accumulator_;
};
