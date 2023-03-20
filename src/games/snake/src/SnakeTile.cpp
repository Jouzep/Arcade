/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeTile
*/

#include "SnakeTile.hpp"

arcade::SnakeTile::SnakeTile()
{
}

arcade::SnakeTile::~SnakeTile()
{
}

// ***************** GETTER *****************

std::string arcade::SnakeTile::getTexture()
{
    return _texture;
}

std::pair<float, float> arcade::SnakeTile::getPosition()
{
    return _position;
}

char arcade::SnakeTile::getCharacter()
{
    return _char;
}

arcade::Color arcade::SnakeTile::getColor()
{
    return _color;
}

std::pair<float, float> arcade::SnakeTile::getScale()
{
    return _scale;
}

float arcade::SnakeTile::getRotation()
{
    return _rotation;
}

// ***************** SETTER *****************

void arcade::SnakeTile::setTexture(std::string path)
{
    _texture = path;
}

void arcade::SnakeTile::setPosition(std::pair<float, float> position)
{
    this->_position.first = position.first;
    this->_position.second = position.second;
}

void arcade::SnakeTile::setCharacter(char c)
{
    this->_char = c;
}

void arcade::SnakeTile::setColor(arcade::Color color)
{
    this->_color = color;
}

void arcade::SnakeTile::setScale(std::pair<float, float> position)
{
    this->_scale.first = this->_scale.first;
    this->_scale.second = this->_scale.second;
}

void arcade::SnakeTile::setRotation(float rotation)
{
    this->_rotation = rotation;
}
