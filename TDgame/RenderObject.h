#pragma once

#include "sdl.h"
class RenderObject
{
public:
	RenderObject(SDL_Renderer * renderer);
	~RenderObject();
	void setRenderer();
	void renderFrame();
	SDL_Renderer * renderer;
	
};

