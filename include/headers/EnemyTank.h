#pragma once
#ifndef ENEMYTANK_H
#define ENEMYTANK_H
#include "CommonFunc.h"
#include "BaseObject.h"
#include "Map.h"
#include "Tank.h"
#include "Bullet.h"
class EnemyTank :public Tank {
private:
	int enemy_move_count = 0;
	int enemyStep=0;
	int enemy_count_bullet = 0;
	int enemy_count_angleTime=0;
	bool bulletActive = 0;
	bool is_enemy_tank_alive = true;
public:
	EnemyTank();
	EnemyTank(std::string str);
	/*bool getIsEnemyTankAlive()
	{
		return this->is_enemy_tank_alive;
	}
	void setIsEnemyTankAlive(bool check)
	{
		this->is_enemy_tank_alive = check;
	}*/
	int randomActive();
	bool getBulletActive();
	void setBulletActive(bool x);
	void handleAtiveTankEnemyA(Tank &tank);
	void handleAtiveTankEnemyB(Tank &tank);
	void handleAtiveTankEnemyC(Tank &tank);
	void handleAtiveTankEnemyD(Tank &tank);
	bool checkTankPosition(Tank &tank);
	void handleTankEnemyLandmineCollistion(Map& obstacle,SDL_Renderer *g_screen);
	void handleTankEnemyMap();
	void EnemyTankMoveX(Map** walls,SDL_Renderer *g_screen);
	void EnemyTankMoveY(Map** walls,SDL_Renderer *g_screen);
	void EnemyCheckMap(Map& obstacle);
};
#endif
