/*
	-----------------------------------------
	SceneMovieState.h
	-----------------------------------------
*/

#ifndef _SCENEMOVIESTATE_H_
#define _SCENEMOVIESTATE_H_

#include "../../Core/CoreApp.h"

// Scene Movie State Class
class SceneMovieState : public AppState
{
public:

	// Constructor
	SceneMovieState(CoreApp*, irr::core::stringw, StateManager::stateSwitchType type);

	// Deconstructor
	~SceneMovieState()
	{
		// Clean Up
		_font->drop();
	}

	// Destroy
	void destroy();

	// Main Functions
	void init();
	void update();
	void draw();
	void doInputEvents();

private:

	// Timer
	float _timeTillFinish;
	float _timeStart;

	// CoreApp Reference
	CoreApp* _coreApp;

	// Fonts
	irr::gui::IGUIFont* _font;

	// Countdown Text
	irr::core::stringw _countdownText;

	// Movie Name
	irr::core::stringw _movieName;

	// Type
	StateManager::stateSwitchType _type;

	// State Function Shortcuts
	// ----------------------------------------------
	// Play Sound Shortcut
	void playSound(CoreApp* core, int ref)
	{
		// Play Sound
		core->getAudioManager()->getSoundEngine()->play2D(
					core->getAssetManager()->getContainer()->getSound(ref));
	}
};

#endif 
