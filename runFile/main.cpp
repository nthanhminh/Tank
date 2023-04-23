#include <iostream>
#include "CommonFunc.h"
#include "BaseObject.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Map.h"
#include "Tank.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include "EnemyTank.h" 
#include "Menu.h"
//variable init
bool gameStart = false;
bool gameOver = false;
bool gameWin = false;
int cnt = 50;
Menu menu1;
Menu menu2;
baseObject gBackground;
baseObject waitingBg;
baseObject gameOverBg;
baseObject gameWinBg;
bool InitData()
{
    int ret = SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    if (ret < 0)
    {
        return false;
    }
    else
    {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        g_window = SDL_CreateWindow("TANK BATTLE",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            screenWidth, scrennHeight,
            SDL_WINDOW_SHOWN);
        if (g_window == NULL)
        {
            return false;
        }
        else
        {
            g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
            if (g_screen == NULL)
            {
                return false;
            }
            else
            {
                SDL_SetRenderDrawColor(g_screen, renderDrawColor, renderDrawColor, renderDrawColor, renderDrawColor);
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags)) && imgFlags)
                {
                    return false;
                }

            }
        }


    }
    return true;
}
bool loadWaitingBg()
{
    bool ret = waitingBg.loadImg("img//Tank-Wars-2D-Game-Kit.png",g_screen);
    if (ret == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool loadGameOverBg()
{
    bool ret = gameOverBg.loadImg("img//game_over.png", g_screen);
    if (ret == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool loadGameWinBg()
{
    bool ret = gameWinBg.loadImg("img//win.png", g_screen);
    if (ret == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void close()
{
    gBackground.free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;
    SDL_DestroyWindow(g_window);
    g_window = NULL;
    IMG_Quit();
    SDL_Quit();
    Mix_Quit();
}
void checkListEnemyTankAlive(EnemyTank *list,int size) {
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (list[i].getIsTankAlive() == false)
        {
            cnt++;
        }
    }
    if (cnt == size)
    {
        gameStart = false;
        gameWin = true;
        gameOver = false;
    }
}
int main(int argc, char* argv[]) {
    //srand(std::time(nullptr));
    //Init Data
    if (!InitData())
    {
        return -1;
    }
    //set XY pos for tank
    //set Menu 1
    Menu menu[2];
    menu[0].setBgPath("img/grass.png");
    menu[0].loadBg();
    menu[0].initTank();
    menu[0].InitMap();
    
    // menu1.setBgPath("img/grass.png");
    // menu1.loadBg();
    // menu1.initTank();
    // menu1.InitMap();
    // Tank tankMenu1 = menu1.getTank();
    // SDL_Rect healthBar = tankMenu1.getHealBar();
    // baseObject bgMenu = menu1.getBg();
    // Map** wallsMenu = menu1.getMap();
    // int sizeTankBulletMenu = menu1.getSizeTankBullet();
    // Bullet* BulletsMenu = menu1.getBullet();
    // EnemyTank* listEnemyTankMenu = menu1.getListEnemyTank();
    // int sizeTankEnemyMenu = menu1.getNumberofEnemyTank();
    // int sizeTankEnemyBulletMenu[10]{};
    // EnemyBullet** EnemyBulletMenu = menu1.getEnemyBullets();
    


    Tank tankMenu1 = menu[0].getTank();
    SDL_Rect healthBar = tankMenu1.getHealBar();
    baseObject bgMenu = menu[0].getBg();
    Map** wallsMenu = menu[0].getMap();
    int sizeTankBulletMenu = menu[0].getSizeTankBullet();
    Bullet* BulletsMenu = menu[0].getBullet();
    EnemyTank* listEnemyTankMenu = menu[0].getListEnemyTank();
    int sizeTankEnemyMenu = menu[0].getNumberofEnemyTank();
    int sizeTankEnemyBulletMenu[10]{};
    EnemyBullet** EnemyBulletMenu = menu[0].getEnemyBullets();
    if (loadWaitingBg() == false)
    {
        std::cout << "Can not load waitingBg" << std::endl;
        return -1;
    }
    if (loadGameOverBg() == false)
    {
        std::cout << "Can not load GameOver" << std::endl;
        return -1;
    }
    if (loadGameWinBg() == false)
    {
        std::cout << "can not load game win" << std::endl;
        return -1;
    }
    // Game Loop
    bool isQuit = false;
    while (!isQuit) 
    {
        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                isQuit = true;
            }
            else if (g_event.type==SDL_MOUSEBUTTONDOWN)
            {
                if (g_event.button.button == SDL_BUTTON_LEFT)
                {
                    int x = g_event.button.x;
                    int y = g_event.button.y;
                    if ((x >= 440 && x <= 760) && (y>=345 && y<=410))
                    {
                        gameStart = true;
                    }
                }
            }
            tankMenu1.handleEvents(g_event,wallsMenu);
            if (tankMenu1.getIsTankAlive())
            {
                BulletsMenu[sizeTankBulletMenu].handleBulletEvents(g_event, tankMenu1, wallsMenu);
                sizeTankBulletMenu+= 1;
            }
        }
        //render background
        if (gameStart == false)
        {
            waitingBg.render(g_screen, NULL);
            if (gameOver == true)
            {
                SDL_RenderClear(g_screen);
                gameOverBg.render(g_screen,NULL);
            }
            else if (gameWin == true)
            {
                SDL_RenderClear(g_screen);
                gameWinBg.render(g_screen, NULL);
            }
            else
            {
                SDL_RenderClear(g_screen);
                waitingBg.render(g_screen, NULL);
            }
        }
        else if (gameStart == true)
        {
            SDL_RenderClear(g_screen);
            //start
            //test
            bgMenu.render(g_screen, NULL);
            healthBar.x = tankMenu1.getXpos()-4;
            healthBar.y = tankMenu1.getYpos()-10;
            healthBar.w = tankMenu1.getTankHp()*2;
            SDL_SetRenderDrawColor(g_screen, 255, 0, 0, 255); 
            if (tankMenu1.getIsTankAlive())
            {
                SDL_RenderFillRect(g_screen, &healthBar);
                tankMenu1.renderRouteThink(g_screen, tankMenu1.getAngle(), NULL);
            }

            //
            for (int i = 0; i < sizeTankEnemyMenu; i++)
            {
               if (listEnemyTankMenu[i].getIsTankAlive())
               {
                   listEnemyTankMenu[i].handleAtiveTankEnemy(tankMenu1);
               }
               if (listEnemyTankMenu[i].getBulletActive() && listEnemyTankMenu[i].getIsTankAlive() && gameOver==false)
               {
                   EnemyBulletMenu[i][sizeTankEnemyBulletMenu[i]].handleAutomatic(listEnemyTankMenu[i]);
                   sizeTankEnemyBulletMenu[i]++;
               }
            }
            tankMenu1.myTankMoveX(wallsMenu);
            tankMenu1.MyTankMoveY(wallsMenu);
            for (int i = 0; i < sizeTankEnemyMenu; i++)
            {
                /*listEnemyTankMenu[i].myTankEnemyMoveX(wallsMenu);
                listEnemyTankMenu[i].MyTankEnemyMoveY(wallsMenu);*/
                listEnemyTankMenu[i].myTankMoveX(wallsMenu);
                listEnemyTankMenu[i].MyTankMoveY(wallsMenu);

            }
            for (int i = 0; i < sizeTankEnemyMenu; i++)
            {
                if (listEnemyTankMenu[i].getIsTankAlive())
                {
                    listEnemyTankMenu[i].renderRouteThink(g_screen, listEnemyTankMenu[i].getAngle(), NULL);
                }
            }
            if (tankMenu1.getIsTankAlive())
            {
                for (int i = 0; i < sizeTankBulletMenu; i++)
                {
                    BulletsMenu[i].move(wallsMenu, listEnemyTankMenu,sizeTankEnemyMenu);
                    BulletsMenu[i].renderRouteThink(g_screen, BulletsMenu[i].getBulletAngle(), NULL);
                }
            }
            else
            {
                if (cnt == 0)
                {
                    gameStart = false;
                    gameOver = true;
                }
                else
                {
                    cnt--;
                }
            }
            // bullet enemy render
            for (int i = 0; i < sizeTankEnemyMenu; i++)
            {
                if (listEnemyTankMenu[i].getIsTankAlive())
                {
                    for (int j = 0; j < sizeTankEnemyBulletMenu[i]; j++)
                    {
                        EnemyBulletMenu[i][j].moveAuto(tankMenu1, wallsMenu);
                        EnemyBulletMenu[i][j].renderRouteThink(g_screen, EnemyBulletMenu[i][j].getBulletAngle(), NULL);
                    }
                }
            }
            for (int i = 0; i < mapRows; i++)
            {
                for (int j = 0; j < mapCols; j++)
                {
                    wallsMenu[i][j].render(g_screen, NULL);
                }
            }
            checkListEnemyTankAlive(listEnemyTankMenu, sizeTankEnemyMenu);
            SDL_Delay(15);
        }
        // uapdate screen 
        SDL_RenderPresent(g_screen);
    }
    delete[]listEnemyTankMenu;
    //detroy bullet
    for (int i = 0; i < sizeTankBulletMenu; i++)
    {
        BulletsMenu[i].free();
    }
    delete[]BulletsMenu;
    //detroy map
    for (int i = 0; i < mapRows; i++)
    {
        for (int j = 0; j < mapCols; j++)
        {
            wallsMenu[i][j].free();
        }
    }
    delete[] wallsMenu;
    std::cout << "end game" << std::endl;
    close(); 
    return 0;
}
