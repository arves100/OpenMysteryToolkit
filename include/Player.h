#ifndef OMT_PLAYER_H
#define OMT_PLAYER_H

class CPlayer : public ncine::IAppEventHandler, public ncine::IInputEventHandler
{
public:
	//void onPreInit(ncine::AppConfiguration &config) override;
	void onInit() override;
	void onFrameStart() override;
	void onKeyReleased(const ncine::KeyboardEvent &event) override;
};

#endif // OMT_PLAYER_H
