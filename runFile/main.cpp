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
#include "ttf.h"
int cnt = 50;
Menu menu1;
Menu menu2;
baseObject gBackground;
baseObject waitingBg;
baseObject gameOverBg;
baseObject gameWinBg;
baseObject gameMenu;
baseObject pauseButton;
baseObject gamePauseBg;
baseObject playBtn;
baseObject helpBtn;
baseObject gameHelp;
bool changePlayBtn=true;
bool changeHelpBtn=true;
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
bool loadPauseButton()
{
    bool ret=pauseButton.loadImg("img/pause.png",g_screen);
    pauseButton.setXYpos(0,0);
    if (ret==false)
    {
        return false;
    }
    else{
        return true;
    }
}
bool loadPHelpButton()
{
    bool ret=helpBtn.loadImg("img/help_button.png",g_screen);
    if (ret==false)
    {
        return false;
    }
    else{
        return true;
    }
}
bool loadHelpBg()
{
    bool ret=gameHelp.loadImg("img/help.png",g_screen);
    if (ret==false)
    {
        return false;
    }
    else{
        return true;
    }
}
bool loadPlayButton()
{
    bool ret=playBtn.loadImg("img/playBtn.png",g_screen);
    playBtn.setXYpos(0,0);
    if (ret==false)
    {
        return false;
    }
    else{
        return true;
    }
}
bool loadPauseBg()
{
    bool ret=gamePauseBg.loadImg("img/game_pause_bg.png",g_screen);
    pauseButton.setXYpos(0,0);
    if (ret==false)
    {
        return false;
    }
    else{
        return true;
    }
}
bool loadWaitingBg()
{
    bool ret = waitingBg.loadImg("img/waiting.png",g_screen);
    //bool ret = waitingBg.loadImg("img//menu.png",g_screen);
    if (ret == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool loadMenuGame()
{
    bool ret=gameMenu.loadImg("img/1.png",g_screen);
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

// Init variables for game
// Tank tankMenu1;
// SDL_Rect healthBar;
// baseObject bgMenu;
// Map** wallsMenu;
// int sizeTankBulletMenu;
// Bullet* BulletsMenu;
// EnemyTank* listEnemyTankMenu;
// int sizeTankEnemyMenu;
// int sizeTankEnemyBulletMenu[10]{};
// EnemyBullet** EnemyBulletMenu;



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
    TextRenderer textRenderer(g_screen, "ttf/OpenSans_Condensed-Bold.ttf", 48, {255, 0, 0, 180});
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

    SDL_Rect healthBar = menu[0].tank.getHealBar();
    SDL_Rect hover({650,420,300,100});
    
    // Tank tankMenu1;
    // SDL_Rect healthBar;
    // baseObject bgMenu;
    // Map** wallsMenu;
    // int sizeTankBulletMenu;
    // Bullet* BulletsMenu;
    // EnemyTank* listEnemyTankMenu;
    // int sizeTankEnemyMenu;
    // int sizeTankEnemyBulletMenu[10]{};
    // EnemyBullet** EnemyBulletMenu;

    // tankMenu1 = menu[0].getTank();
    // healthBar = tankMenu1.getHealBar();
    // bgMenu = menu[0].getBg();
    // wallsMenu = menu[0].getMap();
    // sizeTankBulletMenu = menu[0].getSizeTankBullet();
    // BulletsMenu = menu[0].getBullet();
    // listEnemyTankMenu = menu[0].getListEnemyTank();
    // sizeTankEnemyMenu = menu[0].getNumberofEnemyTank();
    // EnemyBulletMenu = menu[0].getEnemyBullets();
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
    if (loadMenuGame()==false)
    {
        std::cout << "can not load game menu" << std::endl;
        return -1;
    }
    if (loadPauseButton()==false)
    {
        std::cout << "can not load pause button" << std::endl;
        return -1;
    }
    if (loadPauseBg() == false)
    {
        std::cout << "can not load pause bg" << std::endl;
        return -1;
    }
    if (!loadPlayButton())
    {
        std::cout << "can not load play btn" << std::endl;
        return -1;
    }
    else
    {
        playBtn.setXYpos(650,420);
    }
    if (!loadPHelpButton())
    {
        std::cout << "can not load help btn" << std::endl;
        return -1;
    }
    else
    {
        helpBtn.setXYpos(650,500);
    }
    if (!loadHelpBg())
    {
        std::cout << "can not load help bg" << std::endl;
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
                    std::cout << x << " " << y << std::endl;
                    if (waiting)
                    {
                        if (x>=665 && x<=780 && y>=420 && y<=465)
                        {
                            turnMenu=true;
                        }
                        else if (x>=665 && x<=780 && y>=500 && y<=570)
                        {
                            turnHelp=true;
                        }
                    }
                    if (turnMenu)
                    {
                        if((x>=150 && x<=265) && (y>=150 && y<=220))
                        {
                            turnMenu=false;
                            gameStart=true;
                        }
                    }
                    if (gameStart==true)
                    {
                        if ((x>=0 && x<=60) && (y>=0 && y<=60))
                        {
                            gameStart=false;
                            gamePause=true;
                            waiting=false;
                        }
                    }
                    else  if (turnHelp)
                    {
                        if (x>=35 && x<=250 && y>=25 && y<=80)
                        {
                            turnHelp=false;
                            waiting=true;
                        }
                    }
                    else if (gamePause==true)
                    {
                        if ((x>=450 && x<=1050) && (y>=520 && y<=660))
                        {
                            gameStart=true;
                            gamePause=false;
                        }
                    }

                }
            }
            else if (g_event.type==SDL_MOUSEMOTION)
            {
                if (waiting)
                {
                    int x = g_event.motion.x;
                    int y = g_event.motion.y;
                    std::cout<< x << " " << y << std::endl;
                    if (x>=665 && x<=780 && y>=420 && y<=465)
                    {
                        if (changePlayBtn==true)
                        {
                            playBtn.setXYpos(playBtn.getXpos(),playBtn.getYpos()-changeYposHoverBtn);
                            changePlayBtn=false;
                        }
                    }
                    else
                    {
                        if(changePlayBtn==false)
                        {
                            playBtn.setXYpos(playBtn.getXpos(),playBtn.getYpos()+changeYposHoverBtn);
                            changePlayBtn=true;
                        }
                    }
                    if ((x>=665 && x<=780) && y>=500 && y<=570)
                    {
                        if (changeHelpBtn==true)
                        {
                            helpBtn.setXYpos(helpBtn.getXpos(),helpBtn.getYpos()-changeYposHoverBtn);
                            changeHelpBtn=false;
                        }
                    }
                    else{
                        if (changeHelpBtn==false)
                        {
                            helpBtn.setXYpos(helpBtn.getXpos(),helpBtn.getYpos()+changeYposHoverBtn);
                            changeHelpBtn=true;
                        }
                    }
                }   
            }
            if (gameStart==true)
            {
                if (gameStart==true)
                {
                    menu[0].tank.handleEvents(g_event,menu[0].walls);
                    if (menu[0].tank.getIsTankAlive())
                    {
                        menu[0].Bullets[menu[0].sizeTankBullet].handleBulletEvents(g_event, menu[0].tank, menu[0].walls);
                        menu[0].sizeTankBullet+= 1;
                    }
                }
            }
        }
        //render background
        if (gameStart == false)
        {
            //waitingBg.render(g_screen,NULL);
            if (gameOver == true)
            {
                SDL_RenderClear(g_screen);
                gameOverBg.render(g_screen,NULL);
            }
            else if (turnHelp)
            {
                SDL_RenderClear(g_screen);
                gameHelp.render(g_screen,NULL);
            }
            else if (gameWin == true)
            {
                SDL_RenderClear(g_screen);
                gameWinBg.render(g_screen, NULL);
            }
            else if (turnMenu==true)
            {
                SDL_RenderClear(g_screen);
                gameMenu.render(g_screen, NULL);
            }
            else if (gamePause)
            {
                SDL_RenderClear(g_screen);
                gamePauseBg.render(g_screen,NULL);
            }
            else if (waiting)
            {
                SDL_RenderClear(g_screen);
                waitingBg.render(g_screen, NULL);   
                playBtn.render(g_screen,NULL);
                helpBtn.render(g_screen,NULL);
            }
        }
        else if (gameStart == true)
        {

            SDL_RenderClear(g_screen);
            //start
            //test
            menu[0].background.render(g_screen, NULL);
            healthBar.x = menu[0].tank.getXpos()+2;
            healthBar.y = menu[0].tank.getYpos()-15;
            healthBar.w = menu[0].tank.getTankHp()*2; 
            if (menu[0].tank.getIsTankAlive())
            {
                if (menu[0].tank.getTankIsProtected())
                {
                     SDL_SetRenderDrawColor(g_screen, 255, 255, 0, 255);
                }
                else
                {
                     SDL_SetRenderDrawColor(g_screen, 255, 0, 0, 255);
                }
                SDL_RenderFillRect(g_screen, &healthBar);
                menu[0].tank.renderRouteThink(g_screen, menu[0].tank.getAngle(), NULL);
                if (menu[0].tank.getTankIsProtected())
                {
                    if (menu[0].tank.getTimeDefender()==0)
                    {
                        menu[0].tank.setTankIsProtected(false);
                    }
                    else
                    {
                        menu[0].tank.setTimeDefender(menu[0].tank.getTimeDefender()-1);
                    }
                }
            }

            //
            for (int i = 0; i < menu[0].numberOfEnemyTank; i++)
            {
               if (menu[0].listEnemyTank[i].getIsTankAlive())
               {
                    if (i==1)
                        menu[0].listEnemyTank[i].handleAtiveTankEnemyA(menu[0].tank);
                    else if (i==2)
                        menu[0].listEnemyTank[i].handleAtiveTankEnemyB(menu[0].tank);
                    else if (i==3)
                        menu[0].listEnemyTank[i].handleAtiveTankEnemyC(menu[0].tank);
                    else 
                        menu[0].listEnemyTank[i].handleAtiveTankEnemyD(menu[0].tank);
               }
               if (menu[0].listEnemyTank[i].getBulletActive() && menu[0].listEnemyTank[i].getIsTankAlive() && gameOver==false)
               {
                   menu[0].EnemyBullets[i][menu[0].sizeEnemyTankBulluets[i]].handleAutomatic(menu[0].listEnemyTank[i]);
                   menu[0].sizeEnemyTankBulluets[i]++;
               }
            }
            menu[0].tank.myTankMoveX(menu[0].walls);
            menu[0].tank.MyTankMoveY(menu[0].walls);
            for (int i = 0; i < menu[0].numberOfEnemyTank; i++)
            {
                menu[0].listEnemyTank[i].myTankMoveX(menu[0].walls);
                menu[0].listEnemyTank[i].MyTankMoveY(menu[0].walls);

            }
            for (int i = 0; i < menu[0].numberOfEnemyTank; i++)
            {
                if (menu[0].listEnemyTank[i].getIsTankAlive())
                {
                    menu[0].listEnemyTank[i].updateHealBar();
                    SDL_Rect tmp=menu[0].listEnemyTank[i].getHealBar();

                    if (menu[0].listEnemyTank[i].getTankIsProtected())
                    {
                        SDL_SetRenderDrawColor(g_screen, 255, 255, 0, 255);
                        SDL_RenderFillRect(g_screen,&tmp);
                        if (menu[0].listEnemyTank[i].getTimeDefender()==0)
                        {
                            menu[0].listEnemyTank[i].setTankIsProtected(false);
                        }   
                        else
                        {
                            menu[0].listEnemyTank[i].setTimeDefender(menu[0].listEnemyTank[i].getTimeDefender()-1);
                        }
                    }
                    else
                    {
                        SDL_SetRenderDrawColor(g_screen, 255, 0, 0, 255);
                        SDL_RenderFillRect(g_screen,&tmp);
                    }
                    menu[0].listEnemyTank[i].renderRouteThink(g_screen, menu[0].listEnemyTank[i].getAngle(), NULL);
                }
            }
            if (menu[0].tank.getIsTankAlive())
            {
                for (int i = 0; i < menu[0].sizeTankBullet; i++)
                {
                    menu[0].Bullets[i].move(menu[0].walls, menu[0].listEnemyTank,menu[0].numberOfEnemyTank,menu[0].tank);
                    menu[0].Bullets[i].renderRouteThink(g_screen, menu[0].Bullets[i].getBulletAngle(), NULL);
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
            for (int i = 0; i < menu[0].numberOfEnemyTank; i++)
            {
                if (menu[0].listEnemyTank[i].getIsTankAlive())
                {
                    for (int j = 0; j < menu[0].sizeEnemyTankBulluets[i]; j++)
                    {
                        menu[0].EnemyBullets[i][j].moveAuto(menu[0].tank, menu[0].walls,menu[0].listEnemyTank[i]);
                        menu[0].EnemyBullets[i][j].renderRouteThink(g_screen, menu[0].EnemyBullets[i][j].getBulletAngle(), NULL);
                    }
                }
            }
            for (int i = 0; i < mapRows; i++)
            {
                for (int j = 0; j < mapCols; j++)
                {
                    menu[0].walls[i][j].render(g_screen, NULL);
                }
            }
            checkListEnemyTankAlive(menu[0].listEnemyTank, menu[0].numberOfEnemyTank);
            pauseButton.render(g_screen,NULL);
            SDL_Delay(15);
        }
        // uapdate screen 
        SDL_RenderPresent(g_screen);
    }
    menu[0].close();
    std::cout << "end game" << std::endl;
    close(); 
    return 0;
}
