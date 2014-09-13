#include "MapEditor.h"


MapEditor::MapEditor(SDL_Window * window, SDL_Renderer * renderer)
{

	// HERE WE RENDER THE MAP. DO SOME POINTER LINKS

	this->window = window;
	this->renderer = renderer;

	// RENDER THE DIFFERENT OBJECTS;
	emptygrid = SDL_LoadBMP("emptygrid.bmp");
	emptygrid_texture = SDL_CreateTextureFromSurface(renderer,
		emptygrid);
	SDL_FreeSurface(emptygrid);
}


MapEditor::~MapEditor()
{
}

void MapEditor::drawGrid()
{
  // some code here that draws the grid onto the surface object, we will need to pass the surface too;
  // this can be reused of course;


	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	int x;
	int y;



	for (x = 0; x < 25; x++)
	{
		for (y = 0; y < 25; y++) {
			SDL_Rect dstrect = { x * GRID_SIDE + x + MAP_PADDING_LEFT, y* GRID_SIDE + y + MAP_PADDING_TOP, GRID_SIDE, GRID_SIDE };

			SDL_RenderCopy(renderer, emptygrid_texture, NULL, &dstrect);

		}
	};

	SDL_RenderPresent(renderer);
  
}
