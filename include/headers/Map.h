#pragma once
#ifndef MAP_H
#define MAP_H
#include "CommonFunc.h"
#include "BaseObject.h"
#include <iostream>
class Map :public baseObject {
private:
	std::string path;
	int value = 0;
	bool is_change = false;
public:
	Map();
	Map(std::string path);
	bool getIsChange();
	void setIschange(bool change);
	void setValue(int x);
	int getValue();
	std::string getPath();
	void setPath(std::string path);
	void loadMap(SDL_Renderer *g_screen);
};
#endif