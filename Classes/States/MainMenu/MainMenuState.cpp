/*
	-----------------------------------------
	MainMenuState.cpp
	The Main Menu
	-----------------------------------------
*/

// Includes
#include "MainMenuState.h"
#include "../Movie/SceneMovieState.h"
#include "../StateFunctions.h"

using namespace irr;
using namespace video;
using namespace core;

// Disable Warnings
#pragma warning (disable: 4018) // '<' : signed/unsigned mismatch

void MainMenuState::destroy()
{
	// Update Log
	if(_coreApp->isStateLogged())
		_coreApp->addLogItem("!Exiting State...  (Main Menu)");

	// Destroy Non-Shared Assets
	// To avoid complications, destroy them 
	// in the *opposite* order they were created.

	// Drop Surfaces, 
	// This will drop the Container References
	// and unload the texture from memory.
	_coreApp->getAssetManager()->dropSurface(_surfaceRef[1], _coreApp->getGameManager());
	_coreApp->getAssetManager()->dropSurface(_surfaceRef[0], _coreApp->getGameManager());

	// Drop Local References,
	// These must be called after Drop Surfaces
	_surfaceRef.erase(_surfaceRef.begin()+1);
	_surfaceRef.erase(_surfaceRef.begin());
}

// Initialize
void MainMenuState::init()
{
	// Update Log
	if(_coreApp->isStateLogged())
		_coreApp->addLogItem("!Running: Main Menu");

	// Load Non-Shared / Shared Assets,
	// Collect Shared Asset References.

	/*  Load Sounds,
		0 = Select
		1 = Enter
		2 = Cancel
		3 = Background Music (Opted Out)
	*/
	_soundRef.push_back(_coreApp->getAssetManager()->createSound("../Content/Audio/Sounds/Select.wav", _coreApp->getGameManager(), _coreApp->getAudioManager()));
	_soundRef.push_back(_coreApp->getAssetManager()->createSound("../Content/Audio/Sounds/Enter.wav", _coreApp->getGameManager(), _coreApp->getAudioManager()));
	_soundRef.push_back(_coreApp->getAssetManager()->createSound("../Content/Audio/Sounds/Cancel.wav", _coreApp->getGameManager(), _coreApp->getAudioManager()));
	//_soundRef.push_back(_coreApp->getAssetManager()->createSound("../Content/Audio/Music/BackgroundSave.mp3", _coreApp->getGameManager(), _coreApp->getAudioManager()));

	/*  Load Fonts,
		0 = Courier
	*/
	_fontRef.push_back(_coreApp->getAssetManager()->createFont("Courier.bmp", _coreApp->getGameManager()));

	/*  Load Surfaces,
		0 = Title Image
		1 = Background Image
	*/
	_surfaceRef.push_back(_coreApp->getAssetManager()->createSurface("Menu/title.png", _coreApp->getGameManager()));
	_surfaceRef.push_back(_coreApp->getAssetManager()->createSurface("Menu/background.png", _coreApp->getGameManager()));

	// Set Options
	createMainMenuOptions();

	// Set Title Alpha
	_titleAlpha = 0;

	// Set Background Offset
	_backgroundOffset = -300.0f;

	// Set Start Time
	_startTime = _coreApp->getGameManager()->getElapsedTime();
	_resetStartTime = false;
}

// Create Main Menu Options
void MainMenuState::createMainMenuOptions()
{
	// Update Log
	if(_coreApp->isStateLogged())
		_coreApp->addLogItem("(Main Menu) - Switching to (Main)");

	// Set Type
	_optionType = MainMenuState::MAINMENU;

	// Clear Options
	_options.clear();

	// Set Options
	_options.push_back(L"New Game");
	_options.push_back(L"Continue");
	_options.push_back(L"Options");
	if(_coreApp->debugMode())
		_options.push_back(L"Debug Mode Page");

	// Set Selected Option
	_selectedOption = 0;
}

// Create Main Menu Options
void MainMenuState::createOptionsOptions()
{
	// Update Log
	if(_coreApp->isStateLogged())
		_coreApp->addLogItem("(Main Menu) - Switching to (Options)");

	// Set Type
	_optionType = MainMenuState::OPTIONS;

	// Clear Options
	_options.clear();

	// Set Options
	_options.push_back(L"Options 1");
	_options.push_back(L"Options 2");
	_options.push_back(L"Options 3");
	_options.push_back(L"Options 4");

	// Set Selected Option
	_selectedOption = 0;
}

// Create Exit Options
void MainMenuState::createExitOptions()
{
	// Update Log
	if(_coreApp->isStateLogged())
		_coreApp->addLogItem("(Main Menu) - Switching to (Exit)");

	// Set Type
	_optionType = MainMenuState::EXIT;

	// Clear Options
	_options.clear();

	// Set Options
	_options.push_back(L"Go Back");
	_options.push_back(L"Exit Game?");

	// Set Selected Option
	_selectedOption = 0;
}

// Do Input Events
void MainMenuState::doInputEvents()
{
	// Escape Key, Exit Application
	if(_coreApp->getInputManager()->CheckKey(KEY_ESCAPE, _coreApp->getGameManager()->getElapsedTime()))				
		if(_optionType == MainMenuState::OPTIONS)
		{
			// Change to Mainmenu
			createMainMenuOptions();

			// Play Sound
			StateFunctions::playSound(_coreApp, _soundRef[2]);

		}else if(_optionType == MainMenuState::EXIT)
		{
			// Do Nothing
		}else
		{
			if(_backgroundOffset < 0.0f)
				_backgroundOffset = 0.0f;
			else
			{
				// Play Sound
				StateFunctions::playSound(_coreApp, _soundRef[1]);

				createExitOptions();
			}
		}


	// Check if Title 100%
	if(_titleAlpha >= 255)
	{
		// Select Next Option
		if(_coreApp->getInputManager()->CheckKey(KEY_DOWN, _coreApp->getGameManager()->getElapsedTime()))				
			if(_selectedOption < _options.size()-1)
			{
				// Update Option
				_selectedOption++;

				// Play Sound
				//_coreApp->getAudioManager()->getSoundEngine()->play2D(
					//_coreApp->getAssetManager()->getContainer()->getSound(_soundRef[0]));
				StateFunctions::playSound(_coreApp, _soundRef[0]);

				// Update Start Time
				_startTime = _coreApp->getGameManager()->getElapsedTime();
			}

		// Select Previous Option
		if(_coreApp->getInputManager()->CheckKey(KEY_UP, _coreApp->getGameManager()->getElapsedTime()))				
			if(_selectedOption > 0)
			{
				// Update Option
				_selectedOption--;

				// Play Sound
				StateFunctions::playSound(_coreApp, _soundRef[0]);

				// Update Start Time
				_startTime = _coreApp->getGameManager()->getElapsedTime();
			}
	}

	// Enter Key
	if(_coreApp->getInputManager()->CheckKey(KEY_RETURN, _coreApp->getGameManager()->getElapsedTime()))
	{
		if(	_optionType == MainMenuState::MAINMENU)		
		{
			// Play Sound
			StateFunctions::playSound(_coreApp, _soundRef[1]);

			// Do Action
			if(_selectedOption == 2)
			{
				// Create Options
				createOptionsOptions();
			}else if(_selectedOption == 1)
			{
				//_coreApp->addLogItem("@Save State - Added to Stack");
				// Run Save State
				//_coreApp->getStateManager()->add(new SaveState(_coreApp, SaveState::LOAD));
			}else if(_selectedOption == 3)
			{
				//_coreApp->addLogItem("@Debug Mode Scene - Added to Stack");
				// Run Debug Mode State
				//_coreApp->getStateManager()->add(new DebugModeState(_coreApp));
			}
		}else if(_optionType == MainMenuState::EXIT)	
		{
			// Play Sound
			StateFunctions::playSound(_coreApp, _soundRef[1]);

			// Do Action
			if(_selectedOption == 0)
			{
				createMainMenuOptions();
			}else if(_selectedOption == 1)
			{
				_coreApp->exitApplication();
			}
		}
	}
}

// Update
void MainMenuState::update()
{
	// Reset Start Time 
	if(_resetStartTime)
	{
		_startTime = _coreApp->getGameManager()->getElapsedTime();
		_resetStartTime = false;
	}

	// Update Title Alpha
	if(_titleAlpha < 255 && _backgroundOffset >= 0.0f)
		_titleAlpha++;
	else if(_backgroundOffset < 0.0f)
		_backgroundOffset+=0.5f;
	else if(_backgroundOffset > 0.0f)
		_backgroundOffset=0.0f;

	// Show Intro Movie if Idle
	if(_startTime+30000.0f < _coreApp->getGameManager()->getElapsedTime())
	{
		_resetStartTime = true;
		_selectedOption = 0;
		_titleAlpha = 0;
		_backgroundOffset = -300.0f;
		_coreApp->addLogItem("@Intro Movie - Added to Stack");
		_coreApp->getStateManager()->add(new SceneMovieState(_coreApp, L"Intro Movie", StateManager::ADDED));
		draw();
	}

}

// Draw
void MainMenuState::draw()
{
	// Draw Background Image
	if (StateFunctions::getSurface(_coreApp, _surfaceRef[1]))
		_coreApp->getGameManager()->getDriver()->draw2DImage(
			StateFunctions::getSurface(_coreApp, _surfaceRef[1]), 
			position2d<s32>(0,(int)_backgroundOffset),
			rect<s32>(
				0,0,
				_coreApp->getGameManager()->getWindowWidth(),
				_coreApp->getGameManager()->getWindowHeight()+300));

	// Draw Title Image
	if (StateFunctions::getSurface(_coreApp, _surfaceRef[0]))
		_coreApp->getGameManager()->getDriver()->draw2DImage(
			StateFunctions::getSurface(_coreApp, _surfaceRef[0]), 
			position2d<s32>(
				(_coreApp->getGameManager()->getWindowWidth()/2)-250,
				(_coreApp->getGameManager()->getWindowHeight()/2)-200), 
				rect<s32>(
				0,0,
				StateFunctions::getSurface(_coreApp, _surfaceRef[0])->getSize().Width,
				StateFunctions::getSurface(_coreApp, _surfaceRef[0])->getSize().Height),
				0, SColor(_titleAlpha,255,255,255), true);

	// Draw Menu Options
	if (StateFunctions::getFont(_coreApp, _fontRef[0]) && _titleAlpha >= 255)
		for(int i=0; i<_options.size(); i++)
		{
			// Update Selected Option Text Color
			if(_selectedOption == i)
				_optionColor = SColor(255,255,100,0);
			else
				_optionColor = SColor(255,255,255,255);

			// Draw Option Text
			StateFunctions::getFont(_coreApp, _fontRef[0])->draw(_options[i],
					rect<s32>(
						_coreApp->getGameManager()->getWindowWidth()/2,
						_coreApp->getGameManager()->getWindowHeight()/2+(i*30),
						_coreApp->getGameManager()->getWindowWidth()/2,
						_coreApp->getGameManager()->getWindowHeight()/2+(i*30)),
					_optionColor,true,true);

			// Draw Copyright
			StateFunctions::getFont(_coreApp, _fontRef[0])->draw("..Copyright Information Place Holder..",
					rect<s32>(
						_coreApp->getGameManager()->getWindowWidth()/2,
						_coreApp->getGameManager()->getWindowHeight()-50,
						_coreApp->getGameManager()->getWindowWidth()/2,
						_coreApp->getGameManager()->getWindowHeight()-45),
					SColor(255,255,255,255),true,true);
		}

}
