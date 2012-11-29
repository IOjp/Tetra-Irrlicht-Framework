/*
	-----------------------------------------
	Sound.h
	-----------------------------------------
*/

#ifndef _SOUND_H_
#define _SOUND_H_

#include <irrKlang.h>

// Sound Class
class Sound : public BaseAsset
{
private:

	// Sound
	irrklang::ISoundSource* _sound;

public:
	
	// Constructor
	Sound(const char* path, irrklang::ISoundSource* sound)
		: _sound(sound)
	{
		_path = path;
	}

	// Deconstructor
	~Sound(){}

	// Drop
	void drop(){
		if(_sound)
			_sound->drop();
	}

	// Get Asset
	irrklang::ISoundSource* getSound(){return _sound;}

	// Get Path
	const char* getPath(){ return _path; }
};


#endif 
