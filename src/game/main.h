/*
 * @file: game/main.h
 * @author: Arves100
 * @date: 10/15/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <ncine/IAppEventHandler.h>
#include <ncine/IInputEventHandler.h>

#include <game/game.h>

namespace ncine {

class AppConfiguration;

}

class OpenMysteryToolkit final :
    public ncine::IAppEventHandler,
    public ncine::IInputEventHandler
{
  public:
	void onPreInit(ncine::AppConfiguration &config) override;
	void onInit() override;
	void onKeyReleased(const ncine::KeyboardEvent &event) override;
	void onFrameStart() override;
};
