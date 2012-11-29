/*
	-----------------------------------------
	AudioManager.h
	-----------------------------------------
*/

#ifndef _AUDIOMANAGER_H_
#define _AUDIOMANAGER_H_

#include <irrKlang.h>

// Audio Manager Class
class AudioManager
{
private:

	// Sound Engine
	irrklang::ISoundEngine* _soundEngine;

public:
	
	// Constructor
	AudioManager(){

		// Create Device
		_soundEngine = irrklang::createIrrKlangDevice();

		// Return
		if (!_soundEngine)
			return;
	}

	// Deconstructor
	~AudioManager(){

		// Clean Up
		if (_soundEngine)
			_soundEngine->drop();
	}

	// Get Sound Engine
	irrklang::ISoundEngine* getSoundEngine(){return _soundEngine;}

};


#endif 
