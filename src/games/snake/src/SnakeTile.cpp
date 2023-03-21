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

std::string arcade::SnakeTile::getTexture() const
{
    return _texture;
}

std::pair<std::size_t, std::size_t> arcade::SnakeTile::getPosition() const
{
    return _position;
}

char arcade::SnakeTile::getCharacter() const
{
    return _char;
}

arcade::Color arcade::SnakeTile::getColor() const
{
    return _color;
}

std::pair<float, float> arcade::SnakeTile::getScale() const
{
    return _scale;
}

float arcade::SnakeTile::getRotation() const
{
    return _rotation;
}

// ***************** SETTER *****************

void arcade::SnakeTile::setTexture(std::string path)
{
    _texture = path;
}

void arcade::SnakeTile::setPosition(std::pair<std::size_t, std::size_t> position)
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

void arcade::SnakeTile::setScale(std::pair<std::size_t, std::size_t> position)
{
    this->_scale.first = this->_scale.first;
    this->_scale.second = this->_scale.second;
}

void arcade::SnakeTile::setRotation(float rotation)
{
    this->_rotation = rotation;
}