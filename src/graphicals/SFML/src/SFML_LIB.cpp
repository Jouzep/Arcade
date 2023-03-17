/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SFML
*/

#include "IGraphics.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

namespace arcade {
    class SFML_Lib : public IGraphics {
        public:
            SFML_Lib();
            ~SFML_Lib();

            void display();
            void clear();
            void draw(std::shared_ptr<arcade::IObject> object);
            arcade::IGraphics::Input event();
        protected:
        private:
            sf::RenderWindow _window;
            sf::Event _event;
    };
}

arcade::SFML_Lib::SFML_Lib() : _window(sf::VideoMode(1200, 720), "Arcade Game")
{
    std::cout << "test" << std::endl;
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
    // _window.draw(shape);
}

arcade::IGraphics::Input arcade::SFML_Lib::event()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _window.close();
            return arcade::IGraphics::Input::EXIT;
        }
    }
}

extern "C" arcade::SFML_Lib *entryPoint() {
    return new (arcade::SFML_Lib);
}