#pragma once
class UserInput
{
public:
	UserInput();
	~UserInput();

	//User Input Mouse click for whether to do premade map, or make own map
	void mapEditor();

	//User Input Mouse click for clicking tiles to be turned into crittergrid from emptygrid;
	void gridSelect();
};

