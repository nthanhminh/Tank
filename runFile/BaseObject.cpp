#include "BaseObject.h"
baseObject::baseObject()
{
	p_object_ = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
}
baseObject::~baseObject() {
	free();
}

bool baseObject::loadImg(std::string path, SDL_Renderer* screen)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadSurface = IMG_Load(path.c_str());
	if (loadSurface != NULL)
	{
		//SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, colorKeyR, colorKeyG, colorKeyB));
		newTexture = SDL_CreateTextureFromSurface(screen, loadSurface);
		if (newTexture != NULL)
		{
			rect_.w = loadSurface->w;
			rect_.h = loadSurface->h;
		}
		SDL_FreeSurface(loadSurface);
	}
	p_object_ = newTexture;
	return p_object_ != NULL;
}
void baseObject::render(SDL_Renderer* des, const SDL_Rect* clip)
{
	SDL_Rect renderquad = { rect_.x,rect_.y,rect_.w,rect_.h };
	SDL_RenderCopy(des, p_object_, clip, &renderquad);
}
void baseObject::renderRouteThink(SDL_Renderer* des, double angle, const SDL_Rect* clip)
{
	SDL_Rect renderquad = { rect_.x,rect_.y,rect_.w,rect_.h };
	SDL_RenderCopyEx(des, p_object_, clip, &renderquad, angle, NULL, SDL_FLIP_NONE);
}
void baseObject::free()
{
	if (p_object_ != NULL)
	{
		SDL_DestroyTexture(p_object_);
		p_object_ = nullptr;
		rect_.w = 0;
		rect_.h = 0;
	}
}
