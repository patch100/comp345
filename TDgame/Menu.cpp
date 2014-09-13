#include "Menu.h"


Menu::Menu(SDL_Renderer * renderer)
{

	top_menu = SDL_LoadBMP("top_menu.bmp");
	top_menu_texture = SDL_CreateTextureFromSurface(renderer,
		top_menu);

	SDL_FreeSurface(top_menu);
	menu_rect = { 0, 0, 884, 84 };
}


Menu::~Menu()
{
}

void Menu::renderMenu()
{

	SDL_RenderCopy(renderer, top_menu_texture, NULL, &menu_rect);
}