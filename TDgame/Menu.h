#pragma once

#include "SDL.h"
#include "GameEngine.h"
class Menu
{
public:
	Menu(SDL_Renderer * renderer);
	~Menu();
	void renderMenu();

	SDL_Surface * top_menu;
	SDL_Texture * top_menu_texture;
	SDL_Rect menu_rect;


	SDL_Renderer * renderer;

};

