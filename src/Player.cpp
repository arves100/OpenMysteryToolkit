/*+===================================================================
	File:		Player.cpp

	Summary:	nCine application main class.
				Used as an entry point for this nCine based application.

	This file is part of OpenMysteryToolkit. Copyright © 2019 Arves100.
	For more information, visit: https://www.github.com/arves100/OpenMysteryToolkit
===================================================================+*/

#include "StdAfx.h"
#include "Player.h"
#include "Monster.h"
#include "version.h"

// NOTE: All the methods and global variables are used for testing and they are subject to severe changes.

nctl::UniquePtr<CMonster> g_qpMonster;

void CPlayer::onPreInit(ncine::AppConfiguration& cConfig)
{
#ifdef __ANDROID__
	cConfig.dataPath() = "asset::";
#elif defined(__EMSCRIPTEN__)
	cConfig.dataPath() = "/";
#else
	#ifdef PACKAGE_DEFAULT_DATA_DIR
		cConfig.dataPath() = PACKAGE_DEFAULT_DATA_DIR;
	#else
		cConfig.dataPath() = "data/";
	#endif
#endif

	//cConfig.windowIconFilename = "omticon.png"; // TODO!
	cConfig.windowTitle = nctl::String("OMTp ver ") + VersionStrings::Version + " [" + VersionStrings::CompilationDate + "] " + VersionStrings::CompilationTime;
}

void CPlayer::onInit()
{
	ncine::SceneNode& cRootNode = ncine::theApplication().rootNode();

	// Test CMonster API
	g_qpMonster = nctl::makeUnique<CMonster>();
	g_qpMonster->LoadSprite(&cRootNode, "monster1", 25, 25);
	g_qpMonster->AddAnimation(AnimationLayers::Idle_Down, 3.0f, 2, 0, 0);
	g_qpMonster->AddAnimation(AnimationLayers::Move_Down, 3.0f, 3, 0, 25);
	g_qpMonster->SetPosition(200.0f, 200.0f);
	g_qpMonster->ChangeAnimation(AnimationLayers::Idle_Down); // Set the default animation, mandatory
}

void CPlayer::onFrameStart()
{
	g_qpMonster->Update();

	const ncine::KeyboardState& cKeyState = ncine::theApplication().inputManager().keyboardState();

	if (cKeyState.isKeyDown(ncine::KeySym::LEFT))
	{

	}
	else if (cKeyState.isKeyDown(ncine::KeySym::UP))
	{
	
	}
	else if (cKeyState.isKeyDown(ncine::KeySym::DOWN))
	{
		g_qpMonster->Move(Directions::Down);
	}
	else if (cKeyState.isKeyDown(ncine::KeySym::RIGHT))
	{
	
	}

}

void CPlayer::onKeyReleased(const ncine::KeyboardEvent& cEvent)
{
		
}

void CPlayer::onShutdown()
{
	g_qpMonster.reset(nullptr);
}

/*F===================================================================
	Function:	createAppEventHandler

	Summary:	Creates the application event handler that will be fired by the nCine in certain situations

	Args:		None

	Returns:	ncine::IAppEventHandler*
					A pointer to the nCine application class.
===================================================================F*/
ncine::IAppEventHandler *createAppEventHandler()
{
	return new CPlayer();
}
