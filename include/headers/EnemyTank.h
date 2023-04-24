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
	int enemy_count_bullet = 0;
	bool bulletActive = 0;
	bool is_enemy_tank_alive = true;
public:
	EnemyTank()
	{
		this->is_enemy_tank_alive = true;
		setTankHp(20);
		setWeapon(0);
	}
	EnemyTank(std::string str)
	{
		setPath(str);
	}
	/*bool getIsEnemyTankAlive()
	{
		return this->is_enemy_tank_alive;
	}
	void setIsEnemyTankAlive(bool check)
	{
		this->is_enemy_tank_alive = check;
	}*/
	int randomActive()
	{
		return rand() % 2;
	}
	bool getBulletActive()
	{
		return this->bulletActive;
	}
	void setBulletActive(bool x)
	{
		this->bulletActive = x;
	}
	void myTankEnemyMoveX(Map** walls)
	{
		//handleTankEnemyCollision(tank);
		for (int i = 0; i < mapRows; i++)
		{
			for (int j = 0; j < mapCols; j++)
			{
				if (walls[i][j].getValue() != 0 && walls[i][j].getValue() < 11 || (walls[i][j].getValue() > 20 && walls[i][j].getValue() <= 30))
					handleTankObstacleCollision(walls[i][j]);
				else if (walls[i][j].getValue() == 14)
					handleTankEnemyLandmineCollistion(walls[i][j]);
				else if (walls[i][j].getValue() > 50)
					handleGiftCollistion(walls[i][j]);
			}
		}
		this->setOriginalXpos(this->getXpos());
		rect_.x += getvX();
		/*for (int i = 0; i < enemySize; i++)
		{
			handleTankEnemyCollision(list[i]);
		}*/
		if (rect_.x + rect_.w >= screenWidth)
		{
			rect_.x = screenWidth - rect_.w;
		}
		if (rect_.x <= 0)
		{
			rect_.x = 0;
		}
	}
	void MyTankEnemyMoveY(Map** walls)
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
			//handleTankEnemyCollision(tank);
			for (int i = 0; i < mapRows; i++)
			{
				for (int j = 0; j < mapCols; j++)
				{
					if (walls[i][j].getValue() != 0 && walls[i][j].getValue() < 11 || (walls[i][j].getValue() > 20 && walls[i][j].getValue() <= 30))
						handleTankObstacleCollision(walls[i][j]);
					else if (walls[i][j].getValue() == 14)
						handleTankEnemyLandmineCollistion(walls[i][j]);
					else if (walls[i][j].getValue() > 50)
						handleGiftCollistion(walls[i][j]);
				}
			}
			this->setOriginalypos(this->getYpos());
			rect_.y += getvY();
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
	void handleAtiveTankEnemyA(Tank &tank)
	{
		setOriginalXpos(getXpos());
		setOriginalypos(getYpos());
		int x = rand() % 3;
		if (enemy_move_count > 0)
		{
			enemy_move_count -= 1;
			if (getAngle() == 0)
			{
				setvY(-vNormal);
				if (rect_.y <= 0)
				{
					rect_.x = getOriginalXpos();
					rect_.y = vNormal;
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 180)
			{
				setvY(vNormal);
				if (rect_.y + rect_.h >= scrennHeight)
				{
					rect_.y = scrennHeight - rect_.h;
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 90)
			{
				setvX(vNormal);
				if (rect_.x <= 0)
				{
					rect_.x = 0;
					rect_.y = getOriginalYpos();
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 270)
			{
				setvX(-vNormal);
				if (rect_.x + rect_.w >= screenWidth)
				{
					rect_.x = screenWidth - rect_.w;
					enemy_move_count = 0;
				}
			}
		}
		else if (x == 0)
		{
			enemy_move_count = 5;
			setBulletActive(false);
		}
		else if (x == 1)
		{
			int thisEnemyTankPosX = getXpos();
			int thisEnemyTankPosY = getYpos();
			int TankPosX = tank.getXpos();
			int TankPosY = tank.getYpos();
			int randomAngle = rand() % 4;
			if (randomAngle % 2 == 0)
			{
				if (thisEnemyTankPosX < TankPosX)
				{
					setAngle(90);
				}
				else
				{
					setAngle(270);
				}
			}
			else
			{
				setvX(0);
				if (thisEnemyTankPosY < TankPosY)
				{
					setAngle(180);
				}
				else
				{
					setAngle(0);
				}
			}
			/*if (randomAngle == 0 || randomAngle == 2)
			{
				setvX(0);
			}*/
			//setAngle(randomAngle * 90);
			setBulletActive(false); 
		}
		else if (x==2)
		{
			setvX(0);
			setvY(0);
			if (tank.getIsTankAlive() && enemy_count_bullet == 0)
			{
				setBulletActive(true);
				enemy_count_bullet = 8;
			}
			else
			{
				enemy_count_bullet --;
			}
			enemy_move_count = 0;
		}
	}
	void handleAtiveTankEnemyB(Tank &tank)
	{
		setOriginalXpos(getXpos());
		setOriginalypos(getYpos());
		int x = rand() % 3;
		if (enemy_move_count > 0)
		{
			enemy_move_count -= 1;
			if (getAngle() == 0)
			{
				setvY(-vSpeedUp);
				if (rect_.y <= 0)
				{
					rect_.x = getOriginalXpos();
					rect_.y = vSpeedUp;
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 180)
			{
				setvY(vSpeedUp);
				if (rect_.y + rect_.h >= scrennHeight)
				{
					rect_.y = scrennHeight - rect_.h;
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 90)
			{
				setvX(vSpeedUp);
				if (rect_.x <= 0)
				{
					rect_.x = 0;
					rect_.y = getOriginalYpos();
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 270)
			{
				setvX(-vSpeedUp);
				if (rect_.x + rect_.w >= screenWidth)
				{
					rect_.x = screenWidth - rect_.w;
					enemy_move_count = 0;
				}
			}
		}
		else if (x == 0)
		{
			enemy_move_count = 5;
			setBulletActive(false);
		}
		else if (x == 1)
		{
			int thisEnemyTankPosX = getXpos();
			int thisEnemyTankPosY = getYpos();
			int TankPosX = tank.getXpos();
			int TankPosY = tank.getYpos();
			int randomActive = rand() %100;
			if (randomActive<80)
			{
				int randomAngle = rand() % 4;
				if (randomAngle % 2 == 0)
				{
					if (thisEnemyTankPosX < TankPosX)
					{
						setAngle(90);
					}
					else
					{
						setAngle(270);
					}
				}
				else
				{
					setvX(0);
					if (thisEnemyTankPosY < TankPosY)
					{
						setAngle(180);
					}
					else
					{
						setAngle(0);
					}
				}
			}
			else
			{
				int randomAngle = rand() %4;
				if (randomAngle == 0 || randomAngle == 2)
				{
					setvX(0);
				}
				setAngle(randomAngle * 90);
			}
			setBulletActive(false); 
		}
		else if (x==2)
		{
			setvX(0);
			setvY(0);
			if (tank.getIsTankAlive() && enemy_count_bullet == 0)
			{
				setBulletActive(true);
				enemy_count_bullet = 8;
			}
			else
			{
				enemy_count_bullet --;
			}
			enemy_move_count = 0;
		}
	}
	void handleAtiveTankEnemyC(Tank &tank)
	{
		setOriginalXpos(getXpos());
		setOriginalypos(getYpos());
		int x = rand() % 3;
		if (enemy_move_count > 0)
		{
			enemy_move_count -= 1;
			if (getAngle() == 0)
			{
				setvY(-vNormal);
				if (rect_.y <= 0)
				{
					rect_.x = getOriginalXpos();
					rect_.y = vNormal;
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 180)
			{
				setvY(vNormal);
				if (rect_.y + rect_.h >= scrennHeight)
				{
					rect_.y = scrennHeight - rect_.h;
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 90)
			{
				setvX(vNormal);
				if (rect_.x <= 0)
				{
					rect_.x = 0;
					rect_.y = getOriginalYpos();
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 270)
			{
				setvX(-vNormal);
				if (rect_.x + rect_.w >= screenWidth)
				{
					rect_.x = screenWidth - rect_.w;
					enemy_move_count = 0;
				}
			}
		}
		else if (x == 0)
		{
			enemy_move_count = 5;
			setBulletActive(false);
		}
		else if (x == 1)
		{
			int thisEnemyTankPosX = getXpos();
			int thisEnemyTankPosY = getYpos();
			int TankPosX = tank.getXpos();
			int TankPosY = tank.getYpos();
			int randomActive = rand() %100;
			if (randomActive<50)
			{
				int randomAngle = rand() % 4;
				if (randomAngle % 2 == 0)
				{
					if (thisEnemyTankPosX < TankPosX)
					{
						setAngle(90);
					}
					else
					{
						setAngle(270);
					}
				}
				else
				{
					setvX(0);
					if (thisEnemyTankPosY < TankPosY)
					{
						setAngle(180);
					}
					else
					{
						setAngle(0);
					}
				}
			}
			else
			{
				int randomAngle = rand() %4;
				if (randomAngle == 0 || randomAngle == 2)
				{
					setvX(0);
				}
				setAngle(randomAngle * 90);
			}
			setBulletActive(false); 
		}
		else if (x==2)
		{
			setvX(0);
			setvY(0);
			if (tank.getIsTankAlive() && enemy_count_bullet == 0)
			{
				setBulletActive(true);
				enemy_count_bullet = 8;
			}
			else
			{
				enemy_count_bullet --;
			}
			enemy_move_count = 0;
		}
	}
	void handleAtiveTankEnemyD(Tank &tank)
	{
		setOriginalXpos(getXpos());
		setOriginalypos(getYpos());
		int x = rand() % 3;
		if (enemy_move_count > 0)
		{
			enemy_move_count -= 1;
			if (getAngle() == 0)
			{
				setvY(-vSpeedUp);
				if (rect_.y <= 0)
				{
					rect_.x = getOriginalXpos();
					rect_.y = vSpeedUp;
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 180)
			{
				setvY(vSpeedUp);
				if (rect_.y + rect_.h >= scrennHeight)
				{
					rect_.y = scrennHeight - rect_.h;
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 90)
			{
				setvX(vSpeedUp);
				if (rect_.x <= 0)
				{
					rect_.x = 0;
					rect_.y = getOriginalYpos();
					enemy_move_count = 0;
				}
			}
			else if (getAngle() == 270)
			{
				setvX(-vSpeedUp);
				if (rect_.x + rect_.w >= screenWidth)
				{
					rect_.x = screenWidth - rect_.w;
					enemy_move_count = 0;
				}
			}
		}
		else if (x == 0)
		{
			enemy_move_count = 5;
			setBulletActive(false);
		}
		else if (x == 1)
		{
			int thisEnemyTankPosX = getXpos();
			int thisEnemyTankPosY = getYpos();
			int TankPosX = tank.getXpos();
			int TankPosY = tank.getYpos();
			int randomAngle = rand() % 4;
			if (randomAngle % 2 == 0)
			{
				if (thisEnemyTankPosX < TankPosX)
				{
					setAngle(90);
				}
				else
				{
					setAngle(270);
				}
			}
			else
			{
				setvX(0);
				if (thisEnemyTankPosY < TankPosY)
				{
					setAngle(180);
				}
				else
				{
					setAngle(0);
				}
			}
			/*if (randomAngle == 0 || randomAngle == 2)
			{
				setvX(0);
			}*/
			//setAngle(randomAngle * 90);
			setBulletActive(false); 
		}
		else if (x==2)
		{
			setvX(0);
			setvY(0);
			if (tank.getIsTankAlive() && enemy_count_bullet == 0)
			{
				setBulletActive(true);
				enemy_count_bullet = 8;
			}
			else
			{
				enemy_count_bullet --;
			}
			enemy_move_count = 0;
		}
	}
	void handleTankEnemyLandmineCollistion(Map& obstacle)
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
			ani.setXYpos(obstacle.getXpos(), obstacle.getYpos());
			ani.render(g_screen, NULL);
			setXYpos(5000, 5000);
			free();
			setIsTankAlive(false);
			obstacle.setValue(32);
			obstacle.free();
		}
	}
};
#endif
