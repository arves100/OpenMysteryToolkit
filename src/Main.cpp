#include "main.h"
#include "version.h"

#include <ncine/Application.h>
#include <ncine/AppConfiguration.h>
#include <ncine/IFile.h> // for dataPath()

nc::IAppEventHandler *createAppEventHandler()
{
	return new GamePlayer;
}

void GamePlayer::onPreInit(nc::AppConfiguration &config)
{
#if defined(__ANDROID__)
	config.dataPath() = "asset::";
#elif defined(__EMSCRIPTEN__)
	config.dataPath() = "/";
#else
	#ifdef PACKAGE_DEFAULT_DATA_DIR
	config.dataPath() = PACKAGE_DEFAULT_DATA_DIR;
	#else
	config.dataPath() = "data/";
	#endif
#endif

	config.windowTitle = nctl::String("Open Mystery Toolkit Player ver ") + VersionStrings::Version + " [" + VersionStrings::CompilationDate + "] " + VersionStrings::CompilationTime;
	config.windowIconFilename = "basetoolkit/defaultIcon.png";
}

void GamePlayer::onKeyReleased(const nc::KeyboardEvent &event)
{
	if (event.sym == nc::KeySym::ESCAPE)
		nc::theApplication().quit();
}

void GamePlayer::onFrameStart()
{
	
}
