#include "CoreConfig.h"

CoreConfig::CoreConfig(void)
{
	// Settings
	_fullscreen = false;
	_additive = false;
	_vsync = false;
	_aa = false;
	_resx = 800;
	_resy = 600;

	// Get Default Video Driver
	#ifndef _IRR_WINDOWS_
	_driverType = video::EDT_OPENGL;
	#else
	_driverType = video::EDT_DIRECT3D9;
	#endif
}

CoreConfig::~CoreConfig(void)
{
}

// Load Config
void CoreConfig::loadConfig(irr::core::stringc config_file)
{
	try{
		// Create an XML Document Stream,
		// Loads the /Data/previews.dpr snapshot file
		TiXmlDocument tagDoc(config_file.c_str());
		
		// Check if XML Document Stream was created,
		// If not return.
		if (!tagDoc.LoadFile()) return;

		// Create Initial XML Document Fields
		TiXmlHandle hDoc(&tagDoc);
		TiXmlElement* pElem;
		TiXmlHandle hRoot(0);
		TiXmlElement* pElementNode;
		core::stringw str_val;

		// Get First Element
		pElem=hDoc.FirstChildElement().Element();

		// Check if Preview Element was created,
		// If not return.
		if (!pElem) return;

		// Get First Child
		TiXmlNode* pNode=pElem->FirstChild();

		// Get BasicInfo Element Node
		pElementNode = pNode->ToElement();

		// Set Data
		pElementNode->QueryIntAttribute("res_x", &_resx);
		pElementNode->QueryIntAttribute("res_y", &_resy);

		str_val = pElementNode->Attribute( "add" );
		if(str_val == "true")
			_additive = true;
		else
			_additive = false;

		str_val = pElementNode->Attribute( "fs" );
		if(str_val == "true")
			_fullscreen = true;
		else
			_fullscreen = false;

		str_val = pElementNode->Attribute( "aa" );
		if(str_val == "true")
			_aa = true;
		else
			_aa = false;

		str_val = pElementNode->Attribute( "vsync" );
		if(str_val == "true")
			_vsync = true;
		else
			_vsync = false;

		str_val = pElementNode->Attribute( "driver" );
		if(str_val == "dx9")
			_driverType = video::EDT_DIRECT3D9;
		else if(str_val == "dx8")
			_driverType = video::EDT_DIRECT3D8;
		else if(str_val == "gl")
			_driverType = video::EDT_OPENGL;
		else if(str_val == "sw")
			_driverType = video::EDT_SOFTWARE;
		else if(str_val == "bv")
			_driverType = video::EDT_BURNINGSVIDEO;
		else if(str_val == "null")
			_driverType = video::EDT_NULL;

		// Clear XML Document Cache
		tagDoc.Clear();

	}
	catch(std::exception& e)
    {
		fprintf(stderr, "An exception has occurred: %s\n", e.what());
    }
}
