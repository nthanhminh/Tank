#pragma once
#ifndef GAME_H
#define GAME_H
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
#include "Music.h"
class Game {
private:
    int cnt = 50;
    Menu menu1;
    Menu menu2;
    AudioManager musicMenu;
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
    baseObject gameRestart;
    baseObject gameChoseTank;
    bool changePlayBtn=true;
    bool changeHelpBtn=true;
    std::string tankPathChoose="img/tank_1.png";
    bool isQuit = false;
    bool check[6];
    Menu menu[6];
public:
    Game();
    bool loadGameChoseTank(SDL_Renderer *g_screen);
    bool loadPauseButton(SDL_Renderer *g_screen);
    bool loadGameRestart(SDL_Renderer *g_screen);
    bool loadPHelpButton(SDL_Renderer *g_screen);
    bool loadHelpBg(SDL_Renderer *g_screen);
    bool loadPlayButton(SDL_Renderer *g_screen);
    bool loadPauseBg(SDL_Renderer *g_screen);
    bool loadWaitingBg(SDL_Renderer *g_screen);
    bool loadMenuGame(SDL_Renderer *g_screen);
    bool loadGameOverBg(SDL_Renderer *g_screen);
    bool loadGameWinBg(SDL_Renderer *g_screen);
    bool checkListEnemyTankAlive(EnemyTank *list,int size);
    bool loadMusicMenu();
    void loadMusic();
    void loadData(SDL_Renderer *g_screen);
    void run(SDL_Renderer *g_screen);
};
#endif