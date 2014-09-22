#ifndef CRITTERFACTORY_H
#define CRITTERFACTORY_H
#include"Critter.h"
class CritterFactory
{
public:

	int level;
	int critterNumber;
	CritterFactory();
	~CritterFactory();
	void nextLevel();
	bool canCreate();
	Critter createCritter();
};

#endif
