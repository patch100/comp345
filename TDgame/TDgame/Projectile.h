#pragma once

#include "Critter.h"

class Projectile
{
public:
	Projectile();
	~Projectile();

	//projectile moves
	void move();
	
	//then check if it hits target, takes damage
	bool hit();
	
	//then if it hit, it goes away, or when game ends, it goes away
	void die();

	//main method that calls the three;
	void calculate();

private:

	int * posX;
	int * posY;

	//Moving Speed
	int * speed;

	//Damage
	int * damage;

	//Type of projectile it is, from which tower
	int * type;

	Critter target;



};

