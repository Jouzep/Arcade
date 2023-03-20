/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SFML
*/

#include "../../../../include/IGraphics.hpp"
// #include "IGraphics.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../../../include/graphicals/SFML/Sprite.hpp"

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
            sf::RenderWindow _window;
            sf::Event _event;
    };
}

arcade::SFML_Lib::SFML_Lib() : _window(sf::VideoMode(1200, 720), "Arcade Game")
{
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
    sf::Sprite sprite;
    sf::Texture texture;

    arcade::ITile* _tile = dynamic_cast<arcade::ITile*>(object.get());
    if (_tile != nullptr) {
        texture.loadFromFile(_tile->getTexture());
        sprite.setTexture(texture);
        _window.draw(sprite);
    }
}



arcade::Input arcade::SFML_Lib::event()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _window.close();
            return arcade::Input::EXIT;
        }
        if(_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::G) {
                _window.close();
                return arcade::Input::PREVIOUSGRAPH;
            }
            if (_event.key.code == sf::Keyboard::H) {
                _window.close();
                return arcade::Input::NEXTGRAPH;
            }
        }
    }
}

extern "C" arcade::SFML_Lib *entryPoint() {
    return new (arcade::SFML_Lib);
}
