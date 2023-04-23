#pragma once
#ifndef BULLET_H
#define BULLET_H
#include "CommonFunc.h"
#include "BaseObject.h"
#include "Map.h"
#include "Tank.h"
#include "EnemyTank.h"
#include <iostream>
#include <string>
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
	Bullet()
	{
		srand(time(0));
		path = "img//bulletblue2.png";
		vX = 0;
		vY = 0;
		this->choice_weapon = 0;
	}
	void setChoiceWeapon(int x)
	{
		this->choice_weapon = x;
	}
	int getChoiceWeapon()
	{
		return this->choice_weapon;
	}
	std::string getPath()
	{
		return path;
	}
	void setPath(std::string str)
	{
		this->path = str;
	}
	void setOriginalX(int x)
	{
		this->originalXpos = x;
	}
	void setOriginalY(int x)
	{
		this->originalYpos = x;
	}
	int getOriginalX()
	{
		return originalXpos;
	}
	int getOriginalY()
	{
		return originalYpos;
	}
	void setStatus(Tank& tank)
	{
		if (tank.getAngle()==270 || tank.getAngle() == 90)
		{
			this->status = 1;
		}
		else
		{
			this->status = 0;
		}
	}
	int getStatus()
	{
		return this->status;
	}
	void setStatus(EnemyTank& tank)
	{
		if (tank.getAngle() == 270 || tank.getAngle() == 90)
		{
			this->status = 1;
		}
		else
		{
			this->status = 0;
		}
	}
	void setVx(int v)
	{
		this->vX = v;
	}
	void setVy(int y)
	{
		this->vY = y;
	}
	int getVx()
	{
		return vX;
	}
	int getVy()
	{
		return vY;
	}
	double getBulletAngle()
	{
		return bulletAngle;
	}
	void setBulletAngle(double x)
	{
		this->bulletAngle = x;
	}
	void ap(Tank &tank)
	{
		if (tank.getAngle()==90)
		{
			 originalXpos = tank.getXpos() + tank.getWidth();
			 originalYpos = (tank.getYpos() + tank.getHeight()/2) - this->getHeight()/2;
			 bulletAngle = 90;
		}
		else if (tank.getAngle()==270)
		{
			originalXpos = tank.getXpos();
			originalYpos = tank.getYpos() + tank.getHeight()  / 2 - this->getHeight() / 2;
			bulletAngle = 270;
		}
		else if (tank.getAngle() == 0)
		{
			originalXpos = tank.getXpos() + tank.getWidth() / 2 - getWidth() / 2;
			originalYpos = tank.getYpos();
			bulletAngle = 0;
		}
		else if (tank.getAngle()==180)
		{
			originalXpos = tank.getXpos() + tank.getWidth() / 2 - getWidth() / 2;
			originalYpos = tank.getYpos() + tank.getHeight();
			bulletAngle = 180;
		}

		this->setXYpos(originalXpos, originalYpos);
	}
	void handleBulletEvents(SDL_Event& e,Tank& tank,Map**walls)
	{
		if (e.type == SDL_KEYDOWN && e.key.repeat==0)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_SPACE:
				if (tank.getAngle()==90 && tank.getIsTankAlive()==true)
				{		
					if (tank.getWeapon() == 1)
					{
						this->setPath("img/bullet.png");
					}
					else if (tank.getWeapon()==2)
					{
						this->setPath("img/bullets_1.png");
					}
					setChoiceWeapon(tank.getWeapon());
						if (!loadImg(path, g_screen))
						{
							std::cout << "can not load bullet";
						}
						ap(tank);
						Mix_Init(MIX_INIT_MP3);
						Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
						Mix_Chunk* sound = Mix_LoadWAV("sound/gun10.wav");
						Mix_PlayChannel(-1, sound, 0);
						setVx(v_bullet);
						setStatus(tank);
				}
				else if (tank.getAngle()==270 && tank.getIsTankAlive()==true )
				{
					if (tank.getWeapon() == 1)
					{
						this->setPath("img/bullet.png");
					}
					else if (tank.getWeapon() == 2)
					{
						this->setPath("img/bullets_1.png");
					}
					setChoiceWeapon(tank.getWeapon());
					if (!loadImg(path, g_screen))
					{
						std::cout << "can not load bullet";
					}
						ap(tank);
						Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
						Mix_Chunk* sound = Mix_LoadWAV("sound/gun10.wav");
						Mix_PlayChannel(-1, sound, 0);
						setVx(-v_bullet);
						setStatus(tank);
				}
				else if (tank.getAngle()==0 && tank.getIsTankAlive()==true )
				{
					if (tank.getWeapon() == 1)
					{
						this->setPath("img/bullet.png");
					}
					else if (tank.getWeapon() == 2)
					{
						this->setPath("img/bullets_1.png");
					}
					setChoiceWeapon(tank.getWeapon());
					if (!loadImg(path, g_screen))
					{
						std::cout << "can not load bullet";
					}
						ap(tank);
						Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
						Mix_Chunk* sound = Mix_LoadWAV("sound/gun10.wav");
						Mix_PlayChannel(-1, sound, 0);
						setVy(-v_bullet);
						setStatus(tank);
				}
				else if (tank.getAngle()==180 && tank.getIsTankAlive()==true)
				{
					if (tank.getWeapon() == 1)
					{
						this->setPath("img/bullet.png");
					}
					else if (tank.getWeapon() == 2)
					{
						this->setPath("img/bullets_1.png");
					}
					setChoiceWeapon(tank.getWeapon());
					if (!loadImg(path, g_screen))
					{
						std::cout << "can not load bullet";
					}
						ap(tank);
						Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
						Mix_Chunk* sound = Mix_LoadWAV("sound/gun10.wav");
						Mix_PlayChannel(-1, sound, 0);
						setVy(v_bullet);
						setStatus(tank);
				}
			}
		}
	}
	void move(Map**walls,EnemyTank *tank,int sizeEnemyTank)
	{
		if (status == 1)
		{
			rect_.x += vX;
			rect_.y = originalYpos;
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
			for (int i = 0; i < sizeEnemyTank; i++)
			{
				handleTankEnemy(tank[i]);
			}
			/*for (int i = 0; i < enemySize; i++)
			{
				handleTankEnemy(tankEnemys[i]);
			}*/
			if (rect_.x <= 0 || rect_.x > screenWidth)
			{
				this->free();
			}
		}
		else
		{
			rect_.x = originalXpos;
			rect_.y += vY;
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
			if (rect_.y > scrennHeight || rect_.y < 0)
			{
				this->free();
			}
			for (int i = 0; i < sizeEnemyTank; i++)
			{
				handleTankEnemy(tank[i]);
			}
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
	void handleTankMapCollision(Map& tankEnemy)
	{

		SDL_Rect bulletRect = { getXpos(), getYpos(), getWidth(), getHeight() };
		SDL_Rect mapRect = { tankEnemy.getXpos(), tankEnemy.getYpos(), tankEnemy.getWidth(), tankEnemy.getHeight() };

		if (checkCollision(bulletRect, mapRect))
		{
			if (tankEnemy.getValue() < 10 && tankEnemy.getValue()!=0)
			{
				baseObject Effect;
				if (Effect.loadImg("img/explosion4.png", g_screen) == false)
				{
					std::cout << "Can not load effect";
				}
				Effect.setXYpos(getXpos() - Effect.getWidth() / 2, getYpos() - Effect.getHeight() / 2);
				Effect.render(g_screen, NULL);
				Mix_Init(MIX_INIT_MP3);
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
				Mix_Chunk* sound = Mix_LoadWAV("sound/gun9.wav");
				Mix_PlayChannel(-1, sound, 0);
				setVx(0);
				setVy(0);
				this->setXYpos(2000, 2000);
				this->free();
				tankEnemy.setXYpos(2000, 2000);
				tankEnemy.free();
			}
			else if(tankEnemy.getValue()==30)
			{
				baseObject Effect;
				if (Effect.loadImg("img/explosion4.png", g_screen) == false)
				{
					std::cout << "Can not load effect";
				}
				Effect.setXYpos(getXpos() - Effect.getWidth() / 2, getYpos() - Effect.getHeight() / 2);
				Effect.render(g_screen, NULL);
				Mix_Init(MIX_INIT_MP3);
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
				Mix_Chunk* sound = Mix_LoadWAV("sound/gun9.wav");
				Mix_PlayChannel(-1, sound, 0);
				setVx(0);
				setVy(0);
				this->setXYpos(2000, 2000);
				this->free();
				int choice = rand() % 3;
				if (choice == 1)
				{
					bool ret = tankEnemy.loadImg("img/weapon_2.png", g_screen);
					if (ret == false)
					{
						std::cout << "can not load rocket";
					}
					tankEnemy.setValue(51);
				}
				else if (choice==2)
				{
					bool ret = tankEnemy.loadImg("img/weapon_1.png", g_screen);
					if (ret == false)
					{
						std::cout << "can not load rocket";
					}
					tankEnemy.setValue(52);
				}
				else {
					bool ret = tankEnemy.loadImg("img/first_kit.png", g_screen);
					if (ret == false)
					{
						std::cout << "can not load first_kit";
					}
					tankEnemy.setValue(53);
				}
			}
			else if (tankEnemy.getValue()!=14 && tankEnemy.getValue() <= 50)
			{
				baseObject Effect;
				if (Effect.loadImg("img/explosion4.png", g_screen) == false)
				{
					std::cout << "Can not load effect";
				}
				Effect.setXYpos(getXpos() - Effect.getWidth() / 2, getYpos() - Effect.getHeight() / 2);
				Effect.render(g_screen, NULL);
				Mix_Init(MIX_INIT_MP3);
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
				Mix_Chunk* sound = Mix_LoadWAV("sound/gun9.wav");
				Mix_PlayChannel(-1, sound, 0);
				setVx(0);
				setVy(0);
				this->setXYpos(2000, 2000);
				this->free();
			}
		}
	}
	void handleTankEnemy(EnemyTank& tankEnemy)
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
			if (tankEnemy.getTankHp() - damge[getChoiceWeapon()] > 0)
			{
				tankEnemy.setTankHp(tankEnemy.getTankHp() - damge[getChoiceWeapon()]);
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