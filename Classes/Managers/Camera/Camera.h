/*
	-----------------------------------------
	Camera.h
	-----------------------------------------
*/

#ifndef _CAMERA_H_
#define _CAMERA_H_

// Camera Class
class Camera
{
private:

	// CoreApp
	CoreApp* _coreApp;

	// Camera
	irr::scene::ICameraSceneNode* _camera;

public:
	
	// Constructor
	Camera(CoreApp* coreApp)
		: _coreApp(coreApp)
	{}

	// Deconstructor
	~Camera(){}

	// Get Camera 
	irr::scene::ICameraSceneNode* getCamera(){ return _camera; }

	// Initialize Camera
	void init()
	{
		_camera = _coreApp->getGameManager()->getSceneManager()->addCameraSceneNodeFPS(0, 100.0f, .3f, -1, 0, 0, true, 3.f);
		_camera->setPosition(irr::core::vector3df(50,50,-60));
        _camera->setTarget(irr::core::vector3df(-70,30,-60));
	}

};


#endif 