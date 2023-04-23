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
	EnemyBullet()
	{
		setPath("img/bulletdark2.png");
		setVx(0);
		setVy(0);
	}
	void ap(EnemyTank& tank)
	{
		if (tank.getAngle() == 90)
		{
			setOriginalX(tank.getXpos() + tank.getWidth());
			setOriginalY((tank.getYpos() + tank.getHeight() / 2) - this->getHeight() / 2);
			setBulletAngle(90);
		}
		else if (tank.getAngle() == 270)
		{
			setOriginalX(tank.getXpos());
			setOriginalY(tank.getYpos() + tank.getHeight() / 2 - this->getHeight() / 2);
			setBulletAngle(270);
		}
		else if (tank.getAngle() == 0)
		{
			setOriginalX(tank.getXpos() + tank.getWidth() / 2 - getWidth() / 2);
			setOriginalY(tank.getYpos());
			setBulletAngle(0);
		}
		else if (tank.getAngle() == 180)
		{
			setOriginalX(tank.getXpos() + tank.getWidth() / 2 - getWidth() / 2);
			setOriginalY(tank.getYpos() + tank.getHeight());
			setBulletAngle(180);
		}

		this->setXYpos(getOriginalX(), getOriginalY());
	}
	void handleAutomatic(EnemyTank& enemyTank)
	{
		if (enemyTank.getAngle() == 90)
		{
			if (enemyTank.getWeapon() == 1)
			{
				this->setPath("img/bullet.png");
			}
			else if (enemyTank.getWeapon() == 2)
			{
				this->setPath("img/bullets_1.png");
			}
			setChoiceWeapon(enemyTank.getWeapon());
			if (!loadImg(getPath(), g_screen))
			{
				std::cout << "can not load bullet";
			}
			ap(enemyTank);
			Mix_Init(MIX_INIT_MP3);
			Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
			Mix_Chunk* sound = Mix_LoadWAV("sound/gun10.wav");
			Mix_PlayChannel(-1, sound, 0);
			setVx(v_bullet);
			setStatus(enemyTank);
		}
		else if (enemyTank.getAngle() == 270)
		{
			if (enemyTank.getWeapon() == 1)
			{
				this->setPath("img/bullet.png");
			}
			else if (enemyTank.getWeapon() == 2)
			{
				this->setPath("img/bullets_1.png");
			}
			setChoiceWeapon(enemyTank.getWeapon());
			if (!loadImg(getPath(), g_screen))
			{
				std::cout << "can not load bullet";
			}
			ap(enemyTank);
			Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
			Mix_Chunk* sound = Mix_LoadWAV("sound/gun10.wav");
			Mix_PlayChannel(-1, sound, 0);
			setVx(-v_bullet);
			setStatus(enemyTank);
		}
		else if (enemyTank.getAngle() == 0)
		{
			if (enemyTank.getWeapon() == 1)
			{
				this->setPath("img/bullet.png");
			}
			else if (enemyTank.getWeapon() == 2)
			{
				this->setPath("img/bullets_1.png");
			}
			setChoiceWeapon(enemyTank.getWeapon());
			if (!loadImg(getPath(), g_screen))
			{
				std::cout << "can not load bullet";
			}
			ap(enemyTank);
			Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
			Mix_Chunk* sound = Mix_LoadWAV("sound/gun10.wav");
			Mix_PlayChannel(-1, sound, 0);
			setVy(-v_bullet);
			setStatus(enemyTank);
		}
		else if (enemyTank.getAngle() == 180)
		{
			if (enemyTank.getWeapon() == 1)
			{
				this->setPath("img/bullet.png");
			}
			else if (enemyTank.getWeapon() == 2)
			{
				this->setPath("img/bullets_1.png");
			}
			setChoiceWeapon(enemyTank.getWeapon());
			if (!loadImg(getPath(), g_screen))
			{
				std::cout << "can not load bullet";
			}
			ap(enemyTank);
			Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
			Mix_Chunk* sound = Mix_LoadWAV("sound/gun10.wav");
			Mix_PlayChannel(-1, sound, 0);
			setVy(v_bullet);
			setStatus(enemyTank);
		}
	}
	void moveAuto(Tank& tank, Map** walls)
	{
		if (getStatus() == 1)
		{
			rect_.x += getVx();
			rect_.y = getOriginalY();
			for (int i = 0; i < mapRows; i++)
			{
				for (int j = 0; j < mapCols; j++)
				{
					if (walls[i][j].getValue() != 0)
					{
						handleTankMapCollision(walls[i][j]);
					}
				}
			}
			handleMyTank(tank);
			/*for (int i = 0; i < enemySize; i++)
			{
				handleTankEnemy(tankEnemys[i]);
			}*/
		}
		else
		{
			rect_.x = getOriginalX();
			rect_.y += getVy();
			for (int i = 0; i < mapRows; i++)
			{
				for (int j = 0; j < mapCols; j++)
				{
					if (walls[i][j].getValue() != 0)
					{
						handleTankMapCollision(walls[i][j]);
					}
				}
			}
			handleMyTank(tank);
			/*for (int i = 0; i < enemySize; i++)
			{
				handleTankEnemy(tankEnemys[i]);
			}*/
		}
	}
	bool checkCollision(SDL_Rect rect1, SDL_Rect rect2)
	{
		int left1 = rect1.x;
		int right1 = rect1.x + rect1.w;
		int top1 = rect1.y;
		int bottom1 = rect1.y + rect1.h;
		int left2 = rect2.x;
		int right2 = rect2.x + rect2.w;
		int top2 = rect2.y;
		int bottom2 = rect2.y + rect2.h;


		if (left1 >= right2 || right1 <= left2 || top1 >= bottom2 || bottom1 <= top2)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	void handleMyTank(Tank& tankEnemy)
	{

		SDL_Rect bulletRect = { getXpos(), getYpos(), getWidth(), getHeight() };
		SDL_Rect tankEnemyRect = { tankEnemy.getXpos(), tankEnemy.getYpos(), tankEnemy.getWidth(), tankEnemy.getHeight() };

		if (checkCollision(bulletRect, tankEnemyRect))
		{

			baseObject Effect;
			if (Effect.loadImg("img/explosion3.png", g_screen) == false)
			{
				std::cout << "Can not load effect";
			}
			Effect.setXYpos(getXpos() - Effect.getWidth() / 2, getYpos() - Effect.getHeight() / 2);
			Effect.render(g_screen, NULL);
			Mix_Init(MIX_INIT_MP3);
			Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
			Mix_Chunk* sound = Mix_LoadWAV("sound/exp.wav");
			Mix_PlayChannel(-1, sound, 0);
			setVx(0);
			setVy(0);
			setXYpos(2000, 2000);
			free();
			std::cout << getXpos() << " " << getYpos() << " " << getWidth() << " " << getHeight() << std::endl;
			if (tankEnemy.getTankHp() - damge[getChoiceWeapon()] > 0)
			{
				tankEnemy.setTankHp(tankEnemy.getTankHp() - damge[getChoiceWeapon()]);
				std::cout << tankEnemy.getTankHp() << std::endl;
			}
			else
			{
				tankEnemy.setIsTankAlive(false);
				tankEnemy.free();
			}
		}
	}
};
#endif