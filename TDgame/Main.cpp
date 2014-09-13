#include "include/SDL_surface.h"
#include "include/SDL.h"
#include <stdio.h>
#include "Logic.h"
#include "MapEditor.h"
#include "RenderObject.h"
#include "GameEngine.h"

namespace  start{
	SDL_Window * returnWindow(SDL_Window* win){
		return win;

	}
}
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


	///MOVING EVERYTHING DOWN TO GAMEENGINE
	GameEngine * gameEngine = new GameEngine(renderer);

	//GAMEENGINE PHASE1, which is RENDERING EVERYTHING (note, doing from .bmp or .png to surface takes time, this is why we need to render everything first)
	//GAMEENGINE PHASE2, which is map selection
	//GAMEENGINE PHASE3, which is the playing of the game
	//GAMENEGINE PHASE4, REPEAT, GAMEOVER, ETC;




	//Create a menu item, which holds all the menus, as well as text to render (tower info, etc)

	//Top menu bar
	//SDL_Surface * top_menu = SDL_LoadBMP("top_menu.bmp");
	//SDL_Texture * top_menu_texture = SDL_CreateTextureFromSurface(renderer,
		//top_menu);

	//SDL_FreeSurface(top_menu);

	//Render set up
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//SDL_RenderClear(renderer);



	//SDL_Rect dstrect1 = { 0,0, 884, 84 };

	//SDL_RenderCopy(renderer, top_menu_texture, NULL, &dstrect1);

	//Render once;
	//SDL_RenderPresent(renderer);



	//Create the map editor;


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

	

	quit = false;

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


	


	SDL_Quit();

	return 0;

}
