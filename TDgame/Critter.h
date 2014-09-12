#pragma once
class Critter
{
public:
	Critter();
	~Critter();

	//Critter moves, posX, posY changes;
	void move();
	
	//Critter dies HP;
	void die();

	//Critter makes it to the end; return true when it has reached the end;
	bool endPath();

	//calcuate is everything a critter has to do for every frame of game, to it just calls move, die and endpath
	void calculate();

	int * posX;
	int * posY;
	int * moveSpeed;

	int * HP;

	int direction;

};

