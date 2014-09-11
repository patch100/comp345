#include "include/SDL_surface.h"
#include "include/SDL.h"
#include <stdio.h>


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

	SDL_Delay( 5000 ); 

	return 0;

}
