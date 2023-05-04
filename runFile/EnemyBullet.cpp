#include "EnemyBullet.h"



    EnemyBullet::EnemyBullet()
	{
		srand(time(0));
		setPath("img/bulletdark2.png");
		setVx(0);
		setVy(0);
	}
	void EnemyBullet::ap(EnemyTank& tank)
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
	void EnemyBullet::handleAutomatic(EnemyTank& enemyTank,SDL_Renderer *g_screen)
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
	void EnemyBullet::moveAuto(Tank& tankEnemy, Map** walls,Tank &this_tank,SDL_Renderer *g_screen,bool &gameOver)
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
						handleTankMapCollisionForEnemyTank(walls[i][j],tankEnemy,this_tank,g_screen,gameOver);
					}
				}
			}
			handleMyTank(tankEnemy,g_screen);
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
						handleTankMapCollisionForEnemyTank(walls[i][j],tankEnemy,this_tank,g_screen,gameOver);
					}
				}
			}
			handleMyTank(tankEnemy,g_screen);
		}
	}
	bool EnemyBullet::checkCollision(SDL_Rect rect1, SDL_Rect rect2)
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
	void EnemyBullet::handleTankMapCollisionForEnemyTank(Map& tankEnemy,Tank &tank_enemy,Tank &this_tank,SDL_Renderer *g_screen,bool &gameOver)
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
				gameOver=true;
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
				Effect.free();
				Mix_Init(MIX_INIT_MP3);
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
				Mix_Chunk* sound = Mix_LoadWAV("sound/gun9.wav");
				Mix_PlayChannel(-1, sound, 0);
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
				Mix_Init(MIX_INIT_MP3);
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
				Mix_Chunk* sound = Mix_LoadWAV("sound/gun9.wav");
				Mix_PlayChannel(-1, sound, 0);
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
				tank_enemy.checkBoomEffect(Effect.getXpos(),Effect.getYpos());
				Mix_Init(MIX_INIT_MP3);
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
				Mix_Chunk* sound = Mix_LoadWAV("sound/gun9.wav");
				Mix_PlayChannel(-1, sound, 0);
				setVx(0);
				setVy(0);
				this->setXYpos(2000, 2000);
				this->free();
				tankEnemy.setXYpos(5000,5000);
				tankEnemy.free();
				Effect.free();
				// Sau khi hiển thị xong, giải phóng hình ảnh
				// this->setXYpos(2000, 2000);
				// this->free();
				// tankEnemy.setXYpos(5000,5000);
				// tankEnemy.free();
			}
		}
	}
	void EnemyBullet::handleMyTank(Tank& tankEnemy,SDL_Renderer *g_screen)
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
				if (tankEnemy.getTankIsProtected()==false)
				{
					if(tankEnemy.getTankIsProtected()==false)
						tankEnemy.setTankHp(tankEnemy.getTankHp() - damge[getChoiceWeapon()]);
				}
				std::cout << tankEnemy.getTankHp() << std::endl;
			}
			else
			{
				tankEnemy.setIsTankAlive(false);
				tankEnemy.free();
			}
		}
	}