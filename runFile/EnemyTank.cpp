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
						enemy_count_bullet = 4;
						}
						else
						{
							setBulletActive(false);
							enemy_count_bullet --;
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
				enemy_count_bullet = 4;
			}
			else
			{
				setBulletActive(false);
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
			setBulletActive(true);
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
			//obstacle.setValue(32);
			obstacle.free();
		}
	}
	void EnemyTank::handleTankEnemyMap()
	{
		int randomchoice=rand()%100;
		if (randomchoice <40)
		{
			setBulletActive(true);
		}
		else
		{
			int randomAngle=rand()%100;
			int anglePresent=getAngle();
			if (randomAngle<25 && getAngle()!=90)
			{
				setAngle(90);
			}
			else if (randomAngle>=25 && getAngle()!=180 && randomAngle<50)
			{
				setAngle(180);
			}
			else if (randomAngle>=50 && randomAngle<75 && getAngle()!=270)
			{
				setAngle(270);
			}
			else if (randomAngle>=75 && randomAngle<=99 && getAngle()!=0)
			{
				setAngle(0);
			}
		}
	}
	void EnemyTank::EnemyTankMoveX(Map** walls,SDL_Renderer *g_screen,Tank &tankEnemy,EnemyTank *listenEnemy,int sizeOfTankEnemy,int index)
	{
		setOriginalXpos(getXpos());
		rect_.x += getvX();
		for (int i = 0; i < mapRows; i++)
		{
			for (int j = 0; j < mapCols; j++)
			{
				if (walls[i][j].getValue()!=0 && walls[i][j].getValue() < 11 || (walls[i][j].getValue()>20 && walls[i][j].getValue() <= 30) || (walls[i][j].getValue()==13) || (walls[i][j].getValue()==100))
					handleTankObstacleCollision(walls[i][j]);
				else if (walls[i][j].getValue() == 14)
					handleTankLandmineCollistion(walls[i][j],g_screen);
				else if (walls[i][j].getValue()>50 )
					handleGiftCollistion(walls[i][j]);
			}
		}
		handleTankEnemyCollistion(tankEnemy); 
		handleListTankEnemyCollistion(listenEnemy,sizeOfTankEnemy,index);
		if (rect_.x + rect_.w >= screenWidth)
		{
			rect_.x = screenWidth - rect_.w;
		}
		if (rect_.x <= 0)
		{
			rect_.x = 0;
		}
	}
	void EnemyTank::EnemyTankMoveY(Map** walls,SDL_Renderer *g_screen,Tank &tankEnemy,EnemyTank *listenEnemy,int sizeOfTankEnemy,int index)
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
			setOriginalypos(getYpos());
			rect_.y += getvY();
			for (int i = 0; i < mapRows; i++)
			{
				for (int j = 0; j < mapCols; j++)
				{
					if (walls[i][j].getValue() != 0 && walls[i][j].getValue() < 11 || (walls[i][j].getValue() > 20 && walls[i][j].getValue() <= 30) || (walls[i][j].getValue()==13) || (walls[i][j].getValue()==100))
					{	
						handleTankObstacleCollision(walls[i][j]);
						EnemyCheckMap(walls[i][j]);
					}
					else if (walls[i][j].getValue() == 14)
					{
						handleTankLandmineCollistion(walls[i][j],g_screen);
						//EnemyCheckMap(walls[i][j]);
					}
					else if (walls[i][j].getValue() > 50)
						handleGiftCollistion(walls[i][j]);
				}
			}
			handleTankEnemyCollistion(tankEnemy); 
			handleListTankEnemyCollistion(listenEnemy,sizeOfTankEnemy,index);
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
	void EnemyTank::EnemyCheckMap(Map& obstacle)
	{
		SDL_Rect tankRect = { getXpos(), getYpos(), getWidth(), getHeight()};
		SDL_Rect mapRect = { obstacle.getXpos(), obstacle.getYpos(), obstacle.getWidth(), obstacle.getHeight()};
		if (checkCollision(tankRect, mapRect))
		{
			handleTankEnemyMap();
		}
	}
	void EnemyTank::handleTankEnemyCollistion(Tank &EnemyTank)
	{
		SDL_Rect tankRect = { getXpos(), getYpos(), getWidth(), getHeight()};
		SDL_Rect enemyTankRect = { EnemyTank.getXpos(), EnemyTank.getYpos(), EnemyTank.getWidth(), EnemyTank.getHeight()};
		if(checkCollision(tankRect, enemyTankRect))
		{
			setvX(0);
			setvY(0);
			EnemyTank.setvX(0);
			EnemyTank.setvY(0);
			setXYpos(getOriginalXpos(),getOriginalYpos());
			EnemyTank.setXYpos(EnemyTank.getOriginalXpos(),EnemyTank.getOriginalYpos());
		}
	}
	void EnemyTank::handleListTankEnemyCollistion(EnemyTank *listEnemy,int sizeOfTankEnemy,int index)
	{
		for(int i = 0; i < sizeOfTankEnemy;i++)
		{
			if(i!=index)
			{
				handleTankEnemyCollistion(listEnemy[i]);
			}
		}
	}
	void EnemyTank::handleTankAI_2(Map **walls,Tank& tank)
	{
		int x=rand()%3;
		if(enemy_move_count>0)
		{
			enemy_move_count--;
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
		else
		{
			int choice = rand()%100;
			bool check=false;
			for (int i=0;i<mapRows;i++)
			{
				for (int j=0;j<mapCols;j++)
				{
					if(checkMapCollision(walls[i][j]))
					{
						check=true;
						break;
					}
				}
			}
			check_map_collision=check;
			if(check_map_collision)
			{
				int choice=rand()%100;
				if(choice<60)
				{	
					int randomAngle=rand()%4;
					setAngle(randomAngle*90);
				}
				else
				{
					setBulletActive(true);
				}	
				enemy_move_count=1;
				//}
			}
			else 
			{
					int thisEnemyTankPosX = getXpos();
					int thisEnemyTankPosY = getYpos();
					int TankPosX = tank.getXpos();
					int TankPosY = tank.getYpos();
					if (thisEnemyTankPosX<=TankPosX+tank.getWidth()/2 && thisEnemyTankPosX>=TankPosX)
					{
						if (thisEnemyTankPosY>=TankPosY)
						{
							setAngle(0);
						}
						else
						{
							setAngle(180);
						}
						if(enemy_count_bullet==0)
						{
							setBulletActive(true); 
							enemy_count_bullet=2;
						}
						else
						{
							enemy_count_bullet--;
							setBulletActive(false); 
						}
					}
					if (thisEnemyTankPosY<=TankPosY+tank.getHeight()/2 && thisEnemyTankPosY>=TankPosY)
					{
						if (thisEnemyTankPosX>=TankPosX)
						{
							setAngle(270);
						}
						else{
							setAngle(90);
						}
						if(enemy_count_bullet==0)
						{
							setBulletActive(true); 
							enemy_count_bullet=2;
						}
						else
						{
							enemy_count_bullet--;
							setBulletActive(false); 
						}
					}
				if (x == 0)
				{
					enemy_move_count = 5;
					setBulletActive(false);
				}
				else if (x == 1)
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
				else if (x==2)
				{
					setvX(0);
					setvY(0);
					if(enemy_count_bullet==0)
					{
						setBulletActive(true); 
						enemy_count_bullet=2;
					}
					else
					{
						enemy_count_bullet--;
						setBulletActive(false); 
					}
					enemy_move_count = 0;
				}
			}
		}
	}
	void EnemyTank::handleTankAI_4(Map **walls,Tank& tank)
	{
		int x=rand()%3;
		if(enemy_move_count>0)
		{
			enemy_move_count--;
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
		else
		{
			int choice = rand()%100;
			bool check=false;
			for (int i=0;i<mapRows;i++)
			{
				for (int j=0;j<mapCols;j++)
				{
					if(checkMapCollision(walls[i][j]))
					{
						check=true;
						break;
					}
				}
			}
			check_map_collision=check;
			if(check_map_collision)
			{
				int choice=rand()%100;
				if(choice<60)
				{	
					int randomAngle=rand()%4;
					setAngle(randomAngle*90);
				}
				else
				{
					setBulletActive(true);
				}	
				enemy_move_count=1;
				//}
			}
			else 
			{
					int thisEnemyTankPosX = getXpos();
					int thisEnemyTankPosY = getYpos();
					int TankPosX = tank.getXpos();
					int TankPosY = tank.getYpos();
					if (thisEnemyTankPosX<=TankPosX+tank.getWidth()/2 && thisEnemyTankPosX>=TankPosX)
					{
						if (thisEnemyTankPosY>=TankPosY)
						{
							setAngle(0);
						}
						else
						{
							setAngle(180);
						}
						if(enemy_count_bullet==0)
						{
							setBulletActive(true); 
							enemy_count_bullet=4;
						}
						else
						{
							enemy_count_bullet--;
							setBulletActive(false); 
						}
					}
					if (thisEnemyTankPosY<=TankPosY+tank.getHeight()/2 && thisEnemyTankPosY>=TankPosY)
					{
						if (thisEnemyTankPosX>=TankPosX)
						{
							setAngle(270);
						}
						else{
							setAngle(90);
						}
						if(enemy_count_bullet==0)
						{
							setBulletActive(true); 
							enemy_count_bullet=4;
						}
						else
						{
							enemy_count_bullet--;
							setBulletActive(false); 
						}
					}
				if (x == 0)
				{
					enemy_move_count = 6;
					setBulletActive(false);
				}
				else if (x == 1)
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
				else if (x==2)
				{
					setvX(0);
					setvY(0);
					if(enemy_count_bullet==0)
					{
						setBulletActive(true); 
						enemy_count_bullet=4;
					}
					else
					{
						enemy_count_bullet--;
						setBulletActive(false); 
					}
					enemy_move_count = 0;
				}
			}
		}
	}
	void EnemyTank::handleTankAI_6(Map **walls,Tank& tank)
	{
		int x=rand()%3;
		if(enemy_move_count>0)
		{
			enemy_move_count--;
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
		else
		{
			int choice = rand()%100;
			bool check=false;
			for (int i=0;i<mapRows;i++)
			{
				for (int j=0;j<mapCols;j++)
				{
					if(checkMapCollision(walls[i][j]))
					{
						check=true;
						break;
					}
				}
			}
			check_map_collision=check;
			if(check_map_collision)
			{
				int choice=rand()%100;
				if(choice<60)
				{	
					int randomAngle=rand()%4;
					setAngle(randomAngle*90);
				}
				else
				{
					setBulletActive(true);
				}	
				enemy_move_count=1;
				//}
			}
			else 
			{
					int thisEnemyTankPosX = getXpos();
					int thisEnemyTankPosY = getYpos();
					int TankPosX = tank.getXpos();
					int TankPosY = tank.getYpos();
					if (thisEnemyTankPosX<=TankPosX+tank.getWidth()/2 && thisEnemyTankPosX>=TankPosX)
					{
						if (thisEnemyTankPosY>=TankPosY)
						{
							setAngle(0);
						}
						else
						{
							setAngle(180);
						}
						if(enemy_count_bullet==0)
						{
							setBulletActive(true); 
							enemy_count_bullet=6;
						}
						else
						{
							enemy_count_bullet--;
							setBulletActive(false); 
						}
					}
					if (thisEnemyTankPosY<=TankPosY+tank.getHeight()/2 && thisEnemyTankPosY>=TankPosY)
					{
						if (thisEnemyTankPosX>=TankPosX)
						{
							setAngle(270);
						}
						else{
							setAngle(90);
						}
						if(enemy_count_bullet==0)
						{
							setBulletActive(true); 
							enemy_count_bullet=6;
						}
						else
						{
							enemy_count_bullet--;
							setBulletActive(false); 
						}
					}
				if (x == 0)
				{
					enemy_move_count = 8;
					setBulletActive(false);
				}
				else if (x == 1)
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
				else if (x==2)
				{
					setvX(0);
					setvY(0);
					if(enemy_count_bullet==0)
					{
						setBulletActive(true); 
						enemy_count_bullet=6;
					}
					else
					{
						enemy_count_bullet--;
						setBulletActive(false); 
					}
					enemy_move_count = 0;
				}
			}
		}
	}
	void EnemyTank::handleTankAI_8(Map **walls,Tank& tank)
	{
		int x=rand()%3;
		if(enemy_move_count>0)
		{
			enemy_move_count--;
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
		else
		{
			int choice = rand()%100;
			bool check=false;
			for (int i=0;i<mapRows;i++)
			{
				for (int j=0;j<mapCols;j++)
				{
					if(checkMapCollision(walls[i][j]))
					{
						check=true;
						break;
					}
				}
			}
			check_map_collision=check;
			if(check_map_collision)
			{
				int choice=rand()%100;
				if(choice<60)
				{	
					int randomAngle=rand()%4;
					setAngle(randomAngle*90);
				}
				else
				{
					setBulletActive(true);
				}	
				enemy_move_count=1;
				//}
			}
			else 
			{
					int thisEnemyTankPosX = getXpos();
					int thisEnemyTankPosY = getYpos();
					int TankPosX = tank.getXpos();
					int TankPosY = tank.getYpos();
					if (thisEnemyTankPosX<=TankPosX+tank.getWidth()/2 && thisEnemyTankPosX>=TankPosX)
					{
						if (thisEnemyTankPosY>=TankPosY)
						{
							setAngle(0);
						}
						else
						{
							setAngle(180);
						}
						if(enemy_count_bullet==0)
						{
							setBulletActive(true); 
							enemy_count_bullet=8;
						}
						else
						{
							enemy_count_bullet--;
							setBulletActive(false); 
						}
					}
					if (thisEnemyTankPosY<=TankPosY+tank.getHeight()/2 && thisEnemyTankPosY>=TankPosY)
					{
						if (thisEnemyTankPosX>=TankPosX)
						{
							setAngle(270);
						}
						else{
							setAngle(90);
						}
						if(enemy_count_bullet==0)
						{
							setBulletActive(true); 
							enemy_count_bullet=8;
						}
						else
						{
							enemy_count_bullet--;
							setBulletActive(false); 
						}
					}
				if (x == 0)
				{
					enemy_move_count = 10;
					setBulletActive(false);
				}
				else if (x == 1)
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
				else if (x==2)
				{
					setvX(0);
					setvY(0);
					if(enemy_count_bullet==0)
					{
						setBulletActive(true); 
						enemy_count_bullet=8;
					}
					else
					{
						enemy_count_bullet--;
						setBulletActive(false); 
					}
					enemy_move_count = 0;
				}
			}
		}
	}

	bool EnemyTank::checkMapCollision(Map& obstacle)
	{
		SDL_Rect tank_rect = {getXpos(),getYpos(),getWidth(),getHeight()};
		SDL_Rect map_rect={obstacle.getXpos(),obstacle.getYpos(),obstacle.getWidth(),obstacle.getHeight()};
		if (checkCollision(tank_rect,map_rect))
		{
			return true;
		}
		return false;
	}