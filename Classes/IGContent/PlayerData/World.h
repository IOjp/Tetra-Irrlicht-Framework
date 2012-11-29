/*
	-----------------------------------------
	World.h
	-----------------------------------------
*/

#ifndef _WORLD_H_
#define _WORLD_H_

// World Class
class World
{
private:

	// Chapter
	const char* _chapter;
	const char* _area;

public:

	// Constructor
	World()
		: _chapter("Ch. 1 Starting Out"), _area("First Area")
	{}

	// Deconstructor
	~World(){}

	// Get Variables
	const char* getChapter(){ return _chapter;}
	const char* getArea(){ return _area;}

	// Set Variables
	void setChapter(const char* val){ _chapter=val;}
	void setArea(const char* val){_area=val;}
};


#endif 
