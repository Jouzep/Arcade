/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Tile
*/

#include "games/menu/Tile.hpp"

arcade::Tile::Tile()
{
}

arcade::Tile::~Tile()
{
}

std::string arcade::Tile::getTexture()
{
    return _texture;
}

std::pair<float, float> arcade::Tile::getPosition()
{
    return _position;
}

char arcade::Tile::getCharacter()
{

}

arcade::Color arcade::Tile::getColor()
{

}

std::pair<float, float> arcade::Tile::getScale()
{
    return _scale;
}

float arcade::Tile::getRotation()
{

}

void arcade::Tile::setTexture(std::string path)
{
    _texture = path;
}

void arcade::Tile::setPosition(std::pair<float, float> position)
{
    _position = position;
}

void arcade::Tile::setCharacter(char c)
{

}

void arcade::Tile::setColor(arcade::Color color)
{

}

void arcade::Tile::setScale(std::pair<float, float> scale)
{
    _scale = scale;
}

void arcade::Tile::setRotation(float rotation)
{

}

void arcade::Tile::unableClick()
{
    _clickable = true;
}

void arcade::Tile::disableClick()
{
    _clickable = false;
}


bool arcade::Tile::isClickable()
{
    return _clickable;
}