/*
	-----------------------------------------
	AppState.h
	The Base for Application States
	-----------------------------------------
*/

#ifndef _APPSTATE_H_
#define _APPSTATE_H_

// Application State Base Class
class AppState
{
public:

	// Destroy
	virtual void destroy(){}

	// Main Functions
	virtual void init(void) = 0;
	virtual void update(void) = 0;
	virtual void draw(void) = 0;
	virtual void doInputEvents(void) = 0;

protected:

	// Constructor
	AppState(){}

};

#endif 
