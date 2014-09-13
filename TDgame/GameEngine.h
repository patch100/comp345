#pragma once

#include "SDL.h"
#include "Logic.h"
#include "MapEditor.h"
#include "menu.h"

#include "UserInput.h"
#include "RenderObject.h"


class GameEngine
{
public:
	GameEngine(SDL_Renderer * renderer);
	~GameEngine();

	

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
};

