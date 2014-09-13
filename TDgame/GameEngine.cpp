#include "GameEngine.h"





GameEngine::GameEngine(SDL_Renderer * renderer)
{
	this->renderer = renderer;
	this->menu = new Menu(renderer);

	this->mapEditor = new MapEditor(renderer);

	this->userInput = new UserInput();
	this->renderObject = new RenderObject(renderer);
	//this->logic = new Logic();

	renderObject->setRenderer();
	menu->renderMenu();
	mapEditor->drawGrid();
	renderObject->renderFrame();

}


