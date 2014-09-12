#include "Logic.h"


Logic::Logic(int ** grid, int startRow, int startColumn, int endRow, int endColumn)
{

	map = grid;

	startX = startRow;
	startY = startColumn;

	endX = endRow;
	endY = endColumn;

}


Logic::~Logic()
{
}


void Logic::calculate()
{
	
	//Moves the towers, moves the critters, move the projectiles, calculate everything. does a loop;
	//Iterates each object in the vectors, and calculates their movement
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

	



}

void Logic::render()
{
	//Render all the things, this is done after calculating;
	


}

void Logic::startLevel()
{
	currentLevel++;

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
	