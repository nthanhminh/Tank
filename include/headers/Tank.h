#pragma once
#ifndef TANK_H
#define TANK_H
#include "CommonFunc.h"
#include "BaseObject.h"
#include "Map.h"
class Tank :public baseObject {
private:
	std::string path;
	int originalXpos;
	int originalYpos;
	std::string vec;
	int vX;
	int vY;
	double angle = 0;
	int enemy_move_count = 0;
	bool is_tank_alive = true;
	bool tankIsProtected = false;
	int count_time_defender=100;
	int weapon = 0;
	int tank_hp = 20;
	SDL_Rect healthBar;
public:
	Tank();
	SDL_Rect getHealBar();
	void setTimeDefender(int time_defender);
	int getTimeDefender();
	void setTankIsProtected(bool check);
	bool getTankIsProtected();
	void setTankHp(int x);
	int getTankHp();
	void updateHealBar();
	void setWeapon(int x);
	int getWeapon();
	bool getIsTankAlive();
	void setIsTankAlive(bool check);
	Tank(std::string path);
	double getAngle();
	void setAngle(int x);
	void setvX(int v);
	void setvY(int v);
	int getvX();
	int getvY();
	void setPath(std::string path);
	std::string getPath();
	int getOriginalXpos();
	int getOriginalYpos();
	bool loadTank(SDL_Renderer* g_screen);
	void setOriginalXpos(int x);
	void setOriginalypos(int y);
	void handleEvents(SDL_Event& e,Map**walls);
	bool checkCollision(SDL_Rect rect1, SDL_Rect rect2);
	void myTankMoveX(Map** walls,SDL_Renderer *g_screen);
	void MyTankMoveY(Map** walls,SDL_Renderer *g_screen);
	void handleTankObstacleCollision (Map& obstacle);
	void handleTankEnemyCollision(Tank& tankEnemy);
	void handleTankLandmineCollistion(Map& obstacle,SDL_Renderer *g_screen);
	void handleGiftCollistion(Map& obstacle);
	void checkBoomEffect(int boomEffectPosX,int boomEffectPosY);
};
#endif
