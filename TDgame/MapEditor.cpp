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

	testgrid = SDL_LoadBMP("graphics/testgrid.bmp");
	testgrid_texture = SDL_CreateTextureFromSurface(renderer,
		testgrid);

	SDL_FreeSurface(testgrid);






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

void MapEditor::editGrid(int flag)
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

			//depends on flag, click grid to set start point
			if (flag == 1)
			{
				startX = (int)gridX;
				startY = (int)gridY;
				//end loop
				test = true;
			}

			// click grid to set end point
			else if (flag == 2)
			{
				endX = (int)gridX;
				endY = (int)gridY;
				//end loop
				test = true;
			}
			// click grid multiple times to set
			else {
				int mapX = (int)gridX;
				int mapY = (int)gridY;
				if (mapX < ROW_SIZE && mapY < COLUMN_SIZE && mapX > -1 && mapY > -1 && event.motion.y > MAP_PADDING_TOP - 1)
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

bool MapEditor::pathFinder()
{
	using namespace GUI;
	//checks all four values are assigned.
	//false return means it loops again
	if (startX == 0) return false;

	else if (startX == 0) return false;

	else if (endX == 0) return false;

	else if (endY == 0) return false;

	else return true;

	return true;
	//true value means critters are allowed to walk
	//checks if both start and end are critter grids
	//else if (!mapgrid[startX][startY]) return false;
	//else if (!mapgrid[endX][endY]) return false;
	//path should be less than 200 grid spaces from start to end, arbitrary
}

void MapEditor::pathTest(){

	int step = 0;
	using namespace GUI;

	//new x, new y
	int testX = startX;
	int testY = startY;
	


	//if path needs to change
	bool blocked = false;

	int dirX;
	int dirY;
	//DEFINE DIRECTION
	//NORTH, dirY = -1, dirX = 0;
	//EAST dirX = 1, dirY = 0;
	//SOUTH dirX = 0, dirY = 1;
	//WEST dirX = -1, dirY = 0;

	bool testgrid[25][25];

	for (int i = 0; i < ROW_SIZE; i++){

		for (int u = 0; u < COLUMN_SIZE; u++){

			testgrid[i][u] = mapgrid[i][u];
		}
	}

	dirX = 1;
	dirY = 0;
	while (step < 250 && !(testX == 24) ){

		
		//LEFT TOP OUTER CORNER/RIGHT BOTTOM OUTER CORNER
		if (testgrid[testX][testY] && testX > 0 && testX < 24 && testY > 0 && testY < 24){

			if (!testgrid[testX - 1][testY - 1] && !testgrid[testX + 1][testY + 1])

			{

				int temp = dirX;
				dirX = 1 * (dirY);
				dirY = 1 * (temp);

			}

			////RIGHT TOP OUTER CORNER/LEFT BOTTOM OUTER CORNER
			else if (!testgrid[testX + 1][testY - 1] && !testgrid[testX - 1][testY + 1])

			{
				int temp = dirX;
				dirX = -1 * (dirY);
				dirY = -1 * (temp);


			}

			//LEFT TOP INNER CORNER, same as LEFT TOP OUTER CORNER;
			else if ((testX - 2 > -1) && (testX + 1 < 25) && (testY - 2 > -1) && (testY + 1 < 25) && 
				!testgrid[testX + 1][testY + 1] && !testgrid[testX - 2][testY] && !(testgrid[testX][testY - 2])
				
				){
				int temp = dirX;
				dirX = -1 * (dirY);
				dirY = -1 * (temp);
			}

			//RIGHT BOTTOM INNER CORNER, same as RIGHT BOTTOM OUTER
			else if ((testX - 1 > -1) && (testX + 2 < 25) && (testY - 1 > -1) && (testY + 2 < 25)
				&& !testgrid[testX - 1][testY - 1] && !testgrid[testX + 2][testY] && !(testgrid[testX][testY + 2])
				
				){
				int temp = dirX;
				dirX = -1 * (dirY);
				dirY = -1 * (temp);
			}

			//RIGHT TOP INNER, same as RIGHT TOP OUTER
			else if ((testX - 1 > -1) && (testX + 2 < 25) && (testY - 2 > -1) && (testY + 1 < 25) &&
				!testgrid[testX - 1][testY + 1] && !testgrid[testX + 2][testY] && !(testgrid[testX][testY - 2])
				
				){

				int temp = dirX;

				dirX = 1 * (dirY);
				dirY = 1 * (temp);
			}

			//LEFT BOTTOM INNER, same as LEFT BOTTOM OUTER
			else if ((testX - 2 > -1) && (testX + 1 < 25) && (testY - 1 > -1) && (testY + 2 < 25) &&
				!testgrid[testX + 1][testY - 1] && !testgrid[testX - 2][testY] && !(testgrid[testX][testY + 2])
				
				){
				int temp = dirX;
				dirX = 1 * (dirY);
				dirY = 1 * (temp);
			}
		}
			testX = testX + dirX;
			testY = testY + dirY;
			SDL_Rect grid_new = { testX * GRID_SIDE + testX + MAP_PADDING_LEFT, testY* GRID_SIDE + testY + MAP_PADDING_TOP, GRID_SIDE, GRID_SIDE };
			SDL_RenderCopy(renderer, testgrid_texture, NULL, &grid_new);
			SDL_RenderPresent(renderer);
			step++;


			SDL_Delay(250);
		
	}

	return;
}

void MapEditor::renderToTextureGrid()
{


	rendered_grid_rect = { 0, 0, 1000, 800 };
	rendered_grid = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1000, 800);
	SDL_SetTextureBlendMode(rendered_grid, SDL_BLENDMODE_BLEND);


	SDL_SetRenderTarget(renderer, rendered_grid);
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

	SDL_SetRenderTarget(renderer, NULL);
}

void MapEditor::renderGrid()
{
	SDL_RenderCopy(renderer, rendered_grid, NULL, &rendered_grid_rect);



}