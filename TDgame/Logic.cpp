#include "Logic.h"


Logic::Logic()
{
	//All Bitmaps will be in the Logic();
	//CritterFactory critterFactory();

	money = 10;
	currentLevel = 0;
	
	

}


Logic::~Logic()
{
}


void Logic::calculate()
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

void Logic::render()
{
	//Render all the things, this is done after calculating;
	


}

void Logic::startLevel()
{
	//Set the level. Initalized at ZERO.
	currentLevel++;
	critterFactory.nextLevel();

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

void Logic::endLevel()
{

	//Delete all projectiles
	//Wait for Mouse Click Event to start level again;
}


void Logic::frame()
{
	// if there is no more lives, then end the game
	// if there is no more critters, the end the level endLevel();

	if (critterFactory.canCreate())
	{
		critters.push_back(critterFactory.createCritter());
	}

	calculate();
	render();
	
	
	
	
	
}
