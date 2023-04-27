#pragma once
#ifndef MENU_H
#define MENU_H
#include "CommonFunc.h"
#include "BaseObject.h"
#include "Tank.h"
#include "EnemyTank.h"
#include "EnemyBullet.h"
#include "Bullet.h"
#include "Map"
#include <iostream>
#include <fstream>
//testc
class Menu {
public:
	baseObject background;
	std::string backgroundPath;	
	Tank tank;
	Map** walls = new Map * [mapRows];
	int sizeTankBullet = 0;
	int numberOfMenu=0;
	int numberOfEnemyTank=5;
	int sizeEnemyTankBullet = 0;
	Bullet* Bullets = new Bullet[1000000];
	EnemyBullet** EnemyBullets = new EnemyBullet * [numberOfEnemyTank];
	int sizeEnemyTankBulluets[10]{};
	EnemyTank* listEnemyTank = new EnemyTank[numberOfEnemyTank];
	SDL_Rect healBar;
	Menu()
	{
		srand(time(0));
		setNumberOfEnemyTank(5);
		numberOfMenu=0;
	}
	int getSizeTankBullet()
	{
		return this->sizeTankBullet;
	}
	int getNumberofEnemyTank()
	{
		return this->numberOfEnemyTank;
	}
	baseObject getBg()
	{
		return this->background;
	}
	EnemyBullet** getEnemyBullets()
	{
		return this->EnemyBullets;
	}
	Tank getTank()
	{
		return this->tank;
	}
	EnemyTank* getListEnemyTank()
	{
		return this->listEnemyTank;
	}
	Bullet* getBullet()
	{
		return this->Bullets;
	}
	Map** getMap()
	{
		return this->walls;
	}
	void setNumberOfEnemyTank(int x)
	{
		this->numberOfEnemyTank = x;
	}
	std::string getBgPath()
	{
		return this->backgroundPath;
	}
	void setBgPath(std::string path)
	{
		this->backgroundPath = path;
	}
	void loadBg()
	{
		bool ret = background.loadImg(this->backgroundPath, g_screen);
		if (ret == false)
		{
			std::cout << "Can not load background";
		}
	}
	void initTank()
	{
		tank.setPath("img//tank_test.png");
		if (!tank.loadTank())
		{
			std::cout << "Can not load tank";
		}
		tank.setXYpos(1000, 650);
		for (int i = 0; i < this->numberOfEnemyTank; i++)
		{
			EnemyBullets[i] = new EnemyBullet[1000];
		}
		for (int i = 0; i < this->numberOfEnemyTank; i++)
		{
			listEnemyTank[i].setXYpos(rand()%200, rand()%200);
			listEnemyTank[i].setPath("img//tank_test.png");
		}
		for (int i = 0; i < this->numberOfEnemyTank; i++)
		{
			if (!listEnemyTank[i].loadTank())
			{
				std::cout << "can not load tank enemy" << "  133" << std::endl;
			}
		}
	}
	void InitMap()
	{
		for (int i = 0; i < mapRows; i++)
		{
			walls[i] = new Map[mapCols];
		}
		Map map;
		if (numberOfMenu==0)
			map.setPath("data/data.txt");
		else if (numberOfMenu==1)
		{
			map.setPath("data/data.txt");
		}
		std::ifstream file;
        file.open(map.getPath());
		for (int i = 0; i < mapRows; i++)
		{
			for (int j = 0; j < mapCols; j++)
			{
				int x;
				file >> x;
				walls[i][j].setValue(x);
			}
		}
		for (int i = 0; i < mapRows; i++)
		{
			for (int j = 0; j < mapCols; j++)
			{
				std::cout << walls[i][j].getValue() << " ";
				walls[i][j].setXYpos(j * 50, i * 50);
				walls[i][j].loadMap();
			}
			std::cout << "\n";
		}
	}
	void close()
	{
		delete[]listEnemyTank;
		//detroy bullet
		for (int i = 0; i < sizeTankBullet; i++)
		{
		    Bullets[i].free();
		}
		delete[]Bullets;
		//detroy map
		for (int i = 0; i < mapRows; i++)
		{
		    for (int j = 0; j < mapCols; j++)
		    {
		        walls[i][j].free();
		    }
		}
		delete[] walls;
	}
};
#endif