/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Test
*/

#include "../../../../include/IGraphics.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "iostream"
#include "map"
// #include "/home/jyu/delivery/TEK2/arcade/B-OOP-400-PAR-4-1-arcade-joseph.yu/include/core/Error.hpp"

namespace arcade {
    SDL_Color RGB_COLOR[] = {
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
        void drawSprite(arcade::ITile *tile);
        void drawColoredRect(arcade::ITile *tile);
        void drawText(arcade::IText *text);
        arcade::Input event(std::vector<std::shared_ptr<arcade::IObject>> objs);

    private:
        std::shared_ptr<SDL_Window> _win;
        std::shared_ptr<SDL_Renderer>_renderer;
        std::shared_ptr<TTF_Font> _font;
        std::map<std::string, SDL_Texture*> _texture;
    };
}

arcade::SDL2Lib::SDL2Lib()
{
    const char *Font_name = "assets/fonts/8_bit.ttf";

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    _win = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow("Arcade - SDL", 0, 0, 1920, 1080, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE),
        SDL_DestroyWindow  // fonction de suppression personnalisée
    );
    // if (!_win)
    //     throw Error("SDL Window", SDL_GetError());
    _font = std::shared_ptr<TTF_Font>(TTF_OpenFont(Font_name, 15), TTF_CloseFont);
    // if (!_font)
    //     throw Error("SDL FONT", SDL_GetError());
    _renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(_win.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), SDL_DestroyRenderer);
    // if (!_renderer)
    //     throw Error("SDL Renderer", SDL_GetError());

}

arcade::SDL2Lib::~SDL2Lib()
{
    TTF_Quit();
    for (auto it = _texture.begin(); it != _texture.end(); it++)
        SDL_DestroyTexture(it->second);
    _texture.clear();
    SDL_DestroyRenderer(_renderer.get());
    SDL_DestroyWindow(_win.get());
    SDL_Quit();
    std::cout << "SDL2 destroyed" << std::endl;
}

void arcade::SDL2Lib::display()
{
    SDL_SetRenderDrawColor(_renderer.get(), RGB_COLOR[arcade::Color::DARK].r, RGB_COLOR[arcade::Color::DARK].g, RGB_COLOR[arcade::Color::DARK].b, 0); // COLOR
    SDL_RenderPresent(_renderer.get());
}

void arcade::SDL2Lib::clear()
{
    SDL_RenderClear(_renderer.get());
}
void arcade::SDL2Lib::draw(std::shared_ptr<arcade::IObject> object)
{
    arcade::ITile* _tile = dynamic_cast<arcade::ITile*>(object.get());
    if (_tile != nullptr) {
        drawTile(_tile);
        return;
    }
    // arcade::ISound* _sound = dynamic_cast<arcade::ISound*>(object.get());
    // if (_sound != nullptr) {
    //     if (_music.getStatus() != sf::Music::Playing) {
    //         if (_music.openFromFile(_sound->getSoundPath())) {
    //             std::cout << "ok " << _music.getStatus() << std::endl;
    //             _music.setLoop(true);
    //             _music.play();
    //         }
    //     }
    // }
    arcade::IText* text = dynamic_cast<arcade::IText*>(object.get());
    if (text != nullptr) {
        drawText(text);
        return;
    }
}

void arcade::SDL2Lib::drawSprite(arcade::ITile* tile)
{
    int w;
    int h;
    auto texture_name = tile->getTexture();
    SDL_Surface *surface = IMG_Load(tile->getTexture().c_str());
    SDL_Rect rect = {(int)tile->getPosition().first * 20, (int)tile->getPosition().second * 20, 0, 0};

    if (_texture.find(texture_name) == _texture.end()) {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), surface);
        _texture[texture_name] = texture;
    }
    SDL_FreeSurface(surface);

    // get size
    SDL_QueryTexture(_texture[texture_name], NULL, NULL, &w, &h);

    // set size with the scale
    rect.w = w * tile->getScale().first;
    rect.h =  h * tile->getScale().second;
    SDL_RenderCopy(_renderer.get(), _texture[texture_name], NULL, &rect);
}

void arcade::SDL2Lib::drawColoredRect(arcade::ITile* tile)
{
    SDL_Rect rect;
    auto pos = tile->getPosition();
    auto color = tile->getColor();
    int multiplicateur = 20;
    rect.w = multiplicateur;
    rect.h = multiplicateur;
    rect.x = pos.first * multiplicateur;
    rect.y = pos.second * multiplicateur;
    SDL_SetRenderDrawColor(_renderer.get(), RGB_COLOR[color].r, RGB_COLOR[color].g, RGB_COLOR[color].b, RGB_COLOR[color].a); // COLOR
    SDL_RenderFillRect(_renderer.get(), &rect);
}

void arcade::SDL2Lib::drawTile(arcade::ITile* tile)
{

    if (tile->getTexture() == "null") {
        this->drawColoredRect(tile);
    }
    else {
        this->drawSprite(tile);
    }
}

void arcade::SDL2Lib::drawText(arcade::IText* text)
{
    auto content = text->getText();
    auto pos = text->getPosition();
    auto color = text->getColorText();
    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(_font.get(), content.c_str(), RGB_COLOR[color]);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(_renderer.get(), surfaceMessage);
    SDL_Rect rect; // create a rect
    int multiplicateur = 20;
    int text_size = content.size();
    rect.w = multiplicateur * text_size;
    rect.h = multiplicateur;
    rect.x = pos.first * multiplicateur;
    rect.y = pos.second * multiplicateur;
    SDL_RenderCopy(_renderer.get(), Message, NULL, &rect);
    SDL_FreeSurface(surfaceMessage);
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
                    SDL_DestroyWindow(_win.get());
                    SDL_DestroyRenderer(_renderer.get());
                    SDL_Quit();
                    return arcade::Input::EXIT;
                    break;
                // Desordered because key base was in ncurse
                case SDLK_UP:
                    return arcade::Input::RIGHT;
                    break;
                case SDLK_DOWN:
                    return arcade::Input::LEFT;
                    break;
                case SDLK_LEFT:
                    return arcade::Input::UP;     
                    break;
                case SDLK_RIGHT:
                    return arcade::Input::DOWN;
                    break;
                // CHANGER
                case SDLK_g:
                    SDL_DestroyWindow(_win.get());
                    return arcade::Input::PREVIOUSGRAPH;
                case SDLK_h:
                    SDL_DestroyWindow(_win.get());
                    return arcade::Input::NEXTGRAPH;
                case SDLK_b:
                    return arcade::Input::PREVIOUSGAME;
                case SDLK_n:
                    return arcade::Input::NEXTGAME;
                case SDLK_SPACE:
                    return arcade::Input::ACTION1;
                default:
                    break;
            }
	}
    return arcade::Input::UNDEFINED;
}

extern "C" arcade::SDL2Lib *entryPoint() {
    return new (arcade::SDL2Lib);
}