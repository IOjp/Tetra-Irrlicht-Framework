/*
	-----------------------------------------
	BaseMagic.h
	-----------------------------------------
*/

#ifndef _BaseMagic_H_
#define _BaseMagic_H_

// Base Magic Class
class BaseMagic
{
protected:

	// Name
	const char* _name;

public:

	// Constructor
	BaseMagic()
		: _name("N/A")
	{}

	// Deconstructor
	~BaseMagic(){}

	// Get Name
	const char* getName(){return _name;}
};


#endif 
