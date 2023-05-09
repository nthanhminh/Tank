#include "Menu.h"

    Menu::Menu()
	{
		srand(time(0));
		setNumberOfEnemyTank(5);
		tankPath="img//tank_test.png";
		mapPath="data/data_1.txt";
		numberOfMenu=0;
	}
	void Menu::setMapPath(std::string path)
	{
		this->mapPath=path;
	}
	std::string Menu::getMapPath()
	{
		this->mapPath;
	}
	int Menu::getSizeTankBullet()
	{
		return this->sizeTankBullet;
	}
	int Menu::getNumberofEnemyTank()
	{
		return this->numberOfEnemyTank;
	}
	baseObject Menu::getBg()
	{
		return this->background;
	}
	EnemyBullet** Menu::getEnemyBullets()
	{
		return this->EnemyBullets;
	}
	Tank Menu::getTank()
	{
		return this->tank;
	}
	EnemyTank* Menu::getListEnemyTank()
	{
		return this->listEnemyTank;
	}
	Bullet* Menu::getBullet()
	{
		return this->Bullets;
	}
	Map** Menu::getMap()
	{
		return this->walls;
	}
	void Menu::setNumberOfEnemyTank(int x)
	{
		this->numberOfEnemyTank = x;
	}
	std::string Menu::getTankPath()
	{
		this->tankPath;
	}
	void Menu::setTankPath(std::string path)
	{
		this->tankPath=path;
	}
	std::string Menu::getBgPath()
	{
		return this->backgroundPath;
	}
	void Menu::setBgPath(std::string path)
	{
		this->backgroundPath = path;
	}
	void Menu::loadBg(SDL_Renderer *g_screen)
	{
		bool ret = background.loadImg(this->backgroundPath, g_screen);
		if (ret == false)
		{
			std::cout << "Can not load background";
		}
	}
	void Menu::initTank(SDL_Renderer *g_screen)
	{
		tank.setPath(this->tankPath);
		tank.setIsTankAlive(true);
		tank.setTankHp(health);
		tank.setWeapon(0);
		if (!tank.loadTank(g_screen))
		{
			std::cout << "Can not load tank";
		}
		tank.setXYpos(1000, 650);
		for (int i = 0; i < this->numberOfEnemyTank; i++)
		{
			EnemyBullets[i] = new EnemyBullet[1000];
		}
		for (int i = 0; i < this->numberOfEnemyTank; i++)
		{
			listEnemyTank[i].setXYpos(rand()%1500, 0);
			listEnemyTank[i].setPath("img//enemy_tank_test.png");
			listEnemyTank[i].setIsTankAlive(true);
			listEnemyTank[i].setTankHp(health);
			listEnemyTank[i].setWeapon(0);
		}
		for (int i = 0; i < this->numberOfEnemyTank; i++)
		{
			if (!listEnemyTank[i].loadTank(g_screen))
			{
				std::cout << "can not load tank enemy" << "  133" << std::endl;
			}
		}
	}
	void Menu::InitMap(SDL_Renderer *g_screen)
	{
		for (int i = 0; i < mapRows; i++)
		{
			walls[i] = new Map[mapCols];
		}
		Map map;
		map.setPath(this->mapPath);
		std::ifstream file;
        file.open(map.getPath());
		for (int i = 0; i < mapRows; i++)
		{
			for (int j = 0; j < mapCols; j++)
			{
				int x;
				file >> x;
				walls[i][j].setValue(x);
			}
		}
		for (int i = 0; i < mapRows; i++)
		{
			for (int j = 0; j < mapCols; j++)
			{
				std::cout << walls[i][j].getValue() << " ";
				walls[i][j].setXYpos(j * 50, i * 50);
				walls[i][j].loadMap(g_screen);
			}
			std::cout << "\n";
		}
	}
	void Menu::setSizeTankBullet()
	{
		sizeTankBullet=0;
	}
	void Menu::setSizeEnemyTankBullet(int i)
	{
		sizeEnemyTankBulluets[i]=0;
	}
	void Menu::free()
	{
		sizeTankBullet=0;
		for (int i=0;i<numberOfEnemyTank;i++)
		{
			sizeEnemyTankBulluets[i]=0;
		}
		for (int i = 0; i < sizeTankBullet; i++)
		{
			Bullets[i].setXYpos(2000,2000);
		    Bullets[i].free();
			Bullets[i].setVx(0);
			Bullets[i].setVy(0);
		}
		for (int i=0;i<numberOfEnemyTank; i++)
		{
			for (int j=0;j<sizeEnemyTankBulluets[i]; j++)
			{
				EnemyBullets[i][j].setXYpos(2000,2000);
				EnemyBullets[i][j].free();
				EnemyBullets[i][j].setVx(0);
				EnemyBullets[i][j].setVy(0);
			}
		}
		for (int i = 0; i < mapRows; i++)
		{
		    for (int j = 0; j < mapCols; j++)
		    {
				walls[i][j].setXYpos(2000,2000);
		        walls[i][j].free();
		    }
		}
	}
	void Menu::close()
	{
		delete[]listEnemyTank;
		//detroy bullet
		for (int i = 0; i < sizeTankBullet; i++)
		{
		    Bullets[i].free();
		}
		for (int i=0;i<numberOfEnemyTank; i++)
		{
			for (int j=0;j<sizeEnemyTankBulluets[i]; j++)
			{
				EnemyBullets[i][j].free();
			}
		}
		delete[]Bullets;
		//detroy map
		for (int i = 0; i < mapRows; i++)
		{
		    for (int j = 0; j < mapCols; j++)
		    {
		        walls[i][j].free();
		    }
		}
		delete[] walls;
	}