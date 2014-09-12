#include "Critter.h"


Critter::Critter()
{
	//set hp
	//set posX, posY
	//set walking speed
	
}


Critter::~Critter()
{

	//delete;
}

void Critter::calculate()
{
	move();

	//HP less than 1, it dies
	if (*HP < 1)
	die();

	if (endPath()){
		die();
		//lives minus one
	}

}

void Critter::move()
{
	//need some kind of direction mechanism
	//change direction if necessary
	//move posX, posY according to speed;
	//check for walls, etc

}

void Critter::die()
{
	//delete itself;
	//set pointer to null;
	//~Critter();

}

bool Critter::endPath()
{
	//check gamelogic end

	//if not then
	return false;

	//else
	return true;

}