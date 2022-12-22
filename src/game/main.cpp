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
		// TODO: show something that the parameters were invalid
		LOGE("Invalid parameters!");
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

	//theGame().Update(0.0f, currentWorldState_);
}

void OpenMysteryToolkit::onFrameStart()
{
	/*
	* Loop flow chart based from Unity game loop (Fixed time step stage)
	* NOTE: The update function is called during the FPS updates, having this code here tides up the physics core to the FPS of the application
	* 
	* -- Physics update (30 TPS)
	* 0. Determine if the physics tps has been ticked
	* 1. Update AI (State machines)
	* 2. Update systems based from the current cycles (this counts as Unity physics update function)
	* 3. Run physics/box2d update
	* 4. Goto 0 if the physics tps has been ticked again
	*
	* -- Render update (Variable FPS)
	* 5. Run coroutine updates
	* 6. Update the entity animation time for drawing
	* 7. Render scene (this is done by nCine after onFrameStart())
	*
	* We don't have the entity update here because we use the accumulator concept, updating the physics by the accumulator tides the physics to the render time
	*/

	auto frameTime = ncine::theApplication().interval();
	static constexpr float fixedDelta = 1.0f / 30.0f; // Physics TPS

	accumulator_ += frameTime;

	while (accumulator_ >= fixedDelta) // 0. and 4.
	{
		// updates the physics (eg: current position of the player)

		//previousWorldState_ = currentWorldState_;
		//theGame().Update(fixedDelta, currentWorldState_);

		theGame().Update(fixedDelta);
		accumulator_ -= fixedDelta;
	} 

	//const auto alpha = accumulator_ / fixedDelta;
	//const auto renderWorldState = currentWorldState_ * alpha + previousWorldState_ * (1.0f - alpha);

	// updates the render (eg: current animation time of the movement of the player)
	//theGame().Render(renderWorldState);

	theGame().Render(frameTime);

	// 7. --- end
}
