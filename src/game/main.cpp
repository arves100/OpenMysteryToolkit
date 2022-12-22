/*
 * @file: game/main.cpp
 * @author: Arves100
 * @date: 10/15/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <game/main.h>
#include <game/game.h>

#include <ncine/Application.h>
#include <ncine/AppConfiguration.h>
#include <ncine/FileSystem.h>
#include <nctl/String.h>
#include <nctl/SharedPtr.h>

#include <version.h>

nctl::SharedPtr<Game> g_game = nctl::SharedPtr<Game>();

Game &theGame()
{
	return *g_game;
}

/*!
* This function instructs the nCine to create the game application
* @return An unique pointer of the game class
*/
nctl::UniquePtr<ncine::IAppEventHandler> createAppEventHandler()
{
	return nctl::makeUnique<OpenMysteryToolkit>();
}

void OpenMysteryToolkit::onPreInit(ncine::AppConfiguration &config)
{
#if defined(__ANDROID__)
	config.dataPath() = "asset::";
#elif defined(__EMSCRIPTEN__)
	config.dataPath() = "/";
#else
	#ifdef NCPROJECT_DEFAULT_DATA_DIR
	config.dataPath() = NCPROJECT_DEFAULT_DATA_DIR;
	#else
	config.dataPath() = "data/";
	#endif
#endif

	config.resizable = true;

#ifdef OPENMYSTERYTOOLKIT_DEBUG
	config.withDebugOverlay = true;
	config.fileLogLevel = ncine::ILogger::LogLevel::DEBUG;
	config.consoleLogLevel = ncine::ILogger::LogLevel::DEBUG;
#else
	config.consoleLogLevel = ncine::ILogger::LogLevel::ERROR;
#endif

	// default name
	nctl::String str = "OMT ver ";
	str += VersionStrings::Version;
	str += " [";
	str += VersionStrings::CompilationDate;
	str += "] ";
	str += VersionStrings::CompilationTime;

	config.windowTitle = str;
	config.windowIconFilename = "icon48.png";

	if (config.argc() < 2)
	{
		// SHOW MESSAGE BOX INVALID PARAMETERS
		ncine::theApplication().quit();
		return;
	}

	game_ = config.argv(1);
}

void OpenMysteryToolkit::onKeyReleased(const ncine::KeyboardEvent &event)
{

}

void OpenMysteryToolkit::onInit()
{
	g_game = nctl::makeShared<Game>();

	g_game->Load(game_);

	if (!theGame().IsLoaded())
		ncine::theApplication().quit();
}

void OpenMysteryToolkit::onFrameStart()
{
	theGame().Update(ncine::theApplication().interval());
}

void OpenMysteryToolkit::onPostUpdate()
{

}
