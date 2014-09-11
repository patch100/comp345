#include "include/SDL_surface.h"
#include "include/SDL.h"
#include <stdio.h>
#include "Logic.h"


int main(int argc, char* args[])
{

	// Application Window
	SDL_Window* window = NULL; 

	// Drawing Surface
	SDL_Surface* screen = NULL; 

	const int WIDTH = 1000;
	const int HEIGHT = 750;
	// Creating Window, set size
	window = SDL_CreateWindow("Tower Defense Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		WIDTH, HEIGHT, SDL_WINDOW_SHOWN); 

	// Adding surface to window
	screen = SDL_GetWindowSurface( window ); 

	//Select Premade Map OR Create New Map (Load MapEditor);
	//Either way, end with an double array, an X,Y for the start, and X,Y for the end (by grid, not by pixel), we pass this into the gameLogic.
	//Also need a path finding algorithm
	//Close MapEditor, start setting up the game;

	//int ** grid; // Place holders
	//int startRow;
	//int startColumn;
	//int endRow;
	//int endColumn;

	//Create Logic that handles the towers, projectiles, levels, etc.
	//Pass map information over:
	//		Logic gameLogic(grid, startRow, startColumn, endRow, endColumn);

	//Mouse Event to start
	//Game Starts. Allow for pausing at the end of every level;

	//End Game WIN, LOSE, TRY AGAIN?

	//Please read the critter,tower,projectile, logic .h and .cpp files


	SDL_Delay( 5000 ); 

	return 0;

}
