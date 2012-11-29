/*
	-----------------------------------------
	StateManager.h
	-----------------------------------------
*/

#ifndef _STATEMANAGER_H_
#define _STATEMANAGER_H_

#include <vector>
#include "../States/AppState.h"

// State Manager Class
class StateManager
{
private:

	// State Stack
	std::vector<AppState*> _stateStack;

public:
	
	// Constructor
	StateManager(){}

	// Deconstructor
	~StateManager(){}

	// Add Application State
	void add(AppState* appState)
	{
		_stateStack.push_back(appState);
		_stateStack.back()->init();
	}

	// Add Application State To Queue 
	void addToQueue(AppState* appState)
	{
		_stateStack.push_back(appState);
	}

	// Swap Application State
	void swap(AppState* appState)
	{
		_stateStack.back()->destroy();
		_stateStack.back()=0;
		_stateStack.pop_back();

		_stateStack.push_back(appState);
		_stateStack.back()->init();
	}

	// Previous Application State
	void previous()
	{
		_stateStack.back()->destroy();
		_stateStack.back()=0;
		_stateStack.pop_back();
	}

	// Next Queue
	void nextQueue()
	{
		_stateStack.back()->destroy();
		_stateStack.back()=0;
		_stateStack.pop_back();
		_stateStack.back()->init();
	}

	// Get State Stack
	std::vector<AppState*> getStateStack(){return _stateStack;}

	// Swtich Type
	enum stateSwitchType
	{
		NONE,
		ADDED,
		QUEUED
	};
};


#endif 
