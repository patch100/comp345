#include "Menu.h"


Menu::Menu(SDL_Renderer * renderer)
{	

	this->renderer = renderer;

	//Top Menu BackGround Render
	top_menu = SDL_LoadBMP("top_menu.bmp");
	top_menu_texture = SDL_CreateTextureFromSurface(renderer,
		top_menu);
	SDL_FreeSurface(top_menu);

	top_menu_rect = { 0, 0, 884, 84 };

	//Side Menu BackGround Render
	side_menu = SDL_LoadBMP("side_menu.bmp");
	side_menu_texture = SDL_CreateTextureFromSurface(renderer,
		side_menu);
	SDL_FreeSurface(side_menu);

	side_menu_rect = { 900, 0, 100, 675 };

	//Icon Render...
	
}


Menu::~Menu()
{
}

void Menu::renderMenu()
{
	SDL_RenderCopy(renderer, top_menu_texture, NULL, &top_menu_rect);
	SDL_RenderCopy(renderer, side_menu_texture, NULL, &side_menu_rect);
	SDL_RenderPresent(renderer);
}