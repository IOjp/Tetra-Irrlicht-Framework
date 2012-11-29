/*
	-----------------------------------------
	Surface.h
	-----------------------------------------
*/

#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <irrlicht.h>

// Surface Class
class Surface : public BaseAsset
{
private:

	// Attributes
	irr::video::ITexture* _texture;

public:
	
	// Constructor
	Surface(const char* path, irr::video::ITexture* texture)
		: _texture(texture)
	{
		_path = path;
	}

	// Deconstructor
	~Surface(){}

	// Get Attributes
	irr::video::ITexture* getTexture(){return _texture;}

	// Get Path
	const char* getPath(){ return _path; }
};


#endif 
