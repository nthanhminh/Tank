#include "Bullet.h"


    Bullet::Bullet()
	{
		srand(time(0));
		path = "img//bulletblue2.png";
		vX = 0;
		vY = 0;
		this->choice_weapon = 0;
	}
	void Bullet::setChoiceWeapon(int x)
	{
		this->choice_weapon = x;
	}
	int Bullet::getChoiceWeapon()
	{
		return this->choice_weapon;
	}
	std::string Bullet::getPath()
	{
		return path;
	}
	void Bullet::setPath(std::string str)
	{
		this->path = str;
	}
	void Bullet::setOriginalX(int x)
	{
		this->originalXpos = x;
	}
	void Bullet::setOriginalY(int x)
	{
		this->originalYpos = x;
	}
	int Bullet::getOriginalX()
	{
		return originalXpos;
	}
	int Bullet::getOriginalY()
	{
		return originalYpos;
	}
	void Bullet::setStatus(Tank& tank)
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
	int Bullet::getStatus()
	{
		return this->status;
	}
	void Bullet::setStatus(EnemyTank& tank)
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
	void Bullet::setVx(int v)
	{
		this->vX = v;
	}
	void Bullet::setVy(int y)
	{
		this->vY = y;
	}
	int Bullet::getVx()
	{
		return vX;
	}
	int Bullet::getVy()
	{
		return vY;
	}
	double Bullet::getBulletAngle()
	{
		return bulletAngle;
	}
	void Bullet::setBulletAngle(double x)
	{
		this->bulletAngle = x;
	}
	void Bullet::ap(Tank &tank)
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
	void Bullet::handleBulletEvents(SDL_Event& e,Tank& tank,Map**walls,SDL_Renderer *g_screen,AudioManager &sound)
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
					else
					{
						this->setPath("img//bulletblue2.png");
					}
					setChoiceWeapon(tank.getWeapon());
					if (!loadImg(path, g_screen))
					{
						std::cout << "can not load bullet";
					}
					ap(tank);
					sound.playSoundNoRepeat();
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
					else
					{
						this->setPath("img//bulletblue2.png");
					}
					setChoiceWeapon(tank.getWeapon());
					if (!loadImg(path, g_screen))
					{
						std::cout << "can not load bullet";
					}
						ap(tank);
						sound.playSoundNoRepeat();
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
					else
					{
						this->setPath("img//bulletblue2.png");
					}
					setChoiceWeapon(tank.getWeapon());
					if (!loadImg(path, g_screen))
					{
						std::cout << "can not load bullet";
					}
						ap(tank);
						sound.playSoundNoRepeat();
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
					else
					{
						this->setPath("img//bulletblue2.png");
					}
					setChoiceWeapon(tank.getWeapon());
					if (!loadImg(path, g_screen))
					{
						std::cout << "can not load bullet";
					}
						ap(tank);
						sound.playSoundNoRepeat();
						setVy(v_bullet);
						setStatus(tank);
				}
			}
		}
	}
	void Bullet::move(Map**walls,EnemyTank *tank,int sizeEnemyTank,Tank &this_tank,SDL_Renderer *g_screen,bool &gameOver,AudioManager &sound_collision,AudioManager &sound_tank)
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
						handleTankMapCollision(walls[i][j],tank,sizeEnemyTank,this_tank,g_screen,gameOver,sound_collision);
					}
				}
			}
			for (int i = 0; i < sizeEnemyTank; i++)
			{
				handleTankEnemy(tank[i],g_screen,sound_tank);
			}
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
						handleTankMapCollision(walls[i][j],tank,sizeEnemyTank,this_tank,g_screen,gameOver,sound_collision);
					}
				}
			}
			if (rect_.y > scrennHeight || rect_.y < 0)
			{
				this->free();
			}
			for (int i = 0; i < sizeEnemyTank; i++)
			{
				handleTankEnemy(tank[i],g_screen,sound_tank);
			}
		}
	}
	bool Bullet::checkCollision(SDL_Rect rect1, SDL_Rect rect2)
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
	void Bullet::handleTankMapCollision(Map& tankEnemy,EnemyTank *tank,int sizeEnemyTank,Tank &this_tank,SDL_Renderer *g_screen,bool &gameOver,AudioManager &sound_collision)
	{

		SDL_Rect bulletRect = { getXpos(), getYpos(), getWidth(), getHeight() };
		SDL_Rect mapRect = { tankEnemy.getXpos(), tankEnemy.getYpos(), tankEnemy.getWidth(), tankEnemy.getHeight() };

		if (checkCollision(bulletRect, mapRect))
		{
			if (tankEnemy.getValue() < 10 && tankEnemy.getValue()!=0 || tankEnemy.getValue()==23)
			{
				baseObject Effect;
				if (Effect.loadImg("img/explosion4.png", g_screen) == false)
				{
					std::cout << "Can not load effect";
				}
				Effect.setXYpos(getXpos() - Effect.getWidth() / 2, getYpos() - Effect.getHeight() / 2);
				Effect.render(g_screen, NULL);
				Effect.free();
				sound_collision.playSoundNoRepeat();
				setVx(0);
				setVy(0);
				this->setXYpos(2000, 2000);
				this->free();
				tankEnemy.setXYpos(2000, 2000);
				tankEnemy.free();
			}
			else if (tankEnemy.getValue()==100)
			{
				baseObject Effect;
				if (Effect.loadImg("img/explosion4.png", g_screen) == false)
				{
					std::cout << "Can not load effect";
				}
				Effect.setXYpos(getXpos() - Effect.getWidth() / 2, getYpos() - Effect.getHeight() / 2);
				Effect.render(g_screen, NULL);
				Effect.free();
				sound_collision.playSoundNoRepeat();
				setVx(0);
				setVy(0);
				this->setXYpos(2000, 2000);
				this->free();
				tankEnemy.setXYpos(2000, 2000);
				tankEnemy.free();
				gameOver=true;
				this_tank.setIsTankAlive(false);
				time_turn_restart=5000;
				std::cout << gameOver << std::endl;
			}
			else if (tankEnemy.getValue()==26 || tankEnemy.getValue()==27)
			{
				baseObject Effect;
				if (Effect.loadImg("img/explosion4.png", g_screen) == false)
				{
					std::cout << "Can not load effect";
				}
				Effect.setXYpos(getXpos() - Effect.getWidth() / 2, getYpos() - Effect.getHeight() / 2);
				Effect.render(g_screen, NULL);
				Effect.free();
				sound_collision.playSoundNoRepeat();
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
				Effect.free();
				sound_collision.playSoundNoRepeat();
				setVx(0);
				setVy(0);
				this->setXYpos(2000, 2000);
				this->free();
				int choice = rand() % 4;
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
				else if (choice==3) {
					bool ret = tankEnemy.loadImg("img/first_kit.png", g_screen);
					if (ret == false)
					{
						std::cout << "can not load first_kit";
					}
					tankEnemy.setValue(53);
				}
				else {
					bool ret = tankEnemy.loadImg("img/defender.png", g_screen);
					if (ret == false)
					{
						std::cout << "can not load defender";
					}
					tankEnemy.setValue(54);
				}
			}
			else if (tankEnemy.getValue()!=14 && tankEnemy.getValue() <= 50 && tankEnemy.getValue()!=13)
			{
				baseObject Effect;
				if (Effect.loadImg("img/explosion4.png", g_screen) == false)
				{
					std::cout << "Can not load effect";
				}
				Effect.setXYpos(getXpos() - Effect.getWidth() / 2, getYpos() - Effect.getHeight() / 2);
				Effect.render(g_screen, NULL);
				sound_collision.playSoundNoRepeat();
				setVx(0);
				setVy(0);
				this->setXYpos(2000, 2000);
				this->free();
			}
			else if (tankEnemy.getValue()==13)
			{
				baseObject Effect;
				if (Effect.loadImg("img/boom_effect.png", g_screen) == false)
				{
					std::cout << "Can not load effect";
				}
				Effect.setXYpos(tankEnemy.getXpos() - Effect.getWidth() / 2, tankEnemy.getYpos() - Effect.getHeight() / 2);
				Effect.render(g_screen,NULL);
				this_tank.checkBoomEffect(Effect.getXpos(),Effect.getYpos());
				for (int i=0;i<sizeEnemyTank;i++)
				{
					tank[i].checkBoomEffect(Effect.getXpos(),Effect.getYpos());
				}
				sound_collision.playSoundNoRepeat();
				setVx(0);
				setVy(0);
				this->setXYpos(2000, 2000);
				this->free();
				tankEnemy.setXYpos(5000,5000);
				tankEnemy.free();
				Effect.free();
			}
		}
	}
	void Bullet::handleTankEnemy(EnemyTank& tankEnemy,SDL_Renderer *g_screen,AudioManager &sound_tank)
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
			sound_tank.playSoundNoRepeat();
			setVx(0);
			setVy(0);
			setXYpos(2000, 2000);
			free();
			if (tankEnemy.getTankHp() - damge[getChoiceWeapon()] > 0)
			{
				if (tankEnemy.getTankIsProtected() == false)
					tankEnemy.setTankHp(tankEnemy.getTankHp() - damge[getChoiceWeapon()]);
			}
			else
			{
				tankEnemy.setIsTankAlive(false);
				tankEnemy.setXYpos(5000,5000);
				tankEnemy.free();
			}
		}
	}   