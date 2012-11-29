/*
	-----------------------------------------
	BaseGood.h
	-----------------------------------------
*/

#ifndef _BaseGood_H_
#define _BaseGood_H_

// Base Good Class
class BaseGood
{
protected:

	// Name
	const char* _name;

public:

	// Constructor
	BaseGood()
		: _name("N/A")
	{}

	// Deconstructor
	~BaseGood(){}

	// Get Name
	const char* getName(){return _name;}

};


#endif 
