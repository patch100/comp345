#ifndef menu_h
#define menu_h

#include "sdl.h"
#include "gui.h"

class Menu
{
public:

	SDL_Surface * top_menu;
	SDL_Texture * top_menu_texture;
	SDL_Rect top_menu_rect;

	SDL_Surface * side_menu;
	SDL_Texture * side_menu_texture;
	SDL_Rect side_menu_rect;

	SDL_Surface * bot_menu;
	SDL_Texture * bot_menu_texture;
	SDL_Rect bot_menu_rect;

	SDL_Rect basic_menu_rect;
	SDL_Texture * basic_menu;

	SDL_Renderer * renderer;

	SDL_Surface * map1;
	SDL_Texture * map1_texture;
	SDL_Rect map1_rect;

	SDL_Surface * map2;
	SDL_Texture * map2_texture;
	SDL_Rect map2_rect;

	SDL_Surface * map3;
	SDL_Texture * map3_texture;
	SDL_Rect map3_rect;

	//These use the same space as map1 and map2
	SDL_Surface * select_edit;
	SDL_Texture * select_edit_texture;

	SDL_Surface * select_premade;
	SDL_Texture * select_premade_texture;
	
	

	Menu(SDL_Renderer * renderer);
	~Menu();

	void renderMenu();
	void renderEditOrPremade();
	void renderPremadeMapSelection();

};

#endif