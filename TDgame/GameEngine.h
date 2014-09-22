#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "SDL.h"
#include "GUI.h"
#include "MapEditor.h"
#include "Tower.h"
#include "Projectile.h"
#include "CritterFactory.h"
#include <vector>
#include "Menu.h"
#include "UserInput.h"
#include "RenderObject.h"

using namespace std;

class GameEngine
{
public:

	

	// Number of critters allowed to pass through the end until game is over;
	int lives;

	//CurrentLevel;
	int currentLevel;

	//MONEY$$$$
	int money;

	// Vectors for tower, projectile and critter
	vector <Tower> towers;
	vector <Projectile> projectiles;
	vector <Critter> critters;
	
	//Critter Factory Object;
	CritterFactory * critterFactory;

		//Game Engine is responsible for all of these objects


	Menu * menu;

	MapEditor* mapEditor;

	UserInput* userInput;

	RenderObject * renderObject;


	//From main.cpp
	SDL_Renderer* renderer;




	GameEngine(SDL_Renderer * renderer);
	~GameEngine();

	
	void phase1(); // Map Editor
	void phase2(); // Game starts
	void phase3(); // Game ends

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

	//Generates each frame;
	void frame();



};



#endif