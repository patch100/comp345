#include "UserInput.h"
#include "GUI.h"

UserInput::UserInput()
{
	using namespace GUI;
}


UserInput::~UserInput()
{
}


int UserInput::mapEditorSelect(int flag)
{
	using namespace GUI;

	bool test = false;

	SDL_Event event;

	while (!test)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			int x = event.motion.x;
			int y = event.motion.y;

			if (x > side_menu_offset_x && x < side_menu_offset_x + side_menu_icon_width + 1)
			{
				if (
					y > side_menu_offset_y 
					&& 
					y < side_menu_offset_y + side_menu_icon_height + 1) 
					return 1;

				else if (
					y > side_menu_offset_y + side_menu_icon_height + side_menu_gap
					&& 
					y < side_menu_offset_y + side_menu_icon_height * 2 + side_menu_gap + 1) 
					return 2;

				else if (
					y > side_menu_offset_y + side_menu_icon_height * 2 + side_menu_gap * 2
					&&
					y < side_menu_offset_y + side_menu_icon_height * 3 + side_menu_gap * 2 + 1){
						if (flag == 1)	return 3;
					}
				else return 4;
					

			}
			else return 4;


		}


	}
}

