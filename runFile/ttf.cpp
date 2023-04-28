#include "ttf.h"
#include <iostream>
TextRenderer::TextRenderer(SDL_Renderer* renderer, const std::string& font_path, int font_size, SDL_Color color)
    : m_renderer(renderer), m_color(color)
{
    TTF_Init();
    m_font = TTF_OpenFont(font_path.c_str(), font_size);
    if (!m_font) {
        std::cout << "Could not load font: " << TTF_GetError() << std::endl;
    }
}

TextRenderer::~TextRenderer()
{
    TTF_CloseFont(m_font);
    TTF_Quit();
}

void TextRenderer::render(const std::string& text, int x, int y)
{
    SDL_Surface* surface = TTF_RenderText_Solid(m_font, text.c_str(), m_color);
    if (!surface) {
        std::cout << "Could not create surface: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    if (!texture) {
        std::cout << "Could not create texture: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_Rect rect = { x, y, surface->w, surface->h };
    SDL_RenderCopy(m_renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}