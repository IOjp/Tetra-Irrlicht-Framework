/*
	-----------------------------------------
	BaseArmor.h
	-----------------------------------------
*/

#ifndef _BaseArmor_H_
#define _BaseArmor_H_

#include "../BaseIGContent.h"

// Base Armor Class
class BaseArmor : public BaseIGContent
{
protected:

	// Attributes,
	// These are the stats that imbue
	// onto the character when eqquiped
	int _normalAttack;
	int _magicAttack;
	int _normalDefense;
	int _magicDefense;
	int _speed;
	int _attackHit;
	int _magicHit;
	int _attackEvasion;
	int _magicEvasion;

	// Icon Reference
	int _row;
	int _col;

public:

	// Constructor
	BaseArmor(){}

	// Deconstructor
	~BaseArmor(){}

	// Get Attributes
	int getNormalAttack(){ return _normalAttack; }
	int getMagicAttack(){ return _magicAttack; }
	int getNormalDefense(){ return _normalDefense; }
	int getMagicDefense(){ return _magicDefense; }
	int getSpeed(){ return _speed; }
	int getAttackHit(){ return _attackHit; }
	int getMagicHit(){ return _magicHit; }
	int getAttackEvasion(){ return _attackEvasion; }
	int getMagicEvasion(){ return _magicEvasion; }
	int getRow(){ return _row; }
	int getCol(){ return _col; }

	// Set Attributes
	void setNormalAttack( int val ){  _normalAttack = val; }
	void setMagicAttack( int val ){ _magicAttack = val;  }
	void setNormalDefense( int val ){ _normalDefense = val;  }
	void setMagicDefense( int val ){ _magicDefense = val; }
	void setSpeed( int val ){ _speed = val; }
	void setAttackHit( int val ){ _attackHit = val; }
	void setMagicHit( int val ){ _magicHit = val; }
	void setAttackEvasion( int val ){ _attackEvasion = val; }
	void setMagicEvasion( int val ){ _magicEvasion = val; }
	void setRow( int val ){ _row = val; }
	void setCol( int val ){ _col = val; }

};


#endif 
