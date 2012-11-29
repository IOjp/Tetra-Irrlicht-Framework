/*
	-----------------------------------------
	BaseIGContent.h
	-----------------------------------------
*/

#ifndef _BaseIGContent_H_
#define _BaseIGContent_H_

// Base IGContent Class
class BaseIGContent
{
protected:

	// Declarations
	const char* _name;
	const char* _description;

public:

	// Constructor
	BaseIGContent()
		: _name("N/A"), _description("N/A")
	{}

	// Deconstructor
	~BaseIGContent(){}

	// Get Attributes
	const char* getName(){return _name;}
	const char* getDescription(){return _description;}

	// Set Attributes
	void setName( const char* val ){ _name = val; }
	void setDescription( const char* val ){ _description = val; }
};


#endif 
