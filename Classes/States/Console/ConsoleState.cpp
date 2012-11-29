/*
	-----------------------------------------
	ConsoleState.cpp
	The Main Menu
	-----------------------------------------
*/

// Includes
#include "ConsoleState.h"
#include "../../IGContent/PlayerData/Player.h"
#include "../../IGContent/PlayerData/World.h"
#include "../StateFunctions.h"
#include "../MainMenu/MainMenuState.h"

using namespace irr;
using namespace video;
using namespace core;

// Disable Warnings
#pragma warning (disable: 4018) // '<' : signed/unsigned mismatch

void ConsoleState::destroy()
{
	// Clean Up
	_font->drop();
}

// Initialize
void ConsoleState::init()
{
	// Get Courier Font
	_font = _coreApp->getGameManager()->getDevice()->getGUIEnvironment()->getFont(
		_coreApp->getGameManager()->getContentDirectory()+"/Fonts/Courier.bmp");

	// Initial Console Log
	initConsole();
}

// Initial Console Log
void ConsoleState::initConsole()
{
	// Update Log Line Position
	_logPos = 0;

	// Update Log
	_coreApp->addLogItem(L"//--------------------------------------------");
	_coreApp->addLogItem(L"// Tetra Irrlicht Engine (2009)");
	_coreApp->addLogItem(L"// Developed under supervision of IOjp Software");
	_coreApp->addLogItem(L"//--------------------------------------------");
	_coreApp->addLogItem(L" ");
	_coreApp->addLogItem(L"+ Debug Console");
	_coreApp->addLogItem(L"!Console Initialized");
}

// Execute Console Event
void ConsoleState::executeConsoleEvent(stringw val)
{
	val.make_lower();

	if(val=="statelog")
	{	_coreApp->addLogItem(val); _coreApp->toggleStateLog();	}
	else if(val=="debugmode")
	{	_coreApp->addLogItem(val); _coreApp->toggleDebugMode(); }
	else if(val=="exit")
	{	_coreApp->exitApplication();	}
	else if(val.subString(0,4) == "exec")
	{	
		_coreApp->addLogItem(val);

		irr::core::stringc stateRef = val.subString(5,val.size()-5);

		if(stateRef == "mainmenu")
		{
			_coreApp->addLogItem("@Main Menu State - Added to Stack");
			_coreApp->getStateManager()->add(new MainMenuState(_coreApp));
		}
	}
	else
	{	_coreApp->addLogItem("[ERROR] Unknown Command");	}

	_coreApp->getInputManager()->resetString();
}

// Do Input Events
void ConsoleState::doInputEvents()
{
	// Enter Key
	if(_coreApp->getInputManager()->CheckKey(KEY_RETURN, _coreApp->getGameManager()->getElapsedTime()))
	{
		if(_coreApp->getInputManager()->inputString().size() > 0)
		{
			executeConsoleEvent(_coreApp->getInputManager()->inputString());
			_logPos = 0;
		}
	}

	// Recall Last Line
	if(_coreApp->getInputManager()->CheckKey(KEY_LEFT, _coreApp->getGameManager()->getElapsedTime()) &&
	   _coreApp->getConsoleLog().size() > 0)
			_coreApp->getInputManager()->setInputString(_coreApp->getLogLine(_coreApp->getConsoleLog().size()-1));

	// Move Up, Log Line Position
	if(_coreApp->getInputManager()->CheckKey(KEY_DOWN, _coreApp->getGameManager()->getElapsedTime()))
		if(_logPos > 0)	{ _logPos--; }

	// Move Down, Log Line Position
	if(_coreApp->getInputManager()->CheckKey(KEY_UP, _coreApp->getGameManager()->getElapsedTime()))
		if(_logPos < (_coreApp->getConsoleLog().size() - 25))	{ _logPos++; }
	
}

// Update
void ConsoleState::update()
{
	// Do Nothing
}

// Draw
void ConsoleState::draw()
{
	// Check if font is loaded
	if(_font)
	{
		// Offset
		int offset = 0;

		// Background / Input Line Position
		int linePos = 0;

		// Calculate Positions
		if(_coreApp->getConsoleLog().size() > 25)
		{
			offset = ((_coreApp->getConsoleLog().size() - 25) - _logPos)*18;
			linePos = 25*18;
		}
		else
		{
			linePos = _coreApp->getConsoleLog().size()*18;
		}

		// Draw Background
		_coreApp->getGameManager()->getDriver()->draw2DRectangle(
			SColor(100,0,0,0),
			rect<s32>(
				0,0,
				_coreApp->getGameManager()->getWindowWidth(),linePos+18));

		// Draw Log Text
		for(int i=0; i<_coreApp->getConsoleLog().size(); i++)
			if((i*18)-offset < 25*18)
			{
				// Line Color
				SColor lineColor = SColor(255,255,255,255);

				if(_coreApp->getLogLine(i).size() > 1)	// Fail Safe
					if(_coreApp->getLogLine(i).subString(0,1) == "!")
						lineColor = SColor(255,180,255,255);
					else if(_coreApp->getLogLine(i).subString(0,2) == "//")
						lineColor = SColor(255,180,255,180);
					else if(_coreApp->getLogLine(i).subString(0,1) == "@")
						lineColor = SColor(255,255,180,255);
					else if(_coreApp->getLogLine(i).subString(0,7) == "[ERROR]")
						lineColor = SColor(255,255,130,130);
					else if(_coreApp->getLogLine(i).subString(0,1) == "(")
						lineColor = SColor(255,255,255,200);

				// Draw Line
				_font->draw(_coreApp->getLogLine(i),
						rect<s32>(
							10,(i*18)-offset,
							10,(i*18)-offset),
						lineColor,false,false);
			}

		// Get Text
		stringw consoleTest = ">";
		consoleTest += _coreApp->getInputManager()->inputString();

		// Draw Label Text
		_font->draw(consoleTest,
				rect<s32>(10,linePos,10,linePos),
				SColor(255,255,255,255),false,false);
	}
}
