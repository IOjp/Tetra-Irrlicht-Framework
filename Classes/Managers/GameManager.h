/*
	-----------------------------------------
	GameManager.h
	-----------------------------------------
*/

#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include <irrlicht.h>

// Game Manager Class
class GameManager
{
private:

	// Irrlicht Device
	irr::IrrlichtDevice* _device;

	// Video Driver
	irr::video::IVideoDriver* _driver;

	// Scene Manager
	irr::scene::ISceneManager* _smgr;

	// GUI Enviroment ( not in use )
    irr::gui::IGUIEnvironment* _gui;


public:
	
	// Constructor
	GameManager(){}

	// Deconstructor
	~GameManager(){}

	// Get Essentials
	irr::IrrlichtDevice* getDevice(){return _device;}
	irr::video::IVideoDriver* getDriver(){return _driver;}
	irr::scene::ISceneManager* getSceneManager(){return _smgr;}
	irr::gui::IGUIEnvironment* getGUIEnviroment(){return _gui;}

	// Set Essentials
	void setDevice(irr::SIrrlichtCreationParameters params){ _device = irr::createDeviceEx(params); }
	void setDriver(){ _driver = _device->getVideoDriver(); }
	void setSceneManager(){ _smgr = _device->getSceneManager();}
	void setGUIEnviroment(){ _gui = _device->getGUIEnvironment();}

	// Get Application Details
	irr::core::stringc getContentDirectory(){return "../Content";}
	int getWindowWidth(){return _driver->getScreenSize().Width;}
	int getWindowHeight(){return _driver->getScreenSize().Height;}
	float getElapsedTime(){return (float)_device->getTimer()->getTime();}
};


#endif 
