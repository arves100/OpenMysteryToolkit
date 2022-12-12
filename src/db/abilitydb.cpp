/*
 * @file: db/abilitydb.cpp
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <db/abilitydb.h>
#include <db/loader.h>
#include <def/deftable.h>

#include <ncine/common_macros.h>
#include <ncine/IFile.h>

#define ABILITY_MAGIC 1111577679U // OTAB

AbilityDb::AbilityDb()
    : abilities_(ABILITY_MAX_TBL) {}


bool AbilityDb::Init(nctl::String path)
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

	if (!ldr.Load(header, ABILITY_MAGIC))
	{
		LOGE("Invalid file");
		return false;
	}

	for (uint32_t i = 0; i < header.size; i++)
	{
		AbilityId id;
		if (!ldr.Load(id))
		{
			LOGE("Invalid file");
			return false;
		}

		if (id == 0)
		{
			LOGE_X("Invalid ability id (entry %u)", i);
			return false;
		}

		Ability abi;
		if (!ldr.Load(abi.on_cycle))
		{
			LOGE("Invalid file");
			return false;
		}

		if (!ldr.Load(abi.on_atk))
		{
			LOGE("Invalid file");
			return false;
		}

		if (!ldr.Load(abi.on_def))
		{
			LOGE("Invalid file");
			return false;
		}

		if (!ldr.Load(abi.on_kill))
		{
			LOGE("Invalid file");
			return false;
		}

		if (!ldr.Load(abi.on_die))
		{
			LOGE("Invalid file");
			return false;
		}

		abilities_.insert(id, abi);
	}

	return true;
}

std::optional<Ability> AbilityDb::Query(AbilityId id) const
{
	Ability e;
	if (!abilities_.contains(id, e))
		return std::nullopt;

	return e;
}

