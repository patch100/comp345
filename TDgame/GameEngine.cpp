#include "GameEngine.h"





GameEngine::GameEngine(SDL_Renderer * renderer)
{
	this->renderer = renderer;
	this->menu = new Menu(renderer);
	//this->logic = new Logic();
	this->mapEditor = new MapEditor(renderer);
	
	this->userInput = new UserInput();
	this->renderObject = new RenderObject(renderer);
	//this->logic = new Logic();
	this->critterFactory = new CritterFactory();
	


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
		mapEditor->editGrid(0);

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

	menu->renderStartEnd();

	//Set starting and ending points
		switch (UserInput::mapEditorSelect(0))
		{
		case 1:

			mapEditor->editGrid(1);
			break;

		case 2:
			mapEditor->editGrid(2);
			break;
		}
		switch (UserInput::mapEditorSelect(0))
		{
		case 1:

			mapEditor->editGrid(1);
			break;

		case 2:
			mapEditor->editGrid(2);
			break;
		}
	
	//TESTING THE PATH;
	mapEditor->pathTest();

	//CREATE THE FINAL GRID;
	mapEditor->renderToTextureGrid();


	//FINISHED PREPARATION

	//GAME STARTS HERE

	startLevel();
	
	//Render to texture
	//mapEditor->completeGridRender();

	///START THE GAME!
}



void GameEngine::calculate()
{

	//HERE IS WHERE CRITTER FACTORY WOULD GO, DO AN IF to check if there are still any number of critters to be created


	//Moves the towers, moves the critters, move the projectiles, calculate everything. does a loop;
	//Iterates each object in the vectors, and calculates their movement

	//There's an issue how to pass the different arrays, because sometimes individual objects will need to iterate
	//through the array
	//maybe static pointers to the arrays?

	for (vector<Projectile>::iterator p = projectiles.begin(); p != projectiles.end(); ++p)
	{
		p->calculate();
	}

	for (vector<Critter>::iterator c = critters.begin(); c != critters.end(); ++c)
	{
		c->calculate();
	}

	for (vector<Tower>::iterator t = towers.begin(); t != towers.end(); ++t)
	{
		t->calculate();
	}


	//HERE IS WHERE TO HANDLE THE MOUSE CLICK EVENTS, LIKE BUYING TOWERS, SELLING TOWERS, ETC;


}

void GameEngine::render()
{
	//Render all the things, this is done after calculating;



}

void GameEngine::startLevel()
{
	//Set the level. Initalized at ZERO.
	currentLevel++;
	critterFactory->nextLevel();

	while (lives > 0)
	{
		frame();
	}

	//set timer;

	//Render Loop
	// Every render frame is is done in three things: 
	// A) The gameLogic calculates the change of movement of every tower, projectile, and critter
	// B) The gameLogic displays all the towers, projectiles, critters.
	// C) Any special mouse click events (buying new tower, etc)

	//SDL_Timer...
	//calculate();



	//When level is over

	endLevel();
}

void GameEngine::endLevel()
{

	//Delete all projectiles
	//Wait for Mouse Click Event to start level again;
}


void GameEngine::frame()
{
	// if there is no more lives, then end the game
	// if there is no more critters, the end the level endLevel();

	if (critterFactory->canCreate())
	{
		critters.push_back(critterFactory->createCritter());
	}

	calculate();
	render();





}
