/*
	-----------------------------------------
	BaseAddition.h
	-----------------------------------------
*/

#ifndef _BaseAddition_H_
#define _BaseAddition_H_

// Base Addition Class
class BaseAddition
{
protected:

	// Name
	const char* _name;

public:

	// Constructor
	BaseAddition()
		: _name("N/A")
	{}

	// Deconstructor
	~BaseAddition(){}

	// Get Name
	const char* getName(){ return _name; }
};


#endif 
