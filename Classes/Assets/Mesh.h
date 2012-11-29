/*
	-----------------------------------------
	Mesh.h
	-----------------------------------------
*/

#ifndef _MESH_H_
#define _MESH_H_

#include <irrlicht.h>

// Mesh Class
class Mesh : public BaseAsset
{
private:

	// Attributes
	irr::scene::IAnimatedMesh* _mesh;

public:
	
	// Constructor
	Mesh(const char* path, irr::scene::IAnimatedMesh* mesh)
		: _mesh(mesh)
	{
		_path = path;
	}

	// Deconstructor
	~Mesh(){}

	// Get Attributes
	irr::scene::IAnimatedMesh* getMesh(){return _mesh;}

	// Get Path
	const char* getPath(){ return _path; }
};


#endif 
