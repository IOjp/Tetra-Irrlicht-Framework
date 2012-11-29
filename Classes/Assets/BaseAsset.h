/*
	-----------------------------------------
	BaseAsset.h
	-----------------------------------------
*/

#ifndef _BaseAsset_H_
#define _BaseAsset_H_

// Base Asset Class
class BaseAsset
{
protected:

	// Attributes
	const char* _path;

public:
	
	// Constructor
	BaseAsset()
		: _path("")
	{}

	// Drop
	virtual void drop(){}
};


#endif 