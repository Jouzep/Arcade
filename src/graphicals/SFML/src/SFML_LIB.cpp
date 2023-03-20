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
#include <SFML/Audio.hpp>
#include "../../../../include/graphicals/SFML/Sprite.hpp"

namespace arcade {
    class SFML_Lib : public IGraphics {
        public:
            SFML_Lib();
            ~SFML_Lib();

            void display();
            void clear();
            void draw(std::shared_ptr<arcade::IObject> object);
            void drawTile(arcade::ITile* _tile);
            void drawText(arcade::IText* text);
            arcade::Input event(std::vector<std::shared_ptr<arcade::IObject>> objs);
            void clickEvent(std::vector<std::shared_ptr<arcade::IObject>> objs);
        protected:
        private:
            sf::Mouse _mouse;
            // std::vector<sf::VideoMode> fullscreenModes = sf::VideoMode::getFullscreenModes();
            sf::RenderWindow _window;
            sf::Event _event;
            sf::Music _music;
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

void arcade::SFML_Lib::drawTile(arcade::ITile* _tile)
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile(_tile->getTexture());
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(_tile->getScale().first, _tile->getScale().second));
    sprite.setPosition(sf::Vector2f(_tile->getPosition().first, _tile->getPosition().second));
    _window.draw(sprite);
}

void arcade::SFML_Lib::drawText(arcade::IText* textObj)
{
    sf::Text text;
    sf::Font font;

    font.loadFromFile("assets/fonts/8_bit.ttf");
    text.setString(textObj->getText());
    text.setFont(font);
    text.setPosition(sf::Vector2f(textObj->getPosition().first, textObj->getPosition().second));
    _window.draw(text);
}

void arcade::SFML_Lib::draw(std::shared_ptr<arcade::IObject> object)
{
    arcade::ITile* _tile = dynamic_cast<arcade::ITile*>(object.get());
    if (_tile != nullptr) {
        drawTile(_tile);
        return;
    }

    arcade::ISound* _sound = dynamic_cast<arcade::ISound*>(object.get());
    if (_sound != nullptr) {
        if (_music.getStatus() != sf::Music::Playing) {
            if (_music.openFromFile(_sound->getSoundPath())) {
                std::cout << "ok " << _music.getStatus() << std::endl;
                _music.setLoop(true);
                _music.play();
            }
        }
    }

    arcade::IText* text = dynamic_cast<arcade::IText*>(object.get());
    if (text != nullptr) {
        drawText(text);
        return;
    }
}

void arcade::SFML_Lib::clickEvent(std::vector<std::shared_ptr<arcade::IObject>> objs)
{
    // if (_event.type == sf::Event::MouseButtonReleased) {
    //     std::cout << "clicked" << std::endl;
    // }
    for (auto obj : objs) {
        arcade::ITile* tile = dynamic_cast<arcade::ITile*>(obj.get());
        if (tile != nullptr) {
            if (tile->isClickable()) {
                if (_event.mouseMove.x >= tile->getPosition().first && _event.mouseMove.x <= tile->getPosition().first + 50
                && _event.mouseMove.y >= tile->getPosition().second && _event.mouseMove.y <= tile->getPosition().second + 50) {
                    tile->setScale(std::make_pair(0.15, 0.15));
                } else {
                    tile->setScale(std::make_pair(0.1, 0.1));
                }
            }
        }
    }
}

arcade::Input arcade::SFML_Lib::event(std::vector<std::shared_ptr<arcade::IObject>> objs)
{
    // std::cout << _mouse.getPosition().x - _window.getSize().x << std::endl;
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _music.stop();
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
        if (_event.type == sf::Event::MouseMoved || _event.type == sf::Event::MouseButtonPressed) {
            clickEvent(objs);
        }
        /*if(_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::M) {
                 if (_music.openFromFile("assets/sounds/menu.ogg")) {
                     _music.setVolume(100);
                     _music.play();
                     std::cout << "ok " << _music.getStatus() << std::endl;
                 }
                         }
        }*/
    }
}

extern "C" arcade::SFML_Lib *entryPoint() {
    return new (arcade::SFML_Lib);
}
