#pragma once
#ifndef BULLET_H
#define BULLET_H
#include "CommonFunc.h"
#include "BaseObject.h"
#include "Map.h"
#include "Tank.h"
#include "EnemyTank.h"
#include "Music.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
class EnemyTank;
class Bullet : public baseObject {
private:
	std::string path;
	int originalXpos;
	int originalYpos;
	int vX;
	int vY;
	int status=0;
	double bulletAngle = 0;
	int choice_weapon = 0;
public:
	Bullet();
	void setChoiceWeapon(int x);
	int getChoiceWeapon();
	std::string getPath();
	void setPath(std::string str);
	void setOriginalX(int x);
	void setOriginalY(int x);
	int getOriginalX();
	int getOriginalY();
	void setStatus(Tank& tank);
	int getStatus();
	void setStatus(EnemyTank& tank);
	void setVx(int v);
	void setVy(int y);
	int getVx();
	int getVy();
	double getBulletAngle();
	void setBulletAngle(double x);
	void ap(Tank &tank);
	void handleBulletEvents(SDL_Event& e,Tank& tank,Map**walls,SDL_Renderer *g_screen,AudioManager &sound);
	void move(Map**walls,EnemyTank *tank,int sizeEnemyTank,Tank &this_tank,SDL_Renderer *g_screen,bool &gameOver,AudioManager &sound_collision,AudioManager &sound_tank);
	bool checkCollision(SDL_Rect rect1, SDL_Rect rect2);
	void handleTankMapCollision(Map& tankEnemy,EnemyTank *tank,int sizeEnemyTank,Tank &this_tank,SDL_Renderer *g_screen,bool &gameOver,AudioManager &sound_collistion);
	void handleTankEnemy(EnemyTank& tankEnemy,SDL_Renderer *g_screen,AudioManager &sound_tank);
};
#endif