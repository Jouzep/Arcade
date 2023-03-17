/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SFML
*/

#include "IGraphics.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "graphicals/SFML/Sprite.hpp"

namespace arcade {
    class SFML_Lib : public IGraphics {
        public:
            SFML_Lib();
            ~SFML_Lib();

            void display();
            void clear();
            void draw(std::shared_ptr<arcade::IObject> object);
            arcade::Input event();
        protected:
        private:
            arcade::Sprite _background;
            sf::Sprite _bg;
            sf::Texture _bg_texture;
            sf::RenderWindow _window;
            sf::Event _event;
    };
}

arcade::SFML_Lib::SFML_Lib() : _window(sf::VideoMode(1200, 720), "Arcade Game")
{
    _bg_texture.loadFromFile("assets/gui/menu_bg.jpg");
    _bg.setTexture(_bg_texture);
}

arcade::SFML_Lib::~SFML_Lib()
{

}

void arcade::SFML_Lib::display()
{
    _window.display();
}

void arcade::SFML_Lib::clear()
{
    _window.clear();
}

void arcade::SFML_Lib::draw(std::shared_ptr<arcade::IObject> object)
{
    _window.draw(_bg);
}

arcade::Input arcade::SFML_Lib::event()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _window.close();
            return arcade::Input::EXIT;
        }
    }
}

extern "C" arcade::SFML_Lib *entryPoint() {
    return new (arcade::SFML_Lib);
}
