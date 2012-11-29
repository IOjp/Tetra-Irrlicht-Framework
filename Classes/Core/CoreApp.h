//!  The Application's Core Class
/*!
	CoreApp.cpp
	The Application's Core Class
*/

#ifndef _COREAPP_H_
#define _COREAPP_H_

#include <irrlicht.h>
#include "../Managers/Managers.h"

// Core Application Class
class CoreApp
{
public:

	// Constructor
	CoreApp(bool _fullscreen, bool _additive, bool _vsync, bool _aa, irr::video::E_DRIVER_TYPE _driverType, int _resx, int _resy);

	// Deconstructor
	~CoreApp(){}

	// Main Functions
	void init(void);
	void run(void);
	void update(void);
	void draw(void);
	void doInputEvents(void);

	// Managers
	GameManager* getGameManager(){return _gameManager;}
	StateManager* getStateManager(){return _stateManager;}
	InputManager* getInputManager(){return _inputManager;}
	AudioManager* getAudioManager(){return _audioManager;}
	AssetManager* getAssetManager(){return _assetManager;}
	PlayerManager* getPlayerManager(){return _playerManager;}
	WorldManager* getWorldManager(){return _worldManager;}

	// Exit Application Indicator
	bool _doExitApp;

	// Application Functions
	void exitApplication(){_doExitApp = true;}

	// Debug Mode
	bool debugMode(){return _debugMode;}
	void toggleDebugMode()
	{
		// Warning! 
		// If you toggle debug mode, you will not be able to
		// access the console to turn it back on.  You will
		// need to reset the application.
		if(!_debugMode)
		{
			_debugMode=true;
			_log.push_back("!Debug Mode is Enabled");
		}
		else{
			_debugMode=false;
			_log.push_back("!Debug Mode is Disabled");
		}
	}

	// Get / Toggle Console Trigger
	bool isConsole(){return _isConsole;}
	void toggleConsole(){if(!_isConsole){_isConsole=true;}else{_isConsole=false;}}
	bool isStateLogged(){return _isStateLogged;}
	void toggleStateLog()
	{
		if(!_isStateLogged)
		{
			_isStateLogged=true;
			_log.push_back("!State Logging is Enabled");
		}
		else{
			_isStateLogged=false;
			_log.push_back("!State Logging is Disabled");
		}
	}

	// Get Log
	std::vector<irr::core::stringw> getConsoleLog(){return _log;}

	// Get Log Item
	irr::core::stringw getLogLine(int val)
	{
		if(val < _log.size() && val > -1)
			return _log[val];
		else
			return "Error: Line not found";
	}

	// Add Log Item
	void addLogItem(irr::core::stringw val){_log.push_back(val);}

private:

	// Irrlicht Settings
	bool _fullscreen;
	bool _additive;
	bool _vsync;
	bool _aa;
	irr::video::E_DRIVER_TYPE _driverType;
	int _resx;
	int _resy;

	// Debug Mode
	bool _debugMode;

	// Managers
	GameManager* _gameManager;
	StateManager* _stateManager;
	InputManager* _inputManager;
	AudioManager* _audioManager;
	AssetManager* _assetManager;
	PlayerManager* _playerManager;
	WorldManager* _worldManager;

	// Console
	AppState* _console;

	// Console Trigger
	bool _isConsole;

	// Log State Actions
	bool _isStateLogged;

	// Console Log 
	std::vector<irr::core::stringw> _log;

	// Background Color
	irr::video::SColor _backgroundColor;
};


#endif 
