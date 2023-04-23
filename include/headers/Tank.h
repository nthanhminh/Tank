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
	int weapon = 0;
	int tank_hp = 20;
	SDL_Rect healthBar;
public:
	Tank()
	{
		path = "img//my_tank_2.png";
		vX = 0;
		vY = 0;
		this->tank_hp = 20;
		healthBar.x = getXpos();
		healthBar.y = getYpos();
		healthBar.w = 50;
		healthBar.h = 10;
	}
	SDL_Rect getHealBar()
	{
		return healthBar;
	}
	void setTankHp(int x)
	{
		this->tank_hp = x;
	}
	int getTankHp()
	{
		return this->tank_hp;
	}
	void setWeapon(int x)
	{
		this->weapon = x;
	}
	int getWeapon()
	{
		return this->weapon;
	}
	bool getIsTankAlive()
	{
		return this->is_tank_alive;
	}
	void setIsTankAlive(bool check)
	{
		this->is_tank_alive = check;
	}
	Tank(std::string path)
	{
		this->path = path;
	}
	double getAngle()
	{
		return this->angle;
	}
	void setAngle(int x)
	{
		this->angle = x;
	}
	void setvX(int v)
	{
		this->vX = v;
	}
	void setvY(int v)
	{
		this->vY=v;
	}
	int getvX()
	{
		return this->vX;
	}
	int getvY()
	{
		return this->vY;
	}
	void setPath(std::string path)
	{
		this->path = path;
	}
	std::string getPath()
	{
		return this->path;
	}
	int getOriginalXpos()
	{
		return originalXpos;
	}
	int getOriginalYpos()
	{
		return originalYpos;
	}
	bool loadTank()
	{
		bool ret = loadImg(getPath(), g_screen);
		if (ret == false)
		{
			return false;
		}
		return true;
	}
	void setOriginalXpos(int x)
	{
		this->originalXpos = x;
	}
	void setOriginalypos(int y)
	{
		this->originalYpos = y;
	}
	void handleEvents(SDL_Event& e,Map**walls)
	{
		setOriginalXpos(getXpos());
		setOriginalypos(getYpos());
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				//rect_.y -= v;
				setvY(-v);
				if (rect_.y<= 0)
				{
					rect_.x = getOriginalXpos();
					rect_.y = v;
				}
				break;
			case SDLK_DOWN:
				//rect_.y += v;
				setvY(v);
				if (rect_.y + rect_.h >= scrennHeight)
				{
					rect_.y = scrennHeight-rect_.h;
				}
				break;
			case SDLK_LEFT:
				//rect_.x -= v;
				setAngle(270);
				setvX(-v);
				if (rect_.x <= 0)
				{
					rect_.x = 0;
					rect_.y = getOriginalYpos();
				}
				break;
			case SDLK_RIGHT:
				//rect_.x += v;
				setAngle(90);
				setvX(v);
				if (rect_.x + rect_.w >= screenWidth)
				{
					rect_.x = screenWidth-rect_.w;
				}
				break;
			}
		}
		else if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
				case SDLK_UP:
					vY = 0;
					break;
				case SDLK_DOWN:
					vY = 0;
					break;
				case SDLK_LEFT:
					vX = 0;
					break;
				case SDLK_RIGHT:
					vX = 0;
					break;
			}
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
	void myTankMoveX(Map** walls)
	{
		rect_.x += getvX();
		setOriginalXpos(getXpos());
		for (int i = 0; i < mapRows; i++)
		{
			for (int j = 0; j < mapCols; j++)
			{
				if (walls[i][j].getValue()!=0 && walls[i][j].getValue() < 11 || (walls[i][j].getValue()>20 && walls[i][j].getValue() <= 30))
					handleTankObstacleCollision(walls[i][j]);
				else if (walls[i][j].getValue() == 14)
					handleTankLandmineCollistion(walls[i][j]);
				else if (walls[i][j].getValue()>50 )
					handleGiftCollistion(walls[i][j]);
			}
		}
		if (rect_.x + rect_.w >= screenWidth)
		{
			rect_.x = screenWidth - rect_.w;
		}
		if (rect_.x <= 0)
		{
			rect_.x = 0;
		}
	}
	void MyTankMoveY(Map** walls)
	{
		if (getvX() == 0)
		{
			if (getvY() > 0)
			{
				setAngle(180);
			}
			else if (getvY() < 0)
			{
				setAngle(0);
			}
			rect_.y += getvY();
			setOriginalypos(getYpos());
			for (int i = 0; i < mapRows; i++)
			{
				for (int j = 0; j < mapCols; j++)
				{
					if (walls[i][j].getValue() != 0 && walls[i][j].getValue() < 11 || (walls[i][j].getValue() > 20 && walls[i][j].getValue() <= 30))
						handleTankObstacleCollision(walls[i][j]);
					else if (walls[i][j].getValue() == 14)
						handleTankLandmineCollistion(walls[i][j]);
					else if (walls[i][j].getValue() > 50)
						handleGiftCollistion(walls[i][j]);
				}
			}
			/*for (int i = 0; i < enemySize; i++)
			{
				handleTankEnemyCollision(list[i]);
			}*/
			if (rect_.y + rect_.h >= scrennHeight)
			{
				rect_.y = scrennHeight - rect_.h;
			}
			if (rect_.y <= 0)
			{
				rect_.y = 0;
			}
		}
	}
	void handleTankObstacleCollision (Map& obstacle)
	{
		SDL_Rect tankRect = { getXpos(), getYpos(), getWidth(), getHeight()};
		SDL_Rect mapRect = { obstacle.getXpos(), obstacle.getYpos(), obstacle.getWidth(), obstacle.getHeight()};
		if (checkCollision(tankRect, mapRect))
		{
			if (angle == 90)
			{
				setXYpos(obstacle.getXpos() - this->getWidth() -1, getOriginalYpos());
			}
			else if (angle == 270)
			{
				setXYpos(obstacle.getXpos() + obstacle.getWidth() + 1, getOriginalYpos());
			}
			else if (angle == 0)
			{
				setXYpos(getOriginalXpos(), obstacle.getYpos() + obstacle.getHeight() + 1);
			}
			else if (angle==180)
			{
				setXYpos(getOriginalXpos(), obstacle.getYpos() - this->getHeight() - 1);
			}
			/*else
			{
				setXYpos(originalXpos, originalYpos);
			}*/
		}
	}
	void handleTankEnemyCollision(Tank& tankEnemy)
	{
		/*setOriginalXpos(getXpos());
		setOriginalypos(getYpos());*/
		SDL_Rect tankRect = { getXpos(), getYpos(), getWidth(), getHeight() };
		SDL_Rect mapRect = { tankEnemy.getXpos(), tankEnemy.getYpos(), tankEnemy.getWidth(), tankEnemy.getHeight() };
		if (checkCollision(tankRect, mapRect))
		{
			/*if (getAngle() == 90)
			{
				setXYpos(tankEnemy.getXpos() - tankEnemy.getWidth() - 3, getOriginalYpos());
			}
			else if (getAngle() == 270)
			{
				setXYpos(tankEnemy.getXpos() + tankEnemy.getWidth() + 3, getOriginalYpos());
			}
			else if (getAngle() == 0)
			{
				setXYpos(getOriginalXpos(), tankEnemy.getYpos() + tankEnemy.getHeight() + 3);
			}
			else if (getAngle() == 180)
			{
				setXYpos(getOriginalXpos(), tankEnemy.getYpos() - tankEnemy.getHeight() - 3);
			}*/
			/*tankEnemy.setvX(0);
			tankEnemy.setvY(0);
			setvX(0);
			setvY(0);*/
			setXYpos(getOriginalXpos(), getOriginalYpos());
			vX = 0;
			vY = 0;
		}
	}
	void handleTankLandmineCollistion(Map& obstacle)
	{
		SDL_Rect tankRect = { getXpos(), getYpos(), getWidth(), getHeight() };
		SDL_Rect mapRect = { obstacle.getXpos(), obstacle.getYpos(), obstacle.getWidth(), obstacle.getHeight() };
		if (checkCollision(tankRect, mapRect))
		{
			baseObject ani;
			bool ret = ani.loadImg("img/explosion4.png", g_screen);
			if (ret == false)
			{
				std::cout << "can not load ani in handleTankLandmineCollistion" << std::endl;
			}
			ani.setXYpos(obstacle.getXpos(),obstacle.getYpos());
			ani.render(g_screen, NULL);
			setXYpos(5000,5000);
			free();
			setIsTankAlive(false);
			obstacle.setValue(32);
			obstacle.free();
		}
	}
	void handleGiftCollistion(Map& obstacle)
	{
		SDL_Rect tankRect = { getXpos(), getYpos(), getWidth(), getHeight() };
		SDL_Rect mapRect = { obstacle.getXpos(), obstacle.getYpos(), obstacle.getWidth(), obstacle.getHeight() };
		if (checkCollision(tankRect, mapRect))
		{	
			if (obstacle.getValue()<53)
				setWeapon(obstacle.getValue()-50);
			if (obstacle.getValue()==53)
			{
				if (getTankHp() < 20)
					setTankHp(getTankHp() + 10);
				else
					setTankHp(health);
			}
			obstacle.setValue(0);
			obstacle.free();
			std::cout << getWeapon() << std::endl;
		}
	}
};
#endif
