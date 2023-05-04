#pragma once
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#include<Windows.h>
#include<string>
#include<vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

// Screen
const int  screenWidth = 1500;
const int  scrennHeight = 750;
const int  Screen_BPP = 32;

const int colorKeyR = 167;
const int colorKeyG = 175;
const int colorKeyB = 180;
const int renderDrawColor = 0xff;
const int vNormal = 3;
const double v=vNormal;
const double vSpeedUp=1.2*vNormal;
const int health = 20;
const int v_bullet = 8;
const int tankSize = 25; 
const int mapRows = 15;
const int mapCols = 30;
const int damge[3] = { 4,6,8 };
const bool boom_effects=false;
static bool gameStart = false;
static bool gameOver = false;
static bool gameWin = false;
static bool isPlaying = false;
static bool turnMenu = false;
static bool turnHelp = false;
static bool turnGameStart=false;
static bool gamePause = false;
static bool waiting=true;
static bool turnChoseTank=false;
static int choiceOfmenu=0;
static int changeYposHoverBtn=5;
static int time_turn_restart = 10000;

#define TITLE_SIZE 64
#define maxMapX 400
#define maxMapY 10


#endif
