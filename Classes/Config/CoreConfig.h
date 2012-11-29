#pragma once

#include "../TinyXML/tinyxml.h"
#include <irrlicht.h>

// Namespaces
using namespace irr;

class CoreConfig
{
public:

	// De/Constructors
	CoreConfig(void);
	~CoreConfig(void);

	// Load Config
	void loadConfig(irr::core::stringc config_file);

	// Setting Properties
	bool fullScreen(void){return _fullscreen;}
	bool additive(void){return _additive;}
	bool vSync(void){return _vsync;}
	bool aA(void){return _aa;}
	video::E_DRIVER_TYPE driverType(void){return _driverType;}
	int resX(void){return _resx;}
	int resY(void){return _resy;}

private:

	// Settings
	bool _fullscreen;
	bool _additive;
	bool _vsync;
	bool _aa;
	video::E_DRIVER_TYPE _driverType;
	int _resx;
	int _resy;

};
