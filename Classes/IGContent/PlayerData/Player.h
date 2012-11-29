/*
	-----------------------------------------
	Player.h
	-----------------------------------------
*/

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <irrlicht.h>
#include <vector>
#include "../BaseCharacter.h"
#include "../BaseItem.h"
#include "../BaseGood.h"

// Owned Character Class
class OwnedCharacter
{
public:

	// Characters
	BaseCharacter* character;

	// Playable?
	bool isPlayable;

	// On Team?
	bool isOnTeam;

	// Constructor
	OwnedCharacter(BaseCharacter* chr)
		: character(chr),isPlayable(true), isOnTeam(false)
	{}
};

// Player Options Class
class PlayerOptions
{
public:
	// Options
	bool vibrate;
	bool stereo;
	bool shortMorph;
	const char* noteOption;

	// Constructor
	PlayerOptions()
		: vibrate(false),stereo(false),shortMorph(false),noteOption("None")
	{}
};

// Player Class
class Player
{
private:

	// Owned Characters
	std::vector<OwnedCharacter*> _ownedCharacters;

	// Owned Items
	std::vector<BaseItem*> _ownedItems;

	// Owned Armor
	std::vector<BaseArmor*> _ownedArmor;

	// Owned Goods
	std::vector<BaseGood*> _ownedGoods;

	// Player Options
	PlayerOptions* _playerOptions;

	// Player Name
	const char* _playerName;

	// Owned Gold
	int _ownedGold;

	// Total Play Time
	int _totalPlayTime;

	// Star Dust
	int _starDust;

	// Dragon Spirits
	std::vector<const char*> _ownedDragonSpirits;

public:

	// Constructor
	Player()
		: _ownedCharacters(0), _ownedItems(0), _ownedArmor(0), _ownedGoods(0),
		  _playerOptions(0), _ownedGold(0), _totalPlayTime(0),
		  _starDust(0), _ownedDragonSpirits(0), _playerName("None")
	{}

	// Deconstructor
	~Player(){}

	// Delete Player
	void deletePlayer()
	{
		// Clear Lists
		_ownedCharacters.clear();
		_ownedItems.clear();
		_ownedArmor.clear();
		_ownedGoods.clear();
		_ownedDragonSpirits.clear();
	}

	// Get Variables
	std::vector<OwnedCharacter*> getOwnedCharacters(){ return _ownedCharacters;}
	std::vector<BaseItem*> getOwnedItems(){ return _ownedItems;}
	std::vector<BaseArmor*> getOwnedArmor(){ return _ownedArmor;}
	std::vector<BaseGood*> getOwnedGoods(){ return _ownedGoods;}
	std::vector<const char*> getDragonSpirits(){ return _ownedDragonSpirits;}
	const char* getDragonSpirit(int ind){ return _ownedDragonSpirits[ind];}
	const char* getPlayerName(){ return _playerName;}
	int getOwnedGold(){ return _ownedGold;}
	int getTotalPlayTime(){ return _totalPlayTime;}
	int getStarDust(){ return _starDust;}
	PlayerOptions* getPlayerOptions(){ return _playerOptions; }

	// Set Variables
	void setPlayerName(const char* pn){ _playerName = pn;}
	void setOwnedGold(int gold){ _ownedGold = gold;}
	void setTotalPlayTime(int playtime){ _totalPlayTime = playtime;}
	void setStarDust(int dust){ _starDust = dust;}
	void setPlayerOptions(PlayerOptions* options){ _playerOptions = options; }

	// Add to List
	void addOwnedCharacter( OwnedCharacter* val ){ _ownedCharacters.push_back(val);}
	void addOwnedItem( BaseItem* val ){ _ownedItems.push_back(val);}
	void addOwnedGood( BaseGood* val ){ _ownedGoods.push_back(val);}
	void addOwnedArmor( BaseArmor* val ){ _ownedArmor.push_back(val);}
	void addDragonSpirit( const char* val ){ _ownedDragonSpirits.push_back(val);}
};


#endif 
