#pragma once
#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H
#include "CommonFunc.h"
class baseObject {
public:
	baseObject();
	~baseObject();
	void setRect(const int& x, const int& y)
	{
		rect_.x = x;
		rect_.y = y;
	}
	SDL_Rect getRect() const {
		return rect_;
	}
	SDL_Texture* getObject() const
	{
		return p_object_;
	}
	bool loadImg(std::string path, SDL_Renderer* screnn);
	void render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
	void renderRouteThink(SDL_Renderer* des, double angle, const SDL_Rect* clip = NULL);
	void free();
	void setXYpos(int x, int y)
	{
		rect_.x = x;
		rect_.y=y;
	}
	int getWidth()
	{
		return rect_.w;
	}
	int getHeight()
	{
		return rect_.h;
	}
	int getXpos()
	{
		return rect_.x;
	}
	int getYpos()
	{
		return rect_.y;
	}


protected:
	SDL_Texture* p_object_;
	SDL_Rect rect_;
	//SDL_RendererFlip* flip;

};
#endif