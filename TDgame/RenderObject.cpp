#include "RenderObject.h"
#include "GameEngine.h"

RenderObject::RenderObject(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}


RenderObject::~RenderObject()
{
}


void RenderObject::setRenderer()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

}

void RenderObject::renderFrame()
{
	SDL_RenderPresent(renderer);

}