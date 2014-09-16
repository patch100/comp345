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

	//Renders basic menu and default grid
	menu->renderMenu();
	mapEditor->drawGrid();
	
	//Here input the userinput option, for the user to decide between picking one map or another map;
	
	//Phase 1, user decides between loading a premade map, or editting their own map
	menu->renderEditOrPremade();
	switch (UserInput::mapEditorSelect(0))
	{

	case 1:

		//menu loads a "finished" button

		//Edit their own map
		mapEditor->editGrid();

		//Turn map into file. Not used.
		//mapEditor->makePremade();
		break;

	case 2:
		
		//menu loads options;
		menu->renderPremadeMapSelection();
		//Load premade map from map folder
		mapEditor->loadPremade();
		//draw premade map;
		mapEditor->drawGrid();
	}

	//Set starting and ending points

	//Render to texture
	//mapEditor->completeGridRender();

	///START THE GAME!
}


