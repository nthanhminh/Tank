#pragma once
#ifndef TTF_H
#define TTF_H
#include "CommonFunc.h"
#include <string>
class TextRenderer {
public:
    TextRenderer(SDL_Renderer* renderer, const std::string& font_path, int font_size, SDL_Color color);
    ~TextRenderer();
    void render(const std::string& text, int x, int y);

private:
    SDL_Renderer* m_renderer;
    TTF_Font* m_font;
    SDL_Color m_color;
};

#endif