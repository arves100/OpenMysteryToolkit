/*
	Open Mystery Toolkit Player
	Copyright 2019 Arves100.
	https://github.com/arves100/OpenMysteryToolkit
*/
#include "StdAfx.h"
#include "Player.h"

#include "Monster.h"

nctl::UniquePtr<CMonster> monster;

void CPlayer::onInit()
{
	ncine::SceneNode &rootNode = ncine::theApplication().rootNode();

	monster = nctl::makeUnique<CMonster>();
	monster->LoadSprite(&rootNode, "monster1", 25, 25);
	monster->AddAnimation(AnimationLayer::IDLE_DOWN, 3.0f, 2, 0, 0);
	monster->AddAnimation(AnimationLayer::MOVE_DOWN, 3.0f, 3, 0, 25);
	monster->SetPosition(200.0f, 200.0f);
}

void CPlayer::onFrameStart()
{
	monster->Update();

	const ncine::KeyboardState &keyState = ncine::theApplication().inputManager().keyboardState();

	if (keyState.isKeyDown(ncine::KeySym::LEFT))
	{

	}
	else if (keyState.isKeyDown(ncine::KeySym::UP))
	{
	
	}
	else if (keyState.isKeyDown(ncine::KeySym::DOWN))
	{
		monster->Move(Directions::DOWN);
	}
	else if (keyState.isKeyDown(ncine::KeySym::RIGHT))
	{
	
	}

}

void CPlayer::onKeyReleased(const ncine::KeyboardEvent &event)
{
		
}

ncine::IAppEventHandler *createAppEventHandler()
{
	return new CPlayer;
}
