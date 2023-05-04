#pragma once
#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "CommonFunc.h"
#include "BaseObject.h"
#include "Map.h"
#include "Tank.h"
#include "EnemyTank.h"
#include "Bullet.h"
#include <iostream>
#include <string>
class EnemyBullet : public Bullet {
private:
	
public:
	EnemyBullet();
	void ap(EnemyTank& tank);
	void handleAutomatic(EnemyTank& enemyTank,SDL_Renderer *g_screen);
	void moveAuto(Tank& tankEnemy, Map** walls,Tank &this_tank,SDL_Renderer *g_screen,bool &gameOver);
	bool checkCollision(SDL_Rect rect1, SDL_Rect rect2);
	void handleTankMapCollisionForEnemyTank(Map& tankEnemy,Tank &tank_enemy,Tank &this_tank,SDL_Renderer *g_screen,bool &gameOver);
	void handleMyTank(Tank& tankEnemy,SDL_Renderer *g_screen);
};
#endif