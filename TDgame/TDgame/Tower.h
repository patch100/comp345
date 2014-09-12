#pragma once

#include "Critter.h"
class Tower
{
public:
	Tower();
	~Tower();

	//find Target runs first
	//If Tower already has target, check target posX, posY, if it is within range, fireProjectile();
	//If not in range, or no target, or target Hp = 0, then iterate through vector critters until find one;
	//If no target, tower does nothing
	void findTarget();

	//Create new projectile object. Add to projectiles vector
	void fireProjectile();

	//main function, calls find target, then fire projectile if target is found;
	void calculate();



	//Two mouse click events:
	//Sells Tower, gets back points;
	void sellTower();
	//Upgrade tower;
	void upgrade();
private:

	// Firing range
	int * range;

	int * posX;
	int * posY;

	int * firingSpeed;

	//Every tower needs to find a target, and then fire the projectile, depending on firing speed;
	Critter * target;

	//Type of tower;
	// int type;

};

