#ifndef menu_h
#define menu_h

#include "sdl.h"


class Menu
{
public:

	SDL_Surface * top_menu;
	SDL_Texture * top_menu_texture;
	SDL_Rect top_menu_rect;

	SDL_Surface * side_menu;
	SDL_Texture * side_menu_texture;
	SDL_Rect side_menu_rect;

	SDL_Renderer * renderer;

	Menu(SDL_Renderer * renderer);
	~Menu();
	void renderMenu();



};

#endif