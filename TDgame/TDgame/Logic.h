#pragma once

#include <vector>
#include "Tower.h"
#include "Projectile.h"
#include "critter.h"

using namespace std;

class Logic
{
public:
	Logic(int ** grid, int startRow, int startColumn, int endRow, int endColumn);
	~Logic();

	//Returns when game is over or not;
	bool GameOver();

	//Changes the position and states of all objects in the game
	void calculate();

	//Display after calculating
	void render();

	//When there are no more critters on the map (all dead), delete all projectiles still around
	//Pauses the game until the player continues;
	void endLevel();

	//Start the level, creates the critters;
	void startLevel();


	// Vectors for tower, projectile and critter
	vector <Tower> towers;
	vector <Projectile> projectiles;
	vector <Critter> critters;

	// Map passed from Map Editor, or from Premade Map
	int ** map;

	//Where the critters come from, where they end;
	int startX;
	int startY;
	int endX;
	int endY;

	// Number of critters allowed to pass through the end until game is over;
	int lives;

	//CurrentLevel;
	int currentLevel;

	//MONEY$$$$
	int money;

};

