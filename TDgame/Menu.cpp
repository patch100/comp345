#include "Menu.h"


Menu::Menu(SDL_Renderer * renderer)
{	
	using namespace GUI;
	this->renderer = renderer;

	//Top Menu BackGround Render
	top_menu = SDL_LoadBMP("graphics/top_menu.bmp");
	top_menu_texture = SDL_CreateTextureFromSurface(renderer,
		top_menu);
	SDL_FreeSurface(top_menu);
	top_menu_rect = { 0, 0, 680, 90};

	//Side Menu BackGround Render
	side_menu = SDL_LoadBMP("graphics/side_menu.bmp");
	side_menu_texture = SDL_CreateTextureFromSurface(renderer,
		side_menu);
	SDL_FreeSurface(side_menu);
	side_menu_rect = { 670, 0, 330, 800 };

	//Bottom Menu BackGround Render
	bot_menu = SDL_LoadBMP("graphics/bot_menu.bmp");
	bot_menu_texture = SDL_CreateTextureFromSurface(renderer,
		bot_menu);
	SDL_FreeSurface(bot_menu);
	bot_menu_rect = { 0, 760, 1000, 40 };

	//MAP EDITOR MENU ITEMS
	//Map1
	map1 = SDL_LoadBMP("graphics/map_1_icon.bmp");
	map1_texture = SDL_CreateTextureFromSurface(renderer,
		map1);
	SDL_FreeSurface(map1);
	map1_rect = {	side_menu_offset_x, 
					side_menu_offset_y, 
					side_menu_icon_width,
					side_menu_icon_height };

	//Map2
	map2 = SDL_LoadBMP("graphics/map_2_icon.bmp");
	map2_texture = SDL_CreateTextureFromSurface(renderer,
		map2);
	SDL_FreeSurface(map2);
	map2_rect = { side_menu_offset_x,
					side_menu_offset_y + side_menu_gap + side_menu_icon_height,
					side_menu_icon_width,
					side_menu_icon_height };

	//Map3
	map3 = SDL_LoadBMP("graphics/map_3_icon.bmp");
	map3_texture = SDL_CreateTextureFromSurface(renderer,
		map3);
	SDL_FreeSurface(map3);
	map3_rect = { side_menu_offset_x,
					side_menu_offset_y + side_menu_gap*2 + side_menu_icon_height*2,
					side_menu_icon_width,
					side_menu_icon_height };


	//Select Editor
	select_edit = SDL_LoadBMP("graphics/map_editor_icon.bmp");
	select_edit_texture = SDL_CreateTextureFromSurface(renderer,
		select_edit);
	SDL_FreeSurface(select_edit);

	//Select Premade
	select_premade = SDL_LoadBMP("graphics/premade_map_icon.bmp");
	select_premade_texture = SDL_CreateTextureFromSurface(renderer,
		select_premade);
	SDL_FreeSurface(select_premade);



	//Combined Menu
	basic_menu_rect = { 0, 0, 1000, 800 };
	basic_menu = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1000, 800);
	SDL_SetTextureBlendMode(basic_menu, SDL_BLENDMODE_BLEND);

	//Rendering textures to basic_menu texture
	SDL_SetRenderTarget(renderer, basic_menu);
	SDL_RenderCopy(renderer, top_menu_texture, NULL, &top_menu_rect);
	SDL_RenderCopy(renderer, side_menu_texture, NULL, &side_menu_rect);
	SDL_RenderCopy(renderer, bot_menu_texture, NULL, &bot_menu_rect);
	
	//Freeing Renderer;
	SDL_SetRenderTarget(renderer, NULL);

	
	

	
	
}


Menu::~Menu()
{
}

void Menu::renderMenu()
{
	SDL_RenderCopy(renderer,basic_menu, NULL, &basic_menu_rect);
	
}

void Menu::renderPremadeMapSelection()
{
	renderMenu();
	SDL_RenderCopy(renderer, map1_texture, NULL, &map1_rect);
	SDL_RenderCopy(renderer, map2_texture, NULL, &map2_rect);
	SDL_RenderCopy(renderer, map3_texture, NULL, &map3_rect);
	SDL_RenderPresent(renderer);
}

void Menu::renderEditOrPremade()
{
	renderMenu();
	SDL_RenderCopy(renderer, select_edit_texture, NULL, &map1_rect);
	SDL_RenderCopy(renderer, select_premade_texture, NULL, &map2_rect);
	SDL_RenderPresent(renderer);
}