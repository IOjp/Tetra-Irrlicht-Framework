/*
	-----------------------------------------
	SceneMovieState.cpp
	The Class for Rendering Scene Movies
	-----------------------------------------
*/

// Includes
#include "SceneMovieState.h"

using namespace irr;
using namespace video;
using namespace core;

// Constructor
SceneMovieState::SceneMovieState(CoreApp* core, irr::core::stringw moviename, StateManager::stateSwitchType type)
: _coreApp(core), _movieName(moviename), _type(type)
{}


void SceneMovieState::destroy()
{
	// Update Log
	if(_coreApp->isStateLogged())
	{
		stringw str = "!Exiting State... ("; str += _movieName; str += ")";
		_coreApp->addLogItem(str);
	}
}

// Initialize
void SceneMovieState::init()
{
	// Update Log
	if(_coreApp->isStateLogged())
	{
		stringw str = "!Running: "; str+=_movieName;
		_coreApp->addLogItem(str);

		str = "("; str+=_movieName; str += ") - Switching to (Main)";
		_coreApp->addLogItem(str);
	}

	// Set Time Till Finish
	_timeTillFinish = _coreApp->getGameManager()->getElapsedTime() + 5000.0f;
	_timeStart = _coreApp->getGameManager()->getElapsedTime();

	// Get Courier Font
	_font = _coreApp->getGameManager()->getDevice()->getGUIEnvironment()->getFont(
		_coreApp->getGameManager()->getContentDirectory()+"/Fonts/Courier.bmp");
}

// Do Input Events
void SceneMovieState::doInputEvents()
{
	// Escape Key, Exit Application
	if(_coreApp->getInputManager()->CheckKey(KEY_ESCAPE, _coreApp->getGameManager()->getElapsedTime()))							
		_timeTillFinish = _coreApp->getGameManager()->getElapsedTime()-1.0f; 
}

// Update
void SceneMovieState::update()
{
	// Update Countdown Text
	_countdownText = _movieName;
	_countdownText += " : ";
	_countdownText += "Continuing in ";
	_countdownText += (int)(((_timeTillFinish - _coreApp->getGameManager()->getElapsedTime())/5000.0f) * 10.0f);
	_countdownText += "..";

	// If Finished: Exit Scene Movie
	if(_coreApp->getGameManager()->getElapsedTime() > _timeTillFinish)
		if(_type == StateManager::QUEUED)
			_coreApp->getStateManager()->nextQueue();
		else if(_type == StateManager::ADDED)
			_coreApp->getStateManager()->previous();
}

// Draw
void SceneMovieState::draw()
{
	// Draw Place Holder Text
	_font->draw(L"..Movie Scene Place Holder..",
		rect<s32>(
			_coreApp->getGameManager()->getWindowWidth()/2,
			_coreApp->getGameManager()->getWindowHeight()/2,
			_coreApp->getGameManager()->getWindowWidth()/2,
			_coreApp->getGameManager()->getWindowHeight()/2),
		SColor(255,255,255,255),true,true);

	// Draw Countdown Text Text
	_font->draw(_countdownText.c_str(),
		rect<s32>(
			_coreApp->getGameManager()->getWindowWidth()/2,
			_coreApp->getGameManager()->getWindowHeight()/2+30,
			_coreApp->getGameManager()->getWindowWidth()/2,
			_coreApp->getGameManager()->getWindowHeight()/2+30),
		SColor(255,255,255,255),true,true);
}
