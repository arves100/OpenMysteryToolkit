#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include <ncine/IAppEventHandler.h>
#include <ncine/IInputEventHandler.h>
#include <ncine/InputEvents.h>
#include <nctl/String.h>

namespace ncine
{
	class AppConfiguration;
}

class GamePlayer :
	public ncine::IAppEventHandler,
	public ncine::IInputEventHandler
{
public:
	static nctl::String GameName;

	void onPreInit(ncine::AppConfiguration &config) override;
	void onInit() override;

	void onFrameStart() override;

	void onKeyReleased(const ncine::KeyboardEvent &event) override;
};

#endif // GAMEPLAYER_H
