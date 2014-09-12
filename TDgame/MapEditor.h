#pragma once
#include <grid.h>

class MapEditor
{
public:



	//Map editor would have two things, 1 a list of premade grids to choose from
	//2 the option to make their own grid, and then to pass that object.
	
	//either way, it has to first draw a grid, and then be made to pass these values into the logic object.
	//After that, it's useless.
	
	//we can use a public method "drawGrid" to draw the grid for both the map editor, as well as for the game itself;
	//it will take a grid.
	
	MapEditor();
	~MapEditor();
	
	
	void drawGrid(Grid grid);
};

