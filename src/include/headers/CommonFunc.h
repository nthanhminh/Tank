#pragma once
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#include<Windows.h>
#include<string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
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
const int v = 3;
const int health = 20;
const int v_bullet = 6;
const int tankSize = 25; 
const int mapRows = 15;
const int mapCols = 30;
const int damge[3] = { 2,5,8 };


#define TITLE_SIZE 64
#define maxMapX 400
#define maxMapY 10


#endif
