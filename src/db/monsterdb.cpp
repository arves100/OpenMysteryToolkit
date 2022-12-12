/*
 * @file: db/monsterdb.cpp
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <db/monsterdb.h>
#include <db/loader.h>
#include <def/deftable.h>

#include <ncine/common_macros.h>
#include <ncine/IFile.h>

#define MONSTER_MAGIC 1330467919U // OTMO

MonsterDb::MonsterDb(AbilityDb &adb)
    : table_(MONSTER_MAX_TBL), abi_(adb) {}

bool MonsterDb::Init(nctl::String path)
{
	TableHeader header;

	auto file = ncine::IFile::createFileHandle(path.data());
	file->setExitOnFailToOpen(false);
	file->setCloseOnDestruction(true);

	file->open(ncine::IFile::OpenMode::BINARY | ncine::IFile::OpenMode::READ);

	if (!file->isOpened())
	{
		return false;
	}

	Loader ldr(*file);

	if (!ldr.Load(header, MONSTER_MAGIC))
	{
		LOGE("Invalid file");
		return false;
	}

	for (uint32_t i = 0; i < header.size; i++)
	{
		MonsterInfo info;
		
		if (!ldr.Load(info.id))
		{
			LOGE("Invalid file");
			return false;
		}

		if (info.id == 0)
		{
			LOGE_X("Invalid entity id (entry %u)", i);
			return false;
		}

		if (!ldr.Load(info.baseStats))
		{
			LOGE("Invalid file");
			return false;
		}

		if (!ldr.Load(info.iq))
		{
			LOGE("Invalid file");
			return false;
		}

		if (info.iq != 0)
		{
			// todo
		}

		if (!ldr.Load(info.tileSize))
		{
			LOGE("Invalid file");
			return false;
		}

		if (info.tileSize == 0)
		{
			LOGE_X("Invalid tile size (entity %u)", info.id);
			return false;
		}

		for (uint8_t k = 0; k < ABILITY_MAX; k++)
		{
			AbilityId abiid;
			if (!ldr.Load(abiid))
			{
				LOGE("Invalid file");
				return false;
			}

			if (abiid != 0)
			{
				auto abi = abi_.Query(abiid);
				if (!abi.has_value())
				{
					LOGE_X("Invalid ability on entity %u", i);
					return false;
				}

				info.abilities[k] = abi.value();
			}
		}

		CurveId cid;
		if (!ldr.Load(cid))
		{
			LOGE("Invalid file");
			return false;
		}

		if (cid != 0)
		{
			// todo
		}

		if (!ldr.Load(info.allowedGenders))
		{
			LOGE("Invalid file");
			return false;
		}

		if (!ldr.Load(info.recluitRateo))
		{
			LOGE("Invalid file");
			return false;
		}

		if (!ldr.Load(info.genderSpawnPct))
		{
			LOGE("Invalid file");
			return false;
		}

		for (uint8_t k = 0; k < ATTRIBUTE_MAX; k++)
		{
			if (!ldr.Load(info.attributes[k]))
			{
				LOGE("Invalid file");
				return false;
			}
		}

		if (!ldr.Load(info.baseLevel))
		{
			LOGE("Invalid file");
			return false;
		}

		if (info.baseLevel < 1)
		{
			LOGE_X("Invalid level specified for entity %u", info.id);
			return false;
		}

		table_.insert(info.id, info);
	}

	return true;
}

std::optional<MonsterInfo> MonsterDb::Query(MonsterId id) const
{
	MonsterInfo e;
	if (!table_.contains(id, e))
		return std::nullopt;

	return e;
}
