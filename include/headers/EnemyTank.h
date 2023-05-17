#pragma once
#ifndef ENEMYTANK_H
#define ENEMYTANK_H
#include "CommonFunc.h"
#include "BaseObject.h"
#include "Map.h"
#include "Tank.h"
#include "Bullet.h"
#include <cmath>
class EnemyTank :public Tank {
private:
	int enemy_move_count = 0;
	int enemy_move_count_2 = 0;
	int enemy_move_count_4 = 0;
	int enemy_move_count_6 = 0;
	int enemy_move_count_8 = 0;
	int enemyStep=0;
	int enemy_count_bullet = 0;
	int enemy_count_bullet_2 = 0;
	int enemy_count_bullet_4 = 0;
	int enemy_count_bullet_6 = 0;
	int enemy_count_bullet_8 = 0;
	int enemy_count_angleTime=0;
	bool bulletActive = 0;
	bool is_enemy_tank_alive = true;
	bool check_map_collision = false;
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
	void handleTankEnemyCollistion(Tank &EnemyTank);
	void handleTankEnemyMap();
	void EnemyTankMoveX(Map** walls,SDL_Renderer *g_screen,Tank& tankEnemy,EnemyTank *listenEnemy,int sizeOfTankEnemy,int index);
	void EnemyTankMoveY(Map** walls,SDL_Renderer *g_screen,Tank& tankEnemy,EnemyTank *listenEnemy,int sizeOfTankEnemy,int index);
	void EnemyCheckMap(Map& obstacle);
	void handleListTankEnemyCollistion(EnemyTank *listEnemy,int sizeOfTankEnemy,int index);
	void handleTankAI_2(Map **walls,Tank& tank);
	void handleTankAI_4(Map **walls,Tank& tank);
	void handleTankAI_6(Map **walls,Tank& tank);
	void handleTankAI_8(Map **walls,Tank& tank);
	bool checkMapCollision(Map& obstacle);
};
#endif
