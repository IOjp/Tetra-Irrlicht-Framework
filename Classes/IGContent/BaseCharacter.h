/*
	-----------------------------------------
	BaseCharacter.h
	-----------------------------------------
*/

#ifndef _BaseCharacter_H_
#define _BaseCharacter_H_

#include "../BaseIGContent.h"
#include "../Elements.h"
#include "../BaseArmor.h"
#include "../BaseMagic.h"
#include "../BaseAddition.h"

// Base Character Class
class BaseCharacter : public BaseIGContent
{
protected:

	// Base Attributes,
	// Defined in the content header file
	const char* _gender;
	const char* _race;
	const char* _hair;
	int _age;
	int _height;
	const char* _home;
	const char* _element;
	bool _isTeamAlways;
	bool _canCastMagic;
	bool _canTransform;
	int _level;
	int _dragoonLevel;
	int _speed;

	int _maxLevel;
	int _minHP;
	int _maxHP;
	int _minMP;
	int _maxMP;
	int _minEXP;
	int _maxEXP;

	int _minNormalAttack;
	int _maxNormalAttack;
	int _minMagicAttack;
	int _maxMagicAttack;
	int _minNormalDefense;
	int _maxNormalDefense;
	int _minMagicDefense;
	int _maxMagicDefense;

	int _maxNormalAttackDragoon;
	int _maxMagicAttackDragoon;
	int _maxNormalDefenseDragoon;
	int _maxMagicDefenseDragoon;

	int _dLevel1SP;
	int _dLevel2SP;
	int _dLevel3SP;
	int _dLevel4SP;
	int _dLevel5SP;

	std::vector<BaseMagic*> _magic;
	std::vector<BaseAddition*> _additions;

	BaseArmor* _weaponArmor;
	BaseArmor* _headArmor;
	BaseArmor* _chestArmor;
	BaseArmor* _legArmor;
	BaseArmor* _accArmor;

	// Attributes
	int _currentHP;
	int _currentMP;
	int _currentSP;
	int _currentXP;
	int _currentDLSP;

public:

	// Constructor
	BaseCharacter()
	{}

	// Deconstructor
	~BaseCharacter(){}

	// Get Details
	const char* getGender(){			return _gender; }
	const char* getRace(){				return _race; }
	const char* getHair(){				return _hair; }
	int getAge(){						return _age; }
	int getHeight(){					return _height; }
	const char* getHome(){				return _home; }
	bool isTeamAlways(){				return _isTeamAlways; }
	bool canCastMagic(){				return _canCastMagic; }
	bool canTransform(){				return _canTransform; }

	// Get Attributes
	int getLevel(){						return _level; }
	int getCurrentHP(){					return _currentHP; }
	int getMaxHP(){						return (int)(((float)_level/(float)_maxLevel)*(_maxHP-_minHP)+_minHP); }
	int getCurrentMP(){					return _currentMP; }
	int getMaxMP(){						return (int)(((float)_dragoonLevel/5.0f)*(_maxMP-_minMP)+_minMP); }
	int getCurrentSP(){					return _currentSP; }
	int getMaxSP(){						return _dragoonLevel*100; }
	int getCurrentXP(){					return _currentXP; }
	int getCurrentDLSP(){				return _currentDLSP; }
	int getDragoonLevel(){				return _dragoonLevel; }
	int getSpeed(){						return _speed; }
	const char* getElement(){			return _element; }

	int getNormalAttack(){				return (int)(((float)_level/(float)_maxLevel)*(_maxNormalAttack-_minNormalAttack)+_minNormalAttack); }
	int getNormalDefense(){				return (int)(((float)_level/(float)_maxLevel)*(_maxNormalDefense-_minNormalDefense)+_minNormalDefense); }
	int getMagicAttack(){				return (int)(((float)_level/(float)_maxLevel)*(_maxMagicAttack-_minMagicAttack)+_minMagicAttack); }
	int getMagicDefense(){				return (int)(((float)_level/(float)_maxLevel)*(_maxMagicDefense-_minMagicDefense)+_minMagicDefense); }

	int getNormalAttackArmor(){			return _headArmor->getNormalAttack()+_weaponArmor->getNormalAttack()+_chestArmor->getNormalAttack()+_legArmor->getNormalAttack()+_accArmor->getNormalAttack(); }
	int getNormalDefenseArmor(){		return _headArmor->getNormalDefense()+_weaponArmor->getNormalDefense()+_chestArmor->getNormalDefense()+_legArmor->getNormalDefense()+_accArmor->getNormalDefense(); }
	int getMagicAttackArmor(){			return _headArmor->getMagicAttack()+_weaponArmor->getMagicAttack()+_chestArmor->getMagicAttack()+_legArmor->getMagicAttack()+_accArmor->getMagicAttack(); }
	int getMagicDefenseArmor(){			return _headArmor->getMagicDefense()+_weaponArmor->getMagicDefense()+_chestArmor->getMagicDefense()+_legArmor->getMagicDefense()+_accArmor->getMagicDefense(); }
	int getSpeedArmor(){				return _headArmor->getSpeed()+_weaponArmor->getSpeed()+_chestArmor->getSpeed()+_legArmor->getSpeed()+_accArmor->getSpeed(); }

	int getNormalAttackTotal(){			return getNormalAttack()+_headArmor->getNormalAttack()+_weaponArmor->getNormalAttack()+_chestArmor->getNormalAttack()+_legArmor->getNormalAttack()+_accArmor->getNormalAttack(); }
	int getNormalDefenseTotal(){		return getNormalDefense()+_headArmor->getNormalDefense()+_weaponArmor->getNormalDefense()+_chestArmor->getNormalDefense()+_legArmor->getNormalDefense()+_accArmor->getNormalDefense(); }
	int getMagicAttackTotal(){			return getMagicAttack()+_headArmor->getMagicAttack()+_weaponArmor->getMagicAttack()+_chestArmor->getMagicAttack()+_legArmor->getMagicAttack()+_accArmor->getMagicAttack(); }
	int getMagicDefenseTotal(){			return getMagicDefense()+_headArmor->getMagicDefense()+_weaponArmor->getMagicDefense()+_chestArmor->getMagicDefense()+_legArmor->getMagicDefense()+_accArmor->getMagicDefense(); }
	int getSpeedTotal(){				return getSpeed()+_headArmor->getSpeed()+_weaponArmor->getSpeed()+_chestArmor->getSpeed()+_legArmor->getSpeed()+_accArmor->getSpeed(); }

	int getMaxNormalAttackDragoon(){	return _maxNormalAttackDragoon; }
	int getMaxNormalDefenseDragoon(){	return _maxNormalDefenseDragoon; }
	int getMaxMagicAttackDragoon(){		return _maxMagicAttackDragoon; }
	int getMaxMagicDefenseDragoon(){	return _maxMagicDefenseDragoon; }

	int getNormalAttackDragoon(){		return (int)(((float)_dragoonLevel/5.0f)*(_maxNormalAttackDragoon-100)+100); }
	int getNormalDefenseDragoon(){		return (int)(((float)_dragoonLevel/5.0f)*(_maxNormalDefenseDragoon-100)+100); }
	int getMagicAttackDragoon(){		return (int)(((float)_dragoonLevel/5.0f)*(_maxMagicAttackDragoon-100)+100); }
	int getMagicDefenseDragoon(){		return (int)(((float)_dragoonLevel/5.0f)*(_maxMagicDefenseDragoon-100)+100); }

	int getAttackHitArmor(){			return 100+_headArmor->getAttackHit()+_weaponArmor->getAttackHit()+_chestArmor->getAttackHit()+_legArmor->getAttackHit()+_accArmor->getAttackHit(); }
	int getMagicHitArmor(){				return 100+_headArmor->getMagicHit()+_weaponArmor->getMagicHit()+_chestArmor->getMagicHit()+_legArmor->getMagicHit()+_accArmor->getMagicHit(); }
	int getAttackEvasionArmor(){		return +_headArmor->getAttackEvasion()+_weaponArmor->getAttackEvasion()+_chestArmor->getAttackEvasion()+_legArmor->getAttackEvasion()+_accArmor->getAttackEvasion(); }
	int getMagicEvasionArmor(){			return +_headArmor->getMagicEvasion()+_weaponArmor->getMagicEvasion()+_chestArmor->getMagicEvasion()+_legArmor->getMagicEvasion()+_accArmor->getMagicEvasion(); }

	BaseArmor* getWeaponArmor(){		return _weaponArmor; }
	BaseArmor* getHeadArmor(){			return _headArmor; }
	BaseArmor* getChestArmor(){			return _chestArmor; }
	BaseArmor* getLegArmor(){			return _legArmor; }
	BaseArmor* getAccArmor(){			return _accArmor; }

	// Set Attributes
	void setLevel( int val ){				_level = val; }
	void setMaxLevel( int val ){			_maxLevel = val; }

	void setCurrentHP( int val ){			_currentHP = val; }
	void setMinHP( int val ){				_minHP = val; }
	void setMaxHP( int val ){				_maxHP = val; }

	void setCurrentMP( int val ){			_currentMP = val; }
	void setMinMP( int val ){				_minMP = val; }
	void setMaxMP( int val ){				_maxMP = val; }

	void setCurrentSP( int val ){			_currentSP = val; }

	void setCurrentXP( int val ){			_currentXP = val; }
	void setCurrentDLSP( int val ){			_currentDLSP = val; }
	void setDragoonLevel( int val ){		_dragoonLevel = val; }
	void setElement( const char* val ){		_element = val; }

	void setMinNormalAttack( int val ){		_minNormalAttack = val; }
	void setMaxNormalAttack( int val ){		_maxNormalAttack = val; }
	void setMinNormalDefense( int val ){	_minNormalDefense = val; }
	void setMaxNormalDefense( int val ){	_maxNormalDefense = val; }
	void setMinMagicAttack( int val ){		_minMagicAttack = val; }
	void setMaxMagicAttack( int val ){		_maxMagicAttack = val; }
	void setMinMagicDefense( int val ){		_minMagicDefense = val; }
	void setMaxMagicDefense( int val ){		_maxMagicDefense = val; }
	void setSpeed( int val ){				_speed = val; }
	
	void setMaxNormalAttackDragoon( int val ){		_maxNormalAttackDragoon = val; }
	void setMaxNormalDefenseDragoon( int val ){		_maxNormalDefenseDragoon = val; }
	void setMaxMagicAttackDragoon( int val ){		_maxMagicAttackDragoon = val; }
	void setMaxMagicDefenseDragoon( int val ){		_maxMagicDefenseDragoon = val; }

	void setWeaponArmor( BaseArmor* val ){			_weaponArmor = val; }
	void setHeadArmor( BaseArmor* val ){			_headArmor = val; }
	void setChestArmor( BaseArmor* val ){			_chestArmor = val; }
	void setLegArmor( BaseArmor* val ){				_legArmor = val; }
	void setAccArmor( BaseArmor* val ){				_accArmor = val; }
};


#endif 
