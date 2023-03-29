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
// #include <Keyboard.hpp>
#include "../../../../include/graphicals/SFML/Sprite.hpp"
#include <unordered_map>

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
            // arcade::Input clickEvent(std::vector<std::shared_ptr<arcade::IObject>> objs);
        protected:
        private:
            sf::Mouse _mouse;
            // std::vector<sf::VideoMode> fullscreenModes = sf::VideoMode::getFullscreenModes();
            sf::RenderWindow _window;
            sf::Event _event;
            sf::Music _music;
            std::unordered_map<std::string, sf::Texture> _textures;
            std::unordered_map<std::string, std::string> _texturesName;
            std::unordered_map<std::string, sf::Sprite> _sprites;
            sf::Clock clock;
            std::map<std::size_t, sf::Color> _colors;
    };
}

arcade::SFML_Lib::SFML_Lib() : _window(sf::VideoMode(1920, 1080), "Arcade Game")
{
    _colors[arcade::Color::RED] = sf::Color::Red;
    _colors[arcade::Color::BLUE] = sf::Color::Blue;
    _colors[arcade::Color::DARK] = sf::Color::Black;
    _colors[arcade::Color::GREEN] = sf::Color::Green;
    _colors[arcade::Color::WHITE] = sf::Color::White;
    _colors[arcade::Color::YELLOW] = sf::Color::Yellow;
}

arcade::SFML_Lib::~SFML_Lib()
{

}

void arcade::SFML_Lib::display()
{
    // sf::Time elapsed2 = clock.getElapsedTime();
    // // std::cout << elapsed2.asSeconds() << std::endl;
    // if (elapsed2.asSeconds() > 0.5) {
    //     // std::cout << "animte" << std::endl;
    //     clock.restart();
    // }
    _window.display();
}

void arcade::SFML_Lib::clear()
{
    _window.clear();
}

void arcade::SFML_Lib::drawTile(arcade::ITile* _tile)
{
    auto it = _textures.find(_tile->getName());
    if (it == _textures.end() || _texturesName[_tile->getName()] != _tile->getTexture()) {
        sf::Texture texture;
        texture.loadFromFile(_tile->getTexture());
        _textures[_tile->getName()] = texture;
        _texturesName[_tile->getName()] = _tile->getTexture();
        it = _textures.find(_tile->getName());
    }
    sf::Sprite& sprite = _sprites[_tile->getTexture()];

    sprite.setTexture(it->second);

    sprite.setScale(sf::Vector2f(_tile->getScale().first  , _tile->getScale().second));
    // float posX = ((_window.getSize().x / 150) * _tile->getPosition().first)/* - (_tile->getSize().first / 2)*/;
    // float posY = (_window.getSize().y / 50 * _tile->getPosition().second)/* - (_tile->getSize().second / 2)*/;
    // sprite.setPosition(sf::Vector2f(posX, posY));
    sprite.setPosition(sf::Vector2f(_tile->getPosition().first * 20, _tile->getPosition().second * 20));

    _window.draw(sprite);
}

void arcade::SFML_Lib::drawText(arcade::IText* textObj)
{
    sf::Text text;
    sf::Font font;

    font.loadFromFile("assets/fonts/8_bit.ttf");
    text.setString(textObj->getText());
    text.setColor(_colors[textObj->getColorText()]);
    text.setFont(font);
    text.setScale(sf::Vector2f(textObj->getScale().first, textObj->getScale().second));
    // float posX = ((_window.getSize().x / 150) * textObj->getPosition().first);
    // float posY = (_window.getSize().y / 50 * textObj->getPosition().second);
    text.setPosition(sf::Vector2f(textObj->getPosition().first * 20, textObj->getPosition().second * 20));
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

/*arcade::Input arcade::SFML_Lib::clickEvent(std::vector<std::shared_ptr<arcade::IObject>> objs)
{
    for (auto obj : objs) {
        arcade::ITile* tile = dynamic_cast<arcade::ITile*>(obj.get());
        if (tile != nullptr) {
            if (tile->isClickable()) {
                float posX = ((_window.getSize().x / 150) * tile->getOriginPosition().first);
                float posY = (_window.getSize().y / 50 * tile->getOriginPosition().second)
                if (_event.mouseMove.x >= posX && _event.mouseMove.x <= posX + tile->getSize().first
                && _event.mouseMove.y >= posY && _event.mouseMove.y <= posY + tile->getSize().second
                || _event.mouseButton.x >= posX && _event.mouseButton.x <= posX + tile->getSize().first
                && _event.mouseButton.y >= posY && _event.mouseButton.y <= posY + tile->getSize().second) {
                    if (_event.type == sf::Event::MouseButtonReleased) {
                        return tile->getEvent();
                    }
                    tile->setScale(std::make_pair(tile->getOriginScale().first + 0.05, tile->getOriginScale().second + 0.05));
                    tile->setPosition(std::make_pair(tile->getOriginPosition().first - 1, tile->getOriginPosition().second - 1));
                } else {
                    tile->setScale(tile->getOriginScale());
                    tile->setPosition(tile->getOriginPosition());
                }
            }
        }
        arcade::IText* text = dynamic_cast<arcade::IText*>(obj.get());
        if (text != nullptr) {
            if (_event.mouseMove.x >= text->getOriginPosition().first && _event.mouseMove.x <= text->getOriginPosition().first + text->getSize().first
                && _event.mouseMove.y >= text->getOriginPosition().second && _event.mouseMove.y <= text->getOriginPosition().second + text->getSize().second
                || _event.mouseButton.x >= text->getOriginPosition().first && _event.mouseButton.x <= text->getOriginPosition().first + text->getSize().first
                && _event.mouseButton.y >= text->getOriginPosition().second && _event.mouseButton.y <= text->getOriginPosition().second + text->getSize().second) {
                    if (_event.type == sf::Event::MouseButtonReleased) {
                        return text->getEvent();
                    }
                    text->setScale(std::make_pair(text->getOriginScale().first + 0.2, text->getOriginScale().second + 0.2));
                    text->setPosition(std::make_pair(text->getOriginPosition().first - 10, text->getOriginPosition().second - 10));
                } else {
                    text->setScale(text->getOriginScale());
                    text->setPosition(text->getOriginPosition());
                }
        }
    }
    return arcade::Input::UNDEFINED;
}*/

arcade::Input arcade::SFML_Lib::event(std::vector<std::shared_ptr<arcade::IObject>> objs)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _music.stop();
            _window.close();
            return arcade::Input::EXIT;
        }
        if(_event.type == sf::Event::KeyPressed) {
            switch (_event.key.code) {
                case sf::Keyboard::G:
                    _window.close();
                    return arcade::Input::PREVIOUSGRAPH;
                case sf::Keyboard::H:
                    _window.close();
                    return arcade::Input::NEXTGRAPH;
                case sf::Keyboard::B:
                    return arcade::Input::PREVIOUSGAME;
                case sf::Keyboard::N:
                    return arcade::Input::NEXTGAME;
                case sf::Keyboard::Space:
                    return arcade::Input::ACTION1;
                case sf::Keyboard::Escape:
                    return arcade::Input::MENU;
            }
        }

        // Desordered because key base was in ncurse
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            return arcade::Input::RIGHT;
            // return arcade::Input::UP;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            return arcade::Input::LEFT;
            //  return arcade::Input::DOWN;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            return arcade::Input::UP;
            // return arcade::Input::LEFT;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            return arcade::Input::DOWN;
            // return arcade::Input::RIGHT;
    }
    return arcade::Input::UNDEFINED;
}

extern "C" arcade::SFML_Lib *entryPoint() {
    return new (arcade::SFML_Lib);
}
