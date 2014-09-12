#pragma once
class MapEditor
{
public:



	//Map editor would have two things, 1 a list of premade grids to choose from
	//2 the option to make their own grid, and then to pass that object.
	
	//either way, it has to first draw a grid, and then be made to pass these values into the logic object.
	//After that, it's useless.
	
	//the method for drawing the grid for both the map editor and the game can be the same, but it's hard to think of how
	//to reuse that without creating a new class, which takes work...
	
	MapEditor();
	~MapEditor();
};

