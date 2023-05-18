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
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
//testc
class Menu {
public:
	baseObject background;
	std::string backgroundPath;	
	std::string tankPath;
	std::string mapPath;
	Tank tank;
	Map** walls = new Map * [mapRows];
	int sizeTankBullet = 0;
	int numberOfMenu=0;
	int numberOfEnemyTank=6;
	int sizeEnemyTankBullet = 0;
	Bullet* Bullets = new Bullet[1000000];
	EnemyBullet** EnemyBullets = new EnemyBullet * [numberOfEnemyTank];
	int sizeEnemyTankBulluets[10]{};
	EnemyTank* listEnemyTank = new EnemyTank[numberOfEnemyTank];
	SDL_Rect healBar;
	Menu();
	void setMapPath(std::string path);
	std::string getMapPath();
	int getSizeTankBullet();
	int getNumberofEnemyTank();
	baseObject getBg();
	EnemyBullet** getEnemyBullets();
	Tank getTank();
	EnemyTank* getListEnemyTank();
	Bullet* getBullet();
	Map** getMap();
	void setNumberOfEnemyTank(int x);
	std::string getTankPath();
	void setTankPath(std::string path);
	std::string getBgPath();
	void setBgPath(std::string path);
	void loadBg(SDL_Renderer *g_screen);
	void initTank(SDL_Renderer *g_screen);
	void InitMap(SDL_Renderer *g_screen);
	void setSizeTankBullet();
	void setSizeEnemyTankBullet(int i);
	void free();
	void close();
};
#endif