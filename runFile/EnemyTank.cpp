#include "EnemyTank.h"

    EnemyTank::EnemyTank()
	{
		this->is_enemy_tank_alive = true;
		setTankHp(20);
		setWeapon(0);
	}
	EnemyTank::EnemyTank(std::string str)
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
	int EnemyTank::randomActive()
	{
		return rand() % 2;
	}
	bool EnemyTank::getBulletActive()
	{
		return this->bulletActive;
	}
	void EnemyTank::setBulletActive(bool x)
	{
		this->bulletActive = x;
	}
	void EnemyTank::handleAtiveTankEnemyA(Tank &tank)
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
	void EnemyTank::handleAtiveTankEnemyB(Tank &tank)
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
			int HomePosX = screenWidth/2;
			int HomePosY = scrennHeight-100;
			int randomActive = rand() %100;
			if (randomActive<80)
			{
				int randomAngle = rand() % 4;
				if (thisEnemyTankPosY>=HomePosY && thisEnemyTankPosY<=scrennHeight)
				{
					if (thisEnemyTankPosX<HomePosX)
					{
						setAngle(90);
						if (enemy_count_bullet==0)
						{
							setBulletActive(true);
							enemy_count_bullet=8;
						}
						else
						{
							enemy_count_bullet--;
						}
					}
				}
				else
				{
						if(thisEnemyTankPosY<HomePosY)
						{
							setAngle(180);
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
	void EnemyTank::handleAtiveTankEnemyC(Tank &tank)
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
				if (thisEnemyTankPosX<=TankPosX+tank.getWidth()/2 && thisEnemyTankPosX>=TankPosX-tank.getWidth()/2)
				{
					if (thisEnemyTankPosY>=TankPosY)
					{
						setAngle(0);
					}
					else
					{
						setAngle(180);
					}
					if (enemy_count_bullet==0)
					{
						setBulletActive(true);
						enemy_count_bullet=4;
					}
					else{
						enemy_count_bullet--;
					}
				}
				if (thisEnemyTankPosY<=TankPosY+tank.getHeight()/2 && thisEnemyTankPosY>=TankPosY-tank.getHeight()/2)
				{
					if (thisEnemyTankPosX>=TankPosX)
					{
						setAngle(270);
					}
					else{
						setAngle(90);
					}
					if (enemy_count_bullet==0)
					{
						setBulletActive(true);
						enemy_count_bullet=4;
					}
					else{
						enemy_count_bullet--;
					}
				}
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
	void EnemyTank::handleAtiveTankEnemyD(Tank &tank)
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
			if (thisEnemyTankPosX<=TankPosX+tank.getWidth()/2 && thisEnemyTankPosX>=TankPosX-tank.getWidth()/2)
			{
				if (thisEnemyTankPosY>=TankPosY)
				{
					setAngle(0);
				}
				else
				{
					setAngle(180);
				}
				if (enemy_count_bullet==0)
				{
					setBulletActive(true);
					enemy_count_bullet=4;
				}
				else{
					enemy_count_bullet--;
				}
			}
			if (thisEnemyTankPosY<=TankPosY+tank.getHeight()/2 && thisEnemyTankPosY>=TankPosY-tank.getHeight()/2)
			{
				if (thisEnemyTankPosX>=TankPosX)
				{
					setAngle(270);
				}
				else{
					setAngle(90);
				}
				if (enemy_count_bullet==0)
				{
					setBulletActive(true);
					enemy_count_bullet=4;
				}
				else{
					enemy_count_bullet--;
				}
			}
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
		else if (x==2)
		{
			setvX(0);
			setvY(0);
			// if (tank.getIsTankAlive() && enemy_count_bullet == 0)
			// {
			// 	setBulletActive(true);
			// 	enemy_count_bullet = 8;
			// }
			// else
			// {
			// 	enemy_count_bullet --;
			// }
			enemy_move_count = 0;
		}
	}
	bool EnemyTank::checkTankPosition(Tank &tank)
	{
		int thisEnemyTankPosX = getXpos();
		int thisEnemyTankPosY = getYpos();
		int TankPosX = tank.getXpos();
		int TankPosY = tank.getYpos();
		return true;
	}
	void EnemyTank::handleTankEnemyLandmineCollistion(Map& obstacle,SDL_Renderer *g_screen)
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
			//obstacle.setValue(32);
			obstacle.free();
		}
	}