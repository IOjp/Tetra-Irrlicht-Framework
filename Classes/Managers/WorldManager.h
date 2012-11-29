/*
	-----------------------------------------
	WorldManager.h
	-----------------------------------------
*/

#ifndef _WORLDMANAGER_H_
#define _WORLDMANAGER_H_

#include "../IGContent/PlayerData/World.h"

// World Manager Class
class WorldManager
{
private:

	// World
	World* _world;

public:
	
	// Constructor
	WorldManager()
		: _world(0)
	{}

	// Deconstructor
	~WorldManager(){}

	// Get World
	World* getWorld(){ return _world; }

	// Create World
	void createWorld(World* world){ _world = world; }

	// Delete World
	void deleteWorld(){ _world = 0; }
};


#endif 