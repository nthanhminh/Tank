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
	Map() {
		return;
	}
	Map(std::string path)
	{
		this->path = path;
	}
	bool getIsChange()
	{
		return this->is_change;
	}
	void setIschange(bool change)
	{
		this->is_change = change;
	}
	void setValue(int x)
	{
		this->value = x;
	}
	int getValue()
	{
		return this->value;
	}
	std::string getPath()
	{
		return this->path;
	}
	void loadMap()
	{
		if (this->value == 1)
		{
			bool ret = loadImg("img/wall_1.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value==2)
		{
			bool ret = loadImg("img/wall_2.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 3)
		{
			bool ret = loadImg("img/wall_3.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 4)
		{
			bool ret = loadImg("img/wall_4.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 5)
		{
			bool ret = loadImg("img/wall_5.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 6)
		{
			bool ret = loadImg("img/wall_6.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 7)
		{
			bool ret = loadImg("img/wall_7.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 8)
		{
			bool ret = loadImg("img/wall_8.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 11)
		{
			bool ret = loadImg("img/tree_2.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 12)
		{
			bool ret = loadImg("img/decorate_5.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 13)
		{
			bool ret = loadImg("img/boom_2.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 14)
		{
			bool ret = loadImg("img/min.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 9)
		{
			bool ret = loadImg("img/stone_1.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 21)
		{
			bool ret = loadImg("img/box_1.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 22)
		{
			bool ret = loadImg("img/box_2.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 23)
		{
			bool ret = loadImg("img/box_3.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 24)
		{
			bool ret = loadImg("img/box_4.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 25)
		{
			bool ret = loadImg("img/box_5.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 26)
		{
			bool ret = loadImg("img/box_6.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}
		else if (value == 27)
		{
			bool ret = loadImg("img/box_7.png", g_screen);
			if (ret == 0)
			{
				std::cout << "Can not load map";
			}
		}

		else if (value == 30)
		{
		bool ret = loadImg("img/mysterious_box.png", g_screen);
		if (ret == 0)
		{
			std::cout << "Can not load map";
		}
		}
		else if (value == 31)
		{
		bool ret = loadImg("img/nade.png", g_screen);
		if (ret == 0)
		{
			std::cout << "Can not load map";
		}
		}
	}
};
#endif