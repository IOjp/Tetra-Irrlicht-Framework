/*
	-----------------------------------------
	Font.h
	-----------------------------------------
*/

#ifndef _FONT_H_
#define _FONT_H_

#include <irrlicht.h>

// Font Class
class Font : public BaseAsset
{
private:

	// Attributes
	irr::gui::IGUIFont* _font;

public:
	
	// Constructor
	Font(const char* path, irr::gui::IGUIFont* font)
		: _font(font)
	{
		_path = path;
	}

	// Deconstructor
	~Font(){}

	// Get Attributes
	irr::gui::IGUIFont* getFont(){return _font;}

	// Get Path
	const char* getPath(){ return _path; }
};


#endif 
