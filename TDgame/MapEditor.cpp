#include "MapEditor.h"
#include "Grid.h"
#include "GameEngine.h"

MapEditor::MapEditor(SDL_Renderer * renderer)
{

	this->renderer = renderer;
	//Grid Object. To be passed to Logic Object when the game begins;
	//gridObject = new Grid(ROW_SIZE, COLUMN_SIZE);

	// Tower Only Grid Render
	emptygrid = SDL_LoadBMP("graphics/emptygrid.bmp");
	emptygrid_texture = SDL_CreateTextureFromSurface(renderer,
		emptygrid);
	SDL_FreeSurface(emptygrid);
	
	// Critter Only Grid Render
	crittergrid = SDL_LoadBMP("graphics/crittergrid.bmp");
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

	using namespace GUI;
	
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

	SDL_RenderPresent(renderer);
}

void MapEditor::editGrid()
{	
	using namespace GUI;

	bool test = false;

	SDL_Event event;

	while (!test)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_MOUSEBUTTONDOWN:

			double gridX = (event.motion.x - MAP_PADDING_LEFT) / (1 + GRID_SIDE) / 1;
			double gridY = (event.motion.y - MAP_PADDING_TOP) / (1 + GRID_SIDE) / 1;

			int mapX = gridX;
			int mapY = gridY;
			if (mapX < ROW_SIZE && mapY < COLUMN_SIZE && mapX > -1 && mapY > -1 && event.motion.y > MAP_PADDING_TOP-1)
			{
				mapgrid[mapX][mapY] = !mapgrid[mapX][mapY];

				SDL_Rect grid_new = { mapX * GRID_SIDE + mapX + MAP_PADDING_LEFT, mapY* GRID_SIDE + mapY + MAP_PADDING_TOP, GRID_SIDE, GRID_SIDE };
				if (!mapgrid[mapX][mapY])
				{

					SDL_RenderCopy(renderer, emptygrid_texture, NULL, &grid_new);
				}

				else if (mapgrid[mapX][mapY])
					SDL_RenderCopy(renderer, crittergrid_texture, NULL, &grid_new);


				SDL_RenderPresent(renderer);
				

			}
			else test = true;





		}


	}
			

}



//This creates load premade map to file. Just to see if it works;
//No longer needed;
void MapEditor::makePremade()
{
	using namespace GUI;
	fstream outstream;

	outstream.open("map1.txt", ios::out);

	for (int i = 0; i < ROW_SIZE; i++)
	{

		for (int u = 0; u < COLUMN_SIZE; u++)

		{
			if (mapgrid[i][u])
				outstream << 'T';
			else outstream << 'F';

		}
	}
}


//Load premade from file;
void MapEditor::loadPremade()
{
	using namespace std;
	using namespace GUI;

	fstream instream;

	//Switch statement;
	switch (UserInput::mapEditorSelect(1)){
	case 1:
		instream.open("map1.txt", ios::in);
		break;
	case 2:
		instream.open("map2.txt", ios::in);
		break;
	case 3:
		instream.open("map3.txt", ios::in);
		break;
	}

	for (int i = 0; i < ROW_SIZE; i++){

		for (int u = 0; u < COLUMN_SIZE; u++)

		{
			if (instream.get() == 'T')
				mapgrid[i][u] = true;
			else mapgrid[i][u] = false;

		}
	}

	
	//LOAD THE MAP
	
}