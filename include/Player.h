/*+===================================================================
	File:		Player.h

	Summary:	nCine application main class.

	This file is part of OpenMysteryToolkit. Copyright © 2019 Arves100.
	For more information, visit: https://www.github.com/arves100/OpenMysteryToolkit
===================================================================+*/

#ifndef OMT_PLAYER_H
#define OMT_PLAYER_H

/*C===================================================================
	Class:		CPlayer

	Summary:	This class implements an nCine compatible application

	Methods:	onInit
					Fired when nCine is initialized.
				onFrameStart
					Fired when a new frame has started
				onKeyReleased
					Fired when a button is released from the keyboard
===================================================================C*/
class CPlayer : public ncine::IAppEventHandler, public ncine::IInputEventHandler
{
public:
	/*M===================================================================
		Method:		CPlayer::onInit

		Summary:	This method is overrided from ncine::IAppEventHandler.
					This method is fired when the nCine has been initialized, and the game is ready to initialize it's own data.

		Args:		ncine::AppConfiguration& cConfig
						A class used to set the game and engine configuration to the nCine.

		Modifies:	None

		Returns:	void
	===================================================================M*/
	void onPreInit(ncine::AppConfiguration& cConfig) override;
	
	/*M===================================================================
		Method:		CPlayer::onInit

		Summary:	This method is overrided from ncine::IAppEventHandler.
					This method is fired when the nCine has been initialized, and the game is ready to initialize it's own data.

		Args:		None

		Modifies:	None

		Returns:	void
	===================================================================M*/
	void onInit() override;

	/*M===================================================================
		Method:		CPlayer::onFrameStart

		Summary:	This method is overrided from ncine::IAppEventHandler.
					This method is fired when a rendering frame is started.

		Args:		None

		Modifies:	None

		Returns:	void
	===================================================================M*/
	void onFrameStart() override;

	/*M===================================================================
		Method:		CPlayer::onKeyReleased

		Summary:	This method is overrided from ncine::IInputEventHandler.
					This method is fired when a button has been released from the keyboard.

		Args:		const ncine::KeyboardEvent& eEvent
						An event containing the keyboard button released.

		Modifies:	None

		Returns:	void
	===================================================================M*/
	void onKeyReleased(const ncine::KeyboardEvent& eEvent) override;

	/*M===================================================================
		Method:		CPlayer::onShutdown

		Summary:	This method is overrided from ncine::IAppEventHandler.
					This method is fired when the ncine is shutting down, allowing to release all game components.

		Args:		None

		Modifies:	None

		Returns:	void
	===================================================================M*/
	void onShutdown() override;
};

#endif // OMT_PLAYER_H
