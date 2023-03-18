/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Sprite
*/

#include "graphicals/SFML/Sprite.hpp"

arcade::Sprite::Sprite()
{
}

arcade::Sprite::Sprite(std::string filename)
{
    _texture.loadFromFile(filename);
    _sprite.setTexture(_texture);
}

arcade::Sprite::~Sprite()
{
}

sf::Sprite arcade::Sprite::getSprite()
{
    return _sprite;
}

sf::Texture arcade::Sprite::getTexture()
{
    return _texture;
}

void arcade::Sprite::setTexture(std::string filename)
{
    _texture.loadFromFile(filename);
    _sprite.setTexture(_texture);
}
