

#include "include/SDL_surface.h"
#include "include/SDL.h"
#include <stdio.h>
#include <iostream>
#include "GameEngine.h"
#include "GUI.h"

namespace  start{
	SDL_Window * returnWindow(SDL_Window* win){
		return win;

	}
}
int main(int argc, char* args[])
{

	using namespace GUI;
	// init SDL

	//WINDOW SIZE

	//INITALIZING
	SDL_Init(SDL_INIT_VIDEO);

	//WINDOW WILL BE THE DRAWING SURFACE;
	SDL_Window * window = SDL_CreateWindow("Tower Defense",	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	
	//RENDERER is what makes images;
	SDL_Renderer * renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);
	
	
	///MOVING EVERYTHING DOWN TO GAMEENGINE
	GameEngine * gameEngine = new GameEngine(renderer);

	//Note: rendering of all the images needed for the game is done when each object in gameEngine is created

	//GAMEENGINE PHASE1, which is map selection
	//GAMEENGINE PHASE2, which is the playing of the game
	//GAMENEGINE PHASE3, REPEAT, GAMEOVER, ETC;
	SDL_Delay(5000);
	SDL_Quit();

	return 0;

}
