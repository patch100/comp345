#include "include/SDL_surface.h"
#include "include/SDL.h"
#include <stdio.h>
#include "Logic.h"
#include "MapEditor.h"

int main(int argc, char* args[])
{


	// init SDL

	//WINDOW SIZE
	const int SCREEN_WIDTH = 1000;
	const int SCREEN_HEIGHT = 800;

	//INITALIZING
	SDL_Init(SDL_INIT_VIDEO);

	//WINDOW WILL BE THE DRAWING SURFACE;
	SDL_Window * window = SDL_CreateWindow("Tower Defense",	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	//RENDERER is what makes images;
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface * top_menu = SDL_LoadBMP("top_menu.bmp");
	SDL_Texture * top_menu_texture = SDL_CreateTextureFromSurface(renderer,
		top_menu);

	SDL_FreeSurface(top_menu);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	SDL_Rect dstrect1 = { 0,0, 884, 84 };

	SDL_RenderCopy(renderer, top_menu_texture, NULL, &dstrect1);
	SDL_RenderPresent(renderer);

	//Create the map editor;
	MapEditor mapEditor(window, renderer);

	//HERE WE INSERT A SDL_EVENT, SO YOU HAVE TO PICK BETWEEN PRESELECTED, OR READY MADE;
	//EVENT IS BASED ON MOUSE BUTTON X/Y POS; 
	//FROM THAT POINT, WE CAN PICK EITHER TO JUST GO ON TO THE GAME, OR LET THEM PICK THE MAP;

	SDL_Event event;
	bool quit = false;
	
	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_KEYDOWN:
			quit = true;
			break;
		}

	}


	mapEditor.drawGrid();





	//SDL_Surface * image = SDL_LoadBMP("spaceship.bmp");
	//SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
		//image);
	
	

	//SDL_Texture * overlap = SDL_CreateTextureFromSurface(renderer,		image);

	//SDL_FreeSurface(image);

	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// handle events

	
	// cleanup SDL

	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	// Application Window
	//SDL_Window* window = NULL; 

	// Drawing Surface
	//SDL_Surface* screen = NULL; 

	//const int WIDTH = 1000;
	//const int HEIGHT = 750;
	// Creating Window, set size
	//window = SDL_CreateWindow("Tower Defense Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		//WIDTH, HEIGHT, SDL_WINDOW_SHOWN); 

	//creating a renderer to test
	//SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	//SDL_Surface * image = SDL_LoadBMP("spaceship.png");
	//SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,		image);

	//SDL_FreeSurface(image);

	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//SDL_Rect dstrect = { 10, 10, 64, 64 };

	//SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	//SDL_RenderPresent(renderer);

	// Adding surface to window
	//screen = SDL_GetWindowSurface( window ); 
	
	//Check 1
	//Will need multiple SDL_Surface objects, each for each selection of the screen (2 at least)
	
	//Select Premade Map OR Create New Map (Load MapEditor);
	
	//Might have to pass the surface to draw on to creating the mapEditor()
	
	//MapEditor mapEditor();
	//mapEditor.drawGrid();
	//Wait for mouse click events, once the mouse click events are finished, and the grid is selected
	// either by preselection, or creation, the mapEditor object will have the information we need;
	

	//OLD:

	//int ** grid; // Place holders
	//int startRow;
	//int startColumn;
	//int endRow;
	//int endColumn;

	//Create Logic that handles the towers, projectiles, levels, etc.
	//Pass map information over: actually, we can just let the logic object accept a grid instead of these variables;
	//Logic gameLogic(grid, startRow, startColumn, endRow, endColumn); BAD
	
	//NEW: 
	
	//selectMap will return a Grid object;
	//Logic gamelogic(mapEditor.selectMap(), pass the surface to draw on);
	//Mouse Event to start
	
	
	//Game Starts. Allow for pausing at the end of every level;

	//End Game WIN, LOSE, TRY AGAIN?

	//Please read the critter,tower,projectile, logic .h and .cpp files


	
	//SDL_DestroyTexture(texture);
	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyWindow(window);
	//SDL_Quit();
	return 0;

}
