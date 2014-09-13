#pragma once
#include "grid.h"
#include "include/SDL.h"
#include "include/SDL_surface.h"
class MapEditor
{
public:

	bool mapgrid[25][25];

	//CONSTANTS, VALUES IN PIXELS, FORMATTING AND SIZE

	const int MAP_PADDING_LEFT = 10;

	const int MAP_PADDING_TOP = 100;

	const int GRID_SIDE = 25;

	//MAP GRID SIZE
	const int ROW_SIZE = 25;

	const int COLUMN_SIZE = 25;

	//Every image needs a surface to load the image, and then a texture, which is the image rendered.
	//So we need one for empty grid (towers only), and critter grid
	SDL_Surface * emptygrid;
	SDL_Texture * emptygrid_texture;

	SDL_Surface * crittergrid;
	SDL_Texture * crittergrid_texture;


	SDL_Renderer * renderer;

	//the grid object;
	Grid * gridObject;

	//Map editor would have two things, 1 a list of premade grids to choose from
	//2 the option to make their own grid, and then to pass that object.
	
	//either way, it has to first draw a grid, and then be made to pass these values into the logic object.
	//After that, it's useless.
	
	//we can use a public method "drawGrid" to draw the grid for both the map editor, as well as for the game itself;
	//it will take a grid.
	
	MapEditor(SDL_Renderer * renderer);
	~MapEditor();
	
	
	void drawGrid();




};

