/*
	-----------------------------------------
	CoreApp.cpp
	The Application's Core Class
	-----------------------------------------
*/

// Includes
#include "CoreApp.h"
#include "../States/MainMenu/MainMenuState.h"
#include "../States/Console/ConsoleState.h"

using namespace irr;
using namespace video;
using namespace core;

// Constructor
CoreApp::CoreApp(bool f, bool a, bool v, bool fsaa, video::E_DRIVER_TYPE d, int rx, int ry)
: _fullscreen(f), _additive(a), _vsync(v), _aa(fsaa), _driverType(d), _resx(rx), _resy(ry)
{}

// Application Run
void CoreApp::run()
{
	// Debug Mode?
	_debugMode = true;  

	// Log State Actions?
	_isStateLogged = false;

	// Set Default Trigger
	_isConsole = false;

	// Clear Log
	_log.clear();

	// Get Default Dimensions
	core::dimension2d<u32> _resolution ( _resx, _resy );

	// Set Default Dimensions For Older Rendering
	if ( _driverType == EDT_BURNINGSVIDEO || _driverType == EDT_SOFTWARE )
	{
		_resolution.Width = 640;
		_resolution.Height = 480;
	}

	// Gather Irrlicht Params
	SIrrlichtCreationParameters _params;
	_params.DriverType=_driverType;
	_params.WindowSize=_resolution;
	_params.Bits=32;
	_params.Fullscreen=_fullscreen;
	_params.Stencilbuffer=false;
	_params.Vsync=_vsync;
	_params.AntiAlias=_aa;

	// Create Game Manager
	_gameManager = new GameManager();

	// Create Device
	_gameManager->setDevice(_params);
	

	// If Device is Null, 
	// Exit Application
	if (_gameManager->getDevice() == 0)
		return;

	// Create Console
	_console = new ConsoleState(this);
	_console->init();

	addLogItem("");
	addLogItem("// Irrlicht Setup");
	addLogItem("!Irrlicht Device Created");

	// Update Exit Application Indicator
	_doExitApp = false;

	// Set Window Caption
	_gameManager->getDevice()->setWindowCaption(L"The Legend Of Dragoon 2: The Dark Prophecy Battle Simulation");

	// Set Background Color
	_backgroundColor = SColor(0,0,0,0);

	// Set Video Driver
	_gameManager->setDriver();
	addLogItem("!Irrlicht Driver Created");

	// Set Scene Manager
	_gameManager->setSceneManager();
	addLogItem("!Irrlicht Scene Manager Created");

	// Set GUI Enviroment
	_gameManager->setGUIEnviroment();
	addLogItem("!Irrlicht GUI Enviroment Created");

	// Set Texture Quality to 32bit
	_gameManager->getDriver()->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT);

	addLogItem("");
	addLogItem("// Managers");
	addLogItem("!Game Manager Initialized");

	// Create Input Manager
	_inputManager = new InputManager();
	addLogItem("!Input Manager Initialized");

	// Setup Event Reciever
	_gameManager->getDevice()->setEventReceiver(_inputManager);

	// Create Asset Manager
	_assetManager = new AssetManager();
	addLogItem("!Asset Manager Initialized");

	// Create Asset Container
	_assetManager->createContainer();

	// Player Manager
	_playerManager = new PlayerManager();
	addLogItem("!Player Manager Initialized");

	// World Manager
	_worldManager = new WorldManager();
	addLogItem("!World Manager Initialized");

	// Create Audio Manager
	_audioManager = new AudioManager();
	addLogItem("!Audio Manager Initialized");

	// Create State Manager
	_stateManager = new StateManager();
	addLogItem("!State Manager Initialized");

	addLogItem("");
	addLogItem("// Add Initial States to Stack");

	// Add Main Menu to Stack
	addLogItem("@Main Menu - Added to Stack Queue");
	_stateManager->add(new MainMenuState(this));

	// Begin Application Loop
	while(_gameManager->getDevice()->run() && _gameManager->getDriver())
	{
		// Check if window is active
		if (_gameManager->getDevice()->isWindowActive())
		{
			// Do Input Events
			doInputEvents();

			// Update Everything
			update();

			// Begin Scene Render
			_gameManager->getDriver()->beginScene(true, true, _backgroundColor);

			// Draw Everything
			draw();

			// End Scene Render
			_gameManager->getDriver()->endScene();
		}

		// If Indicated: Exit Application 
		if(_doExitApp)
			break;
	}

	// Drop Asset Container
	_assetManager->dropContainer();

	// Drop Device
	_gameManager->getDevice()->drop();

	return;
}

// Do Input Events
void CoreApp::doInputEvents()
{
	if(_inputManager->CheckKey(KEY_TAB, _gameManager->getElapsedTime()))
	{
		toggleConsole();
		_inputManager->toggleInputString();
	}

	if(_console && _debugMode && _isConsole)
		_console->doInputEvents();
	
	if(_stateManager->getStateStack().size() > 0 && !_isConsole)
		_stateManager->getStateStack().back()->doInputEvents();
}

// Update
void CoreApp::update()
{
	if(_console && _debugMode && _isConsole)
		_console->update();

	if(_stateManager->getStateStack().size() > 0)
		_stateManager->getStateStack().back()->update();
	else
		_doExitApp = true;
}

// Draw
void CoreApp::draw()
{
	if(_stateManager->getStateStack().size() > 0)
		_stateManager->getStateStack().back()->draw();

	if(_console && _debugMode && _isConsole)
		_console->draw();
}