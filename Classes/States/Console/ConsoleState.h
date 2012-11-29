/*
	-----------------------------------------
	ConsoleState.h
	-----------------------------------------
*/

#ifndef _CONSOLESTATE_H_
#define _CONSOLESTATE_H_

#include <vector>
#include "../../Core/CoreApp.h"

// Console State Class
class ConsoleState : public AppState
{
public:

	// Constructor
	ConsoleState(CoreApp* core)
		: _coreApp(core)
	{}

	// Deconstructor
	~ConsoleState(){}

	// Destroy
	void destroy();

	// Main Functions
	void init();
	void update();
	void draw();
	void doInputEvents();

private:

	// Initial Console Log
	void initConsole(); 

	// Fonts
	irr::gui::IGUIFont* _font;

	// Execute Console Event
	void executeConsoleEvent(irr::core::stringw val);

	// CoreApp Reference
	CoreApp* _coreApp;

	// Asset Reference Lists
	std::vector<int> _fontRef;
	std::vector<int> _soundRef;

	// Log Line Position
	int _logPos;
};

#endif 
