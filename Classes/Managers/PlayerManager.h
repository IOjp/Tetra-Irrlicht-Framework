/*
	-----------------------------------------
	PlayerManager.h
	-----------------------------------------
*/

#ifndef _PLAYERMANAGER_H_
#define _PLAYERMANAGER_H_

#include "../IGContent/PlayerData/Player.h"

// Player Manager Class
class PlayerManager
{
private:

	// Player
	Player* _player;

public:
	
	// Constructor
	PlayerManager()
		: _player(0)
	{}

	// Deconstructor
	~PlayerManager(){}

	// Get Player
	Player* getPlayer(){ return _player; }

	// Create Player
	void createPlayer(Player* player){ _player = player; }

	// Delete Player
	void deletePlayer(){ _player = 0; }

};


#endif 
