#include "Tank.h"

    Tank::Tank()
	{
		path = "img//my_tank_2.png";
		vX = 0;
		vY = 0;
		this->tank_hp = 20;
		healthBar.x = getXpos()+2;
		healthBar.y = getYpos()-15;
		healthBar.w = 2*getTankHp();
		healthBar.h = 10;
	}
	SDL_Rect Tank::getHealBar()
	{
		return healthBar;
	}
	void Tank::setTimeDefender(int time_defender)
	{
		count_time_defender=time_defender;
	}
	int Tank::getTimeDefender()
	{
		return count_time_defender;
	}
	void Tank::setTankIsProtected(bool check)
	{
		tankIsProtected = check;
	}
	bool Tank::getTankIsProtected()
	{
		return tankIsProtected;
	}
	void Tank::setTankHp(int x)
	{
		this->tank_hp = x;
	}
	int Tank::getTankHp()
	{
		return this->tank_hp;
	}
	void Tank::updateHealBar()
	{
		this->healthBar.x = getXpos()+2;
		this->healthBar.y=getYpos()-15;
		this->healthBar.w =getTankHp()*2;
	}
	void Tank::setWeapon(int x)
	{
		this->weapon = x;
	}
	int Tank::getWeapon()
	{
		return this->weapon;
	}
	bool Tank::getIsTankAlive()
	{
		return this->is_tank_alive;
	}
	void Tank::setIsTankAlive(bool check)
	{
		this->is_tank_alive = check;
	}
	Tank::Tank(std::string path)
	{
		this->path = path;
	}
	double Tank::getAngle()
	{
		return this->angle;
	}
	void Tank::setAngle(int x)
	{
		this->angle = x;
	}
	void Tank::setvX(int v)
	{
		this->vX = v;
	}
	void Tank::setvY(int v)
	{
		this->vY=v;
	}
	int Tank::getvX()
	{
		return this->vX;
	}
	int Tank::getvY()
	{
		return this->vY;
	}
	void Tank::setPath(std::string path)
	{
		this->path = path;
	}
	std::string Tank::getPath()
	{
		return this->path;
	}
	int Tank::getOriginalXpos()
	{
		return originalXpos;
	}
	int Tank::getOriginalYpos()
	{
		return originalYpos;
	}
	bool Tank::loadTank(SDL_Renderer*g_screen)
	{
		bool ret = loadImg(getPath(), g_screen);
		if (ret == false)
		{
			return false;
		}
		return true;
	}
	void Tank::setOriginalXpos(int x)
	{
		this->originalXpos = x;
	}
	void Tank::setOriginalypos(int y)
	{
		this->originalYpos = y;
	}
	void Tank::handleEvents(SDL_Event& e,Map**walls)
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
	bool Tank::checkCollision(SDL_Rect rect1, SDL_Rect rect2)
	{
		// int left1 = rect1.x;
		// int right1 = rect1.x + rect1.w;
		// int top1 = rect1.y;
		// int bottom1 = rect1.y + rect1.h;
		// int left2 = rect2.x;
		// int right2 = rect2.x + rect2.w;
		// int top2 = rect2.y;
		// int bottom2 = rect2.y + rect2.h;

		
		// if (left1 >= right2 || right1 <= left2 || top1 >= bottom2 || bottom1 <= top2)
		// {
		// 	return false;
		// }
		// else
		// {
		// 	return true;
		// }
		if (SDL_HasIntersection(&rect1, &rect2))
		{
			return true;
		}
		else{
			return false;
		}
	}
	void Tank::myTankMoveX(Map** walls,SDL_Renderer *g_screen)
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
		if (rect_.x + rect_.w >= screenWidth)
		{
			rect_.x = screenWidth - rect_.w;
		}
		if (rect_.x <= 0)
		{
			rect_.x = 0;
		}
	}
	void Tank::MyTankMoveY(Map** walls,SDL_Renderer *g_screen)
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
						handleTankObstacleCollision(walls[i][j]);
					else if (walls[i][j].getValue() == 14)
						handleTankLandmineCollistion(walls[i][j],g_screen);
					else if (walls[i][j].getValue() > 50)
						handleGiftCollistion(walls[i][j]);
				}
			}
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
	void Tank::handleTankObstacleCollision (Map& obstacle)
	{
		SDL_Rect tankRect = { getXpos(), getYpos(), getWidth(), getHeight()};
		SDL_Rect mapRect = { obstacle.getXpos(), obstacle.getYpos(), obstacle.getWidth(), obstacle.getHeight()};
		if (checkCollision(tankRect, mapRect))
		{
			// if (angle == 90)
			// {
			// 	setXYpos(obstacle.getXpos() - this->getWidth() -2, getOriginalYpos());
			// 	setvX(0);
			// 	setvY(0);
			// }
			// else if (angle == 270)
			// {
			// 	setXYpos(obstacle.getXpos() + obstacle.getWidth() + 2, getOriginalYpos());
			// 	setvX(0);
			// 	setvY(0);
			// }
			// else if (angle == 0)
			// {
			// 	setXYpos(getOriginalXpos(), obstacle.getYpos() + obstacle.getHeight() + 2);
			// 	setvX(0);
			// 	setvY(0);
			// }
			// else if (angle==180)
			// {
			// 	setXYpos(getOriginalXpos(), obstacle.getYpos() - this->getHeight() - 2);
			// 	setvX(0);
			// 	setvY(0);
			// }
			vX=0;
			vY=0;
			setXYpos(getOriginalXpos(),getOriginalYpos());
		}
	}
	void Tank::handleTankEnemyCollision(Tank& tankEnemy)
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
		}
	}
	void Tank::handleTankLandmineCollistion(Map& obstacle,SDL_Renderer *g_screen)
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
			//obstacle.setValue(32);
			obstacle.free();
		}
	}
	void Tank::handleGiftCollistion(Map& obstacle)
	{
		SDL_Rect tankRect = { getXpos(), getYpos(), getWidth(), getHeight() };
		SDL_Rect mapRect = { obstacle.getXpos(), obstacle.getYpos(), obstacle.getWidth(), obstacle.getHeight() };
		if (checkCollision(tankRect, mapRect))
		{	
			if (obstacle.getValue()<53)
				setWeapon(obstacle.getValue()-50);
			else if (obstacle.getValue()==53)
			{
				if (getTankHp()+10 <= 20)
					setTankHp(getTankHp() + 10);
				else
					setTankHp(health);
			}
			else if (obstacle.getValue()==54)
			{
				this->tankIsProtected=true;
				this->count_time_defender=100;
			}
			obstacle.setValue(0);
			obstacle.free();
			std::cout << getWeapon() << std::endl;
		}
	}
	void Tank::checkBoomEffect(int boomEffectPosX,int boomEffectPosY)
	{
		int tankPosX=this->getXpos();
		int tankPosY=this->getYpos();
		if (tankPosX>=boomEffectPosX && tankPosX<=boomEffectPosX+300 && tankPosY>=boomEffectPosY && tankPosY<=boomEffectPosY+224)
		{
			this->setIsTankAlive(false);
			this->setXYpos(5000,5000);
			this->free();
		}  
		// 300,224 là chiều rộng, chiều cao phạm vi nổ boom
	}