/*
* @file: python/modules/system.cpp
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#include <python/modules.h>
#include <ncine/Application.h>
#include <game/game.h>
#include <version.h>

/*!
* Gets the current cycle of the game
*/
static auto cycles()
{
	return theGame().GetCycles();
}

/*!
* Shuts down the application
*/
static void quit()
{
	ncine::theApplication().quit();
}

MOD_FUNC(system)
{
	m.def("quit", quit);
	m.def("cycles", cycles);

	m.attr("VERSION") = VersionStrings::Version;
	m.attr("COMMIT") = VersionStrings::GitShortHash;
	m.attr("BRANCH") = VersionStrings::GitBranch;
	m.attr("COMPILE_DATE") = VersionStrings::CompilationDate;
	m.attr("COMPILE_TIME") = VersionStrings::CompilationTime;

	#ifdef OPENMYSTERYTOOLKIT_DEBUG
	m.attr("DEBUG") = true;
	#else
	m.attr("DEBUG") = false;
	#endif
}
