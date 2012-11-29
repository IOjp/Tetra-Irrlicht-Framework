/*
	-----------------------------------------
	AssetContainer.h
	-----------------------------------------
*/

#ifndef _ASSETCONTAINER_H_
#define _ASSETCONTAINER_H_

#include <irrlicht.h>
#include <irrKlang.h>
#include <vector>
#include "Assets.h"

// Disable Warnings
#pragma warning (disable: 4018) // '<' : signed/unsigned mismatch

// Audio Manager Class
class AssetContainer
{
private:

	// Asset List
	std::vector<Sound*> _sounds;
	std::vector<Font*> _fonts;
	std::vector<Surface*> _surfaces;
	std::vector<Mesh*> _meshes;

public:
	
	// Constructor
	AssetContainer(){}

	// Deconstructor
	~AssetContainer(){}

	// Drop Assets
	void drop()
	{
		// Drop Sounds
		for(int i = 0; i < _sounds.size(); i++)
			_sounds[i]->drop();

		// Drop Meshes
		for(int i = 0; i < _meshes.size(); i++)
			_meshes[i]->drop();

		// The driver will automatically drop 
		// the remaing textures and fonts so no need
		// to call drop() on them.

		// Clear Lists
		_sounds.clear();
		_fonts.clear();
		_surfaces.clear();
		_meshes.clear();
	}

	// Get Assets
	irrklang::ISoundSource* getSound(int ind){return _sounds[ind]->getSound();}
	irr::video::ITexture* getSurface(int ind){return _surfaces[ind]->getTexture(); }
	irr::gui::IGUIFont* getFont(int ind){return _fonts[ind]->getFont(); }
	irr::scene::IAnimatedMesh* getMesh(int ind){return _meshes[ind]->getMesh(); }

	// Get Asset Vector
	std::vector<Sound*> getSounds(){return _sounds;}
	std::vector<Surface*> getSurfaces(){return _surfaces; }
	std::vector<Font*> getFonts(){return _fonts; }
	std::vector<Mesh*> getMeshes(){return _meshes; }

	// Add Assets
	int addSound(Sound* val)
	{
		_sounds.push_back(val);
		return _sounds.size()-1;
	}
	int addSurface(Surface* val)
	{
		_surfaces.push_back(val); 
		return _surfaces.size()-1;
	}
	int addFont(Font* val)
	{
		_fonts.push_back(val); 
		return _fonts.size()-1;
	}
	int addMesh(Mesh* val)
	{
		_meshes.push_back(val); 
		return _meshes.size()-1;
	}

	// Remove Assets
	void removeSound(int ref)
	{
		_sounds.erase(_sounds.begin() + ref);
	}
	void removeSurface(int ref)
	{
		_surfaces.erase(_surfaces.begin() + ref);
	}
	void removeFont(int ref)
	{
		_fonts.erase(_fonts.begin() + ref);
	}
	void removeMesh(int ref)
	{
		_meshes.erase(_meshes.begin() + ref);
	}
};


#endif 
