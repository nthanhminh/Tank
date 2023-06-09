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
    AudioManager musicRestart;
    AudioManager musicGameWin;
    AudioManager musicGameOver;
    AudioManager musicClick;
    AudioManager sound_gun;
    AudioManager sound_collision;
    AudioManager sound_tank;
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
    baseObject endGame;
    baseObject block[5];
    bool changePlayBtn=true;
    bool changeHelpBtn=true;
    std::string tankPathChoose="img/tank_1.png";
    int menuIsOpen=0;
    bool isQuit = false;
    bool check[5];
    Menu menu[6];
public:
    Game();
    bool loadGameChoseTank(SDL_Renderer *g_screen);
    bool loadBlock(SDL_Renderer* g_screen);
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
    bool loadEndGame(SDL_Renderer *g_screen);
    bool loadSoundGun();
    bool loadSoundCollision();
    bool loadSoundTank();
    bool checkListEnemyTankAlive(EnemyTank *list,int size);
    bool loadMusicMenu();
    bool loadMusicRestart();
    bool loadMusicGameWin();
    bool loadMusicGameOver();
    bool loadMusicClick();
    void loadData(SDL_Renderer *g_screen);
    void renderBlocks(SDL_Renderer *g_screen);

    void run(SDL_Renderer *g_screen);
};
#endif