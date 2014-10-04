#include "CritterFactory.h"


CritterFactory::CritterFactory()
{

	
	critterNumber = 0;
	level = 0;
}


CritterFactory::~CritterFactory()
{
}

void CritterFactory::nextLevel()
{
	level++;
	//set critter number;
	//number of critters per level;
}

Critter CritterFactory::createCritter()
{
	//Depending on level, create X type critter
	Critter crit;
	critterNumber = critterNumber - 1;
	return crit;
}
bool CritterFactory::canCreate()
{
	if (critterNumber == 0) return false;
	else return true;

}