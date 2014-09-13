#include "MapEditor.h"
#include "Grid.h"
#include "GameEngine.h"
MapEditor::MapEditor(SDL_Renderer * renderer)
{

	this->renderer = renderer;
	//Grid Object. To be passed to Logic Object when the game begins;
	//gridObject = new Grid(ROW_SIZE, COLUMN_SIZE);

	// Tower Only Grid Render
	emptygrid = SDL_LoadBMP("emptygrid.bmp");
	emptygrid_texture = SDL_CreateTextureFromSurface(renderer,
		emptygrid);
	SDL_FreeSurface(emptygrid);
	
	// Critter Only Grid Render
	crittergrid = SDL_LoadBMP("crittergrid.bmp");
	crittergrid_texture = SDL_CreateTextureFromSurface(renderer,
		crittergrid);

	SDL_FreeSurface(crittergrid);






}


MapEditor::~MapEditor()
{
}

void MapEditor::drawGrid()
{
  // some code here that draws the grid onto the surface object, we will need to pass the surface too;
  // this can be reused of course;

	mapgrid[0][0] = true;
	mapgrid[1][1] = true;

	int x;
	int y;

	for (x = 0; x < ROW_SIZE; x++)
	{
		for (y = 0; y < COLUMN_SIZE; y++) {
			SDL_Rect grid_rect = { x * GRID_SIDE + x + MAP_PADDING_LEFT, y* GRID_SIDE + y + MAP_PADDING_TOP, GRID_SIDE, GRID_SIDE };

			//gridObject decides whether cells are "emptygrid" or "crittergrid"
			//boolean values
			
			if (!mapgrid[x][y]){

				SDL_RenderCopy(renderer, emptygrid_texture, NULL, &grid_rect);
			}
			
			else 
				if (mapgrid[x][y])
				SDL_RenderCopy(renderer, crittergrid_texture, NULL, &grid_rect);

		}
	};










	
  
}
