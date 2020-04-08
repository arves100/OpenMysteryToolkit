#ifndef OMTPLAYER_MAIN_H
#define OMTPLAYER_MAIN_H

#include <ncine/IAppEventHandler.h>
#include <ncine/IInputEventHandler.h>

namespace ncine
{
	class AppConfiguration;
}

namespace nc = ncine;

class GamePlayer :
	public nc::IAppEventHandler,
	public nc::IInputEventHandler
{
public:
	void onPreInit(nc::AppConfiguration &config) override;

	void onFrameStart() override;

	void onKeyReleased(const nc::KeyboardEvent &event) override;
};

#endif // OMTPLAYER_MAIN_H
