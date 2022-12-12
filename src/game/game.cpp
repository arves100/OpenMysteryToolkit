/*
 * @file: game/game.cpp
 * @author: Arves100
 * @date: 10/15/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <game/game.h>
#include <python/omt.h>
#include <python/link.h>
#include <def/defaults.h>
#include <components/transform.h>
#include <systems/updatable.h>
#include <systems/spawn.h>

#include <ncine/Application.h>
#include <ncine/FileSystem.h>

Game::Game()
    : db_(), ECS(db_), cycles_(0), loaded_(false)
{
	AddSystem<UpdateSystem>();
	AddSystem<SpawnSystem>();
}

Game::~Game()
{
	for (auto &sys : systems_)
	{
		sys->DeInit(reg_);
	}
}

void Game::Load(nctl::String name)
{
	name_ = name;
	const auto gamePath = ncine::fs::joinPath(ncine::theApplication().appConfiguration().dataPath(), name_);

	// load game info
	if (!info_.Load(ncine::fs::joinPath(gamePath, "game.json")))
	{
		return;
	}

	if (!python_.Init(gamePath, info_.GetEntryPoint()))
	{
		LOGE("Unable to initialize Python!");
		return;
	}

	python_.Call("on_pre_init");

	if (!db_.Load(gamePath))
	{
		return;
	}

	// initialize systems
	for (auto& sys : systems_)
	{
		sys->Init(reg_);
	}

	// update UI based from game info
#ifndef OPENMYSTERYTOOLKIT_DEBUG
	ncine::theApplication().gfxDevice().setWindowTitle(info_.GetGameName().data());
#endif
	ncine::theApplication().gfxDevice().setWindowIcon(ncine::fs::joinPath(gamePath, info_.GetIcon().data()).data());

	loaded_ = true;
	python_.Call("on_init");
}

void Game::Update(float delta)
{
	UpdateSystems(0);
}

void Game::Advance()
{
	cycles_++;
}
