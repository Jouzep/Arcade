/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Test
*/

#include "../../../../include/IGraphics.hpp"
#include "SDL2/SDL.h"
#include "iostream"


namespace arcade {
    double RGB_COLOR[][4] = {
        {255,0,0,255}, // RED
        {0,0,255,255}, // BLUE
        {0,255,0,255}, // GREEN
        {0,0,0,255}, // DARK
        {255,255,0,255}, // YELLOW
        {255,255,255,255}, // WHITE
    };
    class SDL2Lib : public IGraphics
    {
    public:
        SDL2Lib();
        ~SDL2Lib();

        void display();
        void clear();

        void draw(std::shared_ptr<arcade::IObject> object);
        void drawTile(arcade::ITile *tile);
        void drawText(arcade::IText *text);
        arcade::Input event(std::vector<std::shared_ptr<arcade::IObject>> objs);

    private:
        SDL_Window *_win;
        SDL_Renderer *_renderer;
    };
}

arcade::SDL2Lib::SDL2Lib()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _win = SDL_CreateWindow("Arcade", 0, 0, 1920, 1080, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

arcade::SDL2Lib::~SDL2Lib()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_win);
    SDL_Quit();
}

void arcade::SDL2Lib::display()
{
    // SDL_SetRenderDrawColor(_renderer,); // COLOR
    SDL_SetRenderDrawColor(_renderer, RGB_COLOR[3][0], RGB_COLOR[3][1], RGB_COLOR[3][2], RGB_COLOR[3][3]); // COLOR

    SDL_RenderPresent(_renderer);
}

void arcade::SDL2Lib::clear()
{
    SDL_RenderClear(_renderer);

}
void arcade::SDL2Lib::draw(std::shared_ptr<arcade::IObject> object)
{
    arcade::ITile* _tile = dynamic_cast<arcade::ITile*>(object.get());

    if (_tile != nullptr) {
        drawTile(_tile);
        return;
    }
}

void arcade::SDL2Lib::drawTile(arcade::ITile* tile)
{
    SDL_Rect rect;
    auto pos = tile->getPosition();
    auto color = tile->getColor();
    int multiplicateur = 20;
    rect.w = multiplicateur;
    rect.h = multiplicateur;
    rect.x = pos.first * multiplicateur;
    rect.y = pos.second * multiplicateur;
    SDL_SetRenderDrawColor(_renderer, RGB_COLOR[color][0], RGB_COLOR[color][1], RGB_COLOR[color][2], RGB_COLOR[color][3]); // COLOR
    SDL_RenderFillRect(_renderer, &rect);
}

void arcade::SDL2Lib::drawText(arcade::IText* text)
{

}

arcade::Input arcade::SDL2Lib::event(std::vector<std::shared_ptr<arcade::IObject>> objs)
{
    SDL_Event event;

	while (SDL_PollEvent(&event))
	{
        if (event.type == SDL_QUIT)
            exit(1);
        if (event.type == SDL_KEYDOWN)
            switch (event.key.keysym.sym)
            {
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDLK_UP:
                    return arcade::Input::RIGHT;
                    break;
                case SDLK_RIGHT:
                    return arcade::Input::DOWN;
                    break;
                case SDLK_LEFT:
                    return arcade::Input::UP;     
                    break;
                case SDLK_h:
                    SDL_DestroyWindow(_win);
                    return arcade::Input::NEXTGRAPH;
                case SDLK_g:
                    SDL_DestroyWindow(_win);
                    return arcade::Input::PREVIOUSGRAPH;
                case SDLK_DOWN:
                    return arcade::Input::LEFT;
                    break;
                default:
                    break;
		    }
	}
}

extern "C" arcade::SDL2Lib *entryPoint() {
    return new (arcade::SDL2Lib);
}