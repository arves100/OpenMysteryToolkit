/*
* @file: db/gameinfo.cpp
* @author: Arves100
* @date: 10/14/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include "db/gameinfo.h"
#include "def/defaults.h"

#include <nlohmann/json.hpp>

#include <ncine/IFile.h>
#include <ncine/common_macros.h>

static constexpr auto CHANNEL = "GameInfo";

bool GameInfo::Load(nctl::String path)
{
	auto asset = ncine::IFile::createFileHandle(path.data());

	if (!asset)
	{
		return false;
	}

	asset->setExitOnFailToOpen(false);
	asset->open(ncine::IFile::OpenMode::READ | ncine::IFile::OpenMode::BINARY);

	if (!asset->isOpened())
	{
		LOGE_X("Unable to open file %s", path.data());
		return false;
	}

	asset->seek(0, SEEK_END);
	auto size = asset->tell();
	asset->seek(0, SEEK_SET);

	uint8_t *data = new uint8_t[size];

	if (asset->read(data, size) != size)
	{
		asset->close();
		LOGE("Unable to read gameinfo");
		return false;
	}

	asset->close();

	data[size] = 0;

	try
	{
		const auto json = nlohmann::json::parse(data);

		if (!json.is_object())
			throw std::runtime_error("Invalid JSON root object");
		
		for (const auto& [k ,v] : json.items())
		{
			if (k == "author")
			{
				if (!v.is_string())
					throw std::runtime_error("Invalid author value");
				
				m_szAuthor = v.get<std::string>().c_str();
			}
			else if (k == "version")
			{
				if (!v.is_string())
					throw std::runtime_error("Invalid version value");
				
				m_szVersion = v.get<std::string>().c_str();
			}
			else if (k == "url")
			{
				if (!v.is_string())
					throw std::runtime_error("Invalid url value");
				
				m_szURL = v.get<std::string>().c_str();
			}
			else if (k == "icon")
			{
				if (!v.is_string())
					throw std::runtime_error("Invalid icon value");
				
				m_szIcon = v.get<std::string>().c_str();
			}
			else if (k == "gamename")
			{
				if (!v.is_string())
					throw std::runtime_error("Invalid gamename value");
				
				m_szGameName = v.get<std::string>().c_str();
			}
			else if (k == "online")
			{
				if (!v.is_boolean())
					throw std::runtime_error("Invalid online value");
				
				m_bOnline = v.get<bool>();
			}
			else if (k == "localplay")
			{
				if (!v.is_boolean())
					throw std::runtime_error("Invalid localplay value");
				
				m_bLocalPlay = v.get<bool>();
			}
			else if (k == "netplay")
			{
				if (!v.is_boolean())
					throw std::runtime_error("Invalid netplay value");
				
				m_bNetPlay = v.get<bool>();
			}
			else if (k == "entrypoint")
			{
				if (!v.is_string())
					throw std::runtime_error("Invalid icon value");
				
				m_szEntryPoint = v.get<std::string>().c_str();
			}
		}

		if (m_szEntryPoint.isEmpty())
			throw new std::runtime_error("No python entrypoint specified");
	}
	catch (std::exception& except)
	{
		LOGE_X("Unable to load gameinfo. Error: %s", except.what());
		return false;
	}

	if (m_szGameName.isEmpty())
	{
		LOGW("No gamename specified");
		m_szGameName = DEFAULT_GAME_NAME;
	}

	LOGI("Gameinfo loaded");
	return true;
}

GameInfo::GameInfo() = default;

