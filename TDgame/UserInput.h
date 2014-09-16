#ifndef USERINPUT_H
#define USERINPUT_H
#include "sdl.h"
#include "MapEditor.h"
class UserInput
{
public:

	
	//MapEditor * mapEditor;
	

	UserInput();
	~UserInput();

	//User Input Mouse click for whether to do premade map, or make own map
	static int mapEditorSelect(int flag);


};

#endif