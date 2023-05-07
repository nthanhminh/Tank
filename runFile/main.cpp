#include "Game.h"
Game game;
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
        if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3) 
        {
           std::cout << "Failed to initialize SDL_mixer" << Mix_GetError();
           return false;
        }

    }
    return true;
}
void close()
{
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;
    SDL_DestroyWindow(g_window);
    g_window = NULL;
    IMG_Quit();
    SDL_Quit();
    Mix_CloseAudio();
    Mix_Quit();
}

int main(int argc, char* argv[]) {
    //Init Data
    if (!InitData())
    {
        return -1;
    }
    game.loadData(g_screen);
    game.run(g_screen);
    close(); 
    return 0;
}
