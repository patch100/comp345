#ifndef USERINPUT_H
#define USERINPUT_H
#include "sdl.h"
class UserInput
{
public:

	SDL_Event * event;

	UserInput();
	~UserInput();

	//User Input Mouse click for whether to do premade map, or make own map
	void mapEditor();

	//User Input Mouse click for clicking tiles to be turned into crittergrid from emptygrid;
	void gridSelect();



};

#endif