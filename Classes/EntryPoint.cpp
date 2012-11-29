/*
	Tetra Irrlicht 0.0.3
	- Irrlicht Framework -
	First Demo Application Draft (2009)
	-----------------------------------------
	Credits:
	- REMOVED -
	-----------------------------------------
	Initial Framework developed under 
	supervision of IOjp Software
	-----------------------------------------
	Disclaimer:            
	- REMOVED -
	-----------------------------------------
	EntryPoint.cpp
	The Application's Entry Point
	-----------------------------------------
*/

//!  \file The Application's Entry Point 

// Includes
#include <irrlicht.h>
#include "Core/CoreApp.h"
#include "Config/CoreConfig.h"
#ifdef _IRR_WINDOWS_
#include <windows.h>
#pragma comment (lib, "irrKlang.lib")
#endif

// Namespaces
using namespace irr;

// Main Entry Point
#ifdef _WIN32
#pragma comment(lib, "Irrlicht.lib")
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
int main(int argc, char* argv[])
#endif
{
	// Setup Try/Catch Block
	try
    {
		// Config Settings
		CoreConfig* config = new CoreConfig();
		config->loadConfig("..\\Content\\Data\\Config.dpr");

		// Create Core Application
		CoreApp _coreApplication(
			config->fullScreen(), 
			config->additive(), 
			config->vSync(), 
			config->aA(), 
			config->driverType(),
			config->resX(),
			config->resY());

		// Run Core Application
		_coreApplication.run();
    }
	catch(std::exception& e)
    {
		fprintf(stderr, "An exception has occurred: %s\n", e.what());
    }

	// Return, Exit Application
	return 0;
}

