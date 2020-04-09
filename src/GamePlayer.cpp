#include "GamePlayer.h"
#include "version.h"

#include <ncine/Application.h>
#include <ncine/AppConfiguration.h>
#include <ncine/IFile.h> // for dataPath()
#include <ncine/FileSystem.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/document.h>

namespace nc = ncine;

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

	// Game info
	{
		auto gameInfo = config.dataPath() + GameName + "/game.json";

		auto infoFile = nc::IFile::createFileHandle(gameInfo.data());
		infoFile->open(nc::IFile::OpenMode::READ);
		if (infoFile->isOpened())
		{
			infoFile->seek(0, SEEK_END);
			long size = infoFile->tell();
			infoFile->seek(0, SEEK_SET);

			char* buffer = static_cast<char*>(malloc(size + 1));

			infoFile->read(buffer, size);
			infoFile->close();

			rapidjson::Document document;
			document.Parse(buffer);

			free(buffer);

			if (document.HasParseError())
			{
				printf("Unable to parse JSON: %d %zd\n", document.GetParseError(), document.GetErrorOffset());
				nc::theApplication().quit();
				return;
			}

			assert(document.IsObject());

			if (!document.HasMember("name") || !document.HasMember("version") || !document.HasMember("author") || !document.HasMember("website"))
			{
				printf("JSON Invalid members!\n");
				nc::theApplication().quit();
				return;
			}

			auto nameIt = document.FindMember("name");
			auto versionIt = document.FindMember("version");

			if (!nameIt->value.IsString() || !versionIt->value.IsDouble())
			{
				printf("JSON Invalid values!\n");
				nc::theApplication().quit();
				return;
			}

			config.windowTitle = nctl::String(nameIt->value.GetStringLength() * 3).format("%s %.1f", nameIt->value.GetString(), versionIt->value.GetDouble());

			if (document.HasMember("icon"))
			{
				auto iconIt = document.FindMember("icon");

				if (!iconIt->value.IsString())
				{
					printf("JSON Invalid values!\n");
					nc::theApplication().quit();
					return;
				}

				config.windowIconFilename = GameName + "/" + iconIt->value.GetString();
			}
		}
		else
		{
			printf("Cannot access gameInfo!");
			nc::theApplication().quit();
		}
	}
}

void GamePlayer::onInit()
{

}

void GamePlayer::onKeyReleased(const nc::KeyboardEvent &event)
{
	if (event.sym == ncine::KeySym::ESCAPE)
		ncine::theApplication().quit();
}

void GamePlayer::onFrameStart()
{
	
}

nctl::String GamePlayer::GameName = nctl::String("");

nc::IAppEventHandler* createAppEventHandler()
{
	return new GamePlayer();
}
