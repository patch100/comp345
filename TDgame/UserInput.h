#ifndef USERINPUT_H
#define USERINPUT_H
#include "sdl.h"
#include "MapEditor.h"
class UserInput
{
public:

	
	MapEditor * mapEditor;
	

	UserInput();
	~UserInput();

	//User Input Mouse click for whether to do premade map, or make own map
	void mapEdit();

	//User Input Mouse click for clicking tiles to be turned into crittergrid from emptygrid;
	void gridSelect();



};

#endif