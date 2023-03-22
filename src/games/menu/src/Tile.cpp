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

std::string arcade::Tile::getTexture() const
{
    return _texture;
}

std::pair<std::size_t, std::size_t> arcade::Tile::getPosition() const
{
    return _position;
}

char arcade::Tile::getCharacter() const
{

}

arcade::Color arcade::Tile::getColor() const
{

}

std::pair<float, float> arcade::Tile::getScale() const
{
    return _scale;
}

float arcade::Tile::getRotation() const
{

}

void arcade::Tile::setTexture(std::string path)
{
    _texture = path;
}

void arcade::Tile::setPosition(std::pair<std::size_t, std::size_t> position)
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

std::pair<float, float> arcade::Tile::getOriginScale()
{
    return _originScale;
}

std::pair<std::size_t, std::size_t> arcade::Tile::getOriginPosition()
{
    return _originPosition;
}

std::pair<float, float> arcade::Tile::setOriginScale(std::pair<float, float> scale)
{
    _scale = scale;
    _originScale = scale;
}

std::pair<std::size_t, std::size_t> arcade::Tile::setOriginPosition(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
    _originPosition = position;
}

void arcade::Tile::setEvent(arcade::Input event)
{
    _event = event;
}

arcade::Input arcade::Tile::getEvent() const
{
    return _event;
}

void arcade::Tile::setSize(std::pair<std::size_t, std::size_t> size)
{
    _size = size;
}

std::pair<std::size_t, std::size_t> arcade::Tile::getSize() const
{
    return _size;
}
