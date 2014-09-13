#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "SDL.h"
#include "Logic.h"
#include "MapEditor.h"
#include "Menu.h"
#include "UserInput.h"
#include "RenderObject.h"


class GameEngine
{
public:

	//Game Engine is responsible for all of these objects
	Logic* logic;

	Menu * menu;

	MapEditor* mapEditor;

	UserInput* userInput;

	RenderObject * renderObject;


	//From main.cpp
	SDL_Renderer* renderer;



	static const int SCREEN_WIDTH = 1000;
	static const int SCREEN_HEIGHT = 800;

	GameEngine(SDL_Renderer * renderer);
	~GameEngine();

	
	void phase1(); // Map Editor
	void phase2(); // Game starts
	void phase3(); // Game ends





};



#endif