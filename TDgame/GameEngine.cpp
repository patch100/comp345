#include "GameEngine.h"





GameEngine::GameEngine(SDL_Renderer * renderer)
{
	this->renderer = renderer;
	menu = new Menu(renderer);
	mapEditor = new MapEditor(renderer);
	userInput = new UserInput();
	renderObject = new RenderObject(renderer);



}


