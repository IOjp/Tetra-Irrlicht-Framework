/*
	-----------------------------------------
	StateFunctions.h
	-----------------------------------------
*/

#ifndef _StateFunctions_H_
#define _StateFunctions_H_

#include <irrlicht.h>
#include <vector>

class StateFunctions
{
public:

	// State Function Shortcuts
	// ----------------------------------------------

	// Play Sound Shortcut
	static void playSound(CoreApp* core, int ref)
	{
		// Play Sound
		core->getAudioManager()->getSoundEngine()->play2D(
					core->getAssetManager()->getContainer()->getSound(ref));
	}

	// Get Asset Shortcuts,
	// Get Font Shortcut
	static irr::gui::IGUIFont* getFont(CoreApp* core, int ref)
	{
		return core->getAssetManager()->getContainer()->getFont(ref);
	}
	// Get Surface Shortcut
	static irr::video::ITexture* getSurface(CoreApp* core, int ref)
	{
		return core->getAssetManager()->getContainer()->getSurface(ref);
	}
	// Get Mesh Shortcut
	static irr::scene::IAnimatedMesh* getMesh(CoreApp* core, int ref)
	{
		return core->getAssetManager()->getContainer()->getMesh(ref);
	}

	// Rendering Shortcuts,
	// Draw Doubled Text
	static void drawDoubledText(irr::core::stringw text, irr::gui::IGUIFont* font, 
		irr::core::position2d<irr::s32> loc, irr::video::SColor color, bool center)
	{
		// Draw Option Text
		font->draw(text,
			irr::core::rect<irr::s32>(loc.X+1,loc.Y+1,loc.X+1,loc.Y+1),
			irr::video::SColor(255,0,0,0),center,false);

		// Draw Option Text
		font->draw(text,
			irr::core::rect<irr::s32>(loc.X,loc.Y,loc.X,loc.Y),
		color,center,false);
	}
	static void drawDoubledText(irr::core::stringw text, irr::gui::IGUIFont* font, 
		irr::core::position2d<irr::s32> loc, irr::video::SColor color)
	{
		drawDoubledText(text, font, loc, color, false);
	}

	// Game Manager Shortcuts,
	// Get Device
	static irr::IrrlichtDevice* getDevice(CoreApp* core)
	{
		return core->getGameManager()->getDevice();
	}
	// Get Driver
	static irr::video::IVideoDriver* getDriver(CoreApp* core)
	{
		return core->getGameManager()->getDriver();
	}
	// Get Scene Manager
	static irr::scene::ISceneManager* getSceneManager(CoreApp* core)
	{
		return core->getGameManager()->getSceneManager();
	}
	// Get GUI Enviroment
	static irr::gui::IGUIEnvironment* getGUI(CoreApp* core)
	{
		return core->getGameManager()->getGUIEnviroment();
	}

	// Calculative Shortcuts,
	// Convert Playtime Seconds into String
	static irr::core::stringw convertPlayTime(int time)
	{
		// Create Temp String / Ints
		irr::core::stringw str = "";	
		int seconds = 0;
		int minutes = 0;
		int hours = 0;

		// More Than a Minute
		if(time > 3599)
		{
			hours = time/3600;
			seconds = time-(hours*3600);

			minutes = seconds/60;
			seconds = seconds-(minutes*60);
		}else if(time > 59)
		{
			minutes = time/60;
			seconds = time-(minutes*60);
		}

		// Update String
		if(hours<10)
			str+="0";
		str+=hours;
		str+=":";
		if(minutes<10)
			str+="0";
		str+=minutes;
		str+=":";
		if(seconds<10)
			str+="0";
		str+=seconds;

		// Return String
		return str;
	}
};

#endif 
