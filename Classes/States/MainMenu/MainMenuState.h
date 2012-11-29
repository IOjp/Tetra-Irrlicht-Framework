/*
	-----------------------------------------
	MainMenuState.h
	-----------------------------------------
*/

#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

#include <vector>
#include "../../Core/CoreApp.h"

// Main Menu State Class
class MainMenuState : public AppState
{
public:

	// Constructor
	MainMenuState(CoreApp* core)
		: _coreApp(core)
	{}

	// Deconstructor
	~MainMenuState(){}

	// Destroy
	void destroy();

	// Main Functions
	void init();
	void update();
	void draw();
	void doInputEvents();

	// Options Creation
	void createMainMenuOptions();
	void createOptionsOptions();
	void createExitOptions();

private:

	// CoreApp Reference
	CoreApp* _coreApp;

	// Menu Options
	std::vector<irr::core::stringw> _options;

	// Asset Reference Lists
	std::vector<int> _fontRef;
	std::vector<int> _soundRef;
	std::vector<int> _surfaceRef;

	// Selected Option
	int _selectedOption;
	irr::video::SColor _optionColor;

	// Title Alpha Color
	int _titleAlpha;

	// Background Offset
	float _backgroundOffset;

	// Start Time
	float _startTime;
	bool _resetStartTime;

	// Option Enums
	enum menuOptionType
	{
		MAINMENU,
		OPTIONS,
		EXIT
	};
	menuOptionType _optionType;
};

#endif 
