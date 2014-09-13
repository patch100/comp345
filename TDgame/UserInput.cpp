#include "UserInput.h"


UserInput::UserInput()
{
}


UserInput::~UserInput()
{
}


void UserInput::mapEdit()
{
	bool quit = false;
	SDL_Event event;
	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}




	}

}