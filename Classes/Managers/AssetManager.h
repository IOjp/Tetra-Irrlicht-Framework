/*
	-----------------------------------------
	AssetManager.h
	-----------------------------------------
*/

#ifndef _ASSETMANAGER_H_
#define _ASSETMANAGER_H_

// Disable Warnings
#pragma warning (disable: 4018) // '<' : signed/unsigned mismatch

#include <irrlicht.h>
#include <irrKlang.h>
#include <vector>
#include "../Assets/AssetContainer.h"
#include "AudioManager.h"
#include "GameManager.h"

// Asset Manager Class
class AssetManager
{
private:

	// Asset Container
	AssetContainer* _assetContainer;

public:
	
	// Constructor
	AssetManager()
		: _assetContainer(0)
	{}

	// Deconstructor
	~AssetManager(){}

	// Create a Container
	void createContainer()
	{ 
		_assetContainer = new AssetContainer();
	}

	// Get Current Container
	AssetContainer* getContainer()
	{ 
		return _assetContainer;
	}

	// Drop Container
	void dropContainer()
	{
		_assetContainer->drop();
	}

	// Look For Assets
	int findSound(const char* path)
	{
		for(int n=0; n<_assetContainer->getSounds().size(); n++)
			if(_assetContainer->getSounds()[n]->getPath() == path)
				return n;
		return -1;
	}
	int findSurface(const char* path)
	{
		for(int n=0; n<_assetContainer->getSurfaces().size(); n++)
			if(_assetContainer->getSurfaces()[n]->getPath() == path)
				return n;
		return -1;
	}
	int findFont(const char* path)
	{
		for(int n=0; n<_assetContainer->getFonts().size(); n++)
			if(_assetContainer->getFonts()[n]->getPath() == path)
				return n;
		return -1;
	}
	int findMesh(const char* path)
	{
		for(int n=0; n<_assetContainer->getMeshes().size(); n++)
			if(_assetContainer->getMeshes()[n]->getPath() == path)
				return n;
		return -1;
	}


	// Create Assets
	int createSound(const char* path, GameManager* game_manager, AudioManager* audio_manager)
	{  
		if(findSound(path) == -1)
			return _assetContainer->addSound(new Sound(path, audio_manager->getSoundEngine()->addSoundSourceFromFile(path))); 
		else
			return findSound(path);
	}
	int createFont(const char* path, GameManager* game_manager)
	{  
		if(findFont(path) == -1)
			return _assetContainer->addFont(new Font(path, game_manager->getDevice()->getGUIEnvironment()->getFont(game_manager->getContentDirectory()+"/Fonts/"+path))); 
		else
			return findFont(path);
	}
	int createSurface(const char* path, GameManager* game_manager)
	{ 
		if(findSurface(path) == -1)
			return _assetContainer->addSurface(new Surface(path, game_manager->getDriver()->getTexture(game_manager->getContentDirectory()+"/Textures/"+path))); 
		else
			return findSurface(path);
	}
	int createMesh(const char* path, GameManager* game_manager)
	{ 
		if(findMesh(path) == -1)
			return _assetContainer->addMesh(new Mesh(path, game_manager->getSceneManager()->getMesh(game_manager->getContentDirectory()+"/Meshes/"+path))); 
		else
			return findMesh(path);
	}

	// Drop Assets
	void dropSound(int ref)
	{  
		_assetContainer->getSound(ref)->drop();	
		_assetContainer->getSounds().erase(
		_assetContainer->getSounds().begin() + ref);
	}
	void dropFont(int ref, GameManager* game_manager)
	{ 
		/* No method to drop fonts yet */
	}
	void dropSurface(int ref, GameManager* game_manager)
	{ 
		game_manager->getDriver()->removeTexture(_assetContainer->getSurface(ref));
		_assetContainer->removeSurface(ref);
	}
	void dropMesh(int ref, GameManager* game_manager)
	{ 
		_assetContainer->removeMesh(ref);
	}
};


#endif 