/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Tile
*/

#include "games/Tile.hpp"

arcade::Tile::Tile()
{
}

arcade::Tile::~Tile()
{
}

// ---- GETTERS ---- //

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
    return _char;
}

arcade::Color arcade::Tile::getColor() const
{
    return _color;
}

std::pair<float, float> arcade::Tile::getScale() const
{
    return _scale;
}

float arcade::Tile::getRotation() const
{
    return _rotation;
}

std::pair<float, float> arcade::Tile::getOriginScale()
{
    return _originScale;
}

std::pair<std::size_t, std::size_t> arcade::Tile::getOriginPosition()
{
    return _originPosition;
}

std::pair<std::size_t, std::size_t> arcade::Tile::getSize() const
{
    return _size;
}

arcade::Input arcade::Tile::getEvent() const
{
    return _event;
}

// ---- SETTERS ---- //

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
    _char = c;
}

void arcade::Tile::setColor(arcade::Color color)
{
    _color = color;
}

void arcade::Tile::setScale(std::pair<float, float> scale)
{
    _scale = scale;
}

void arcade::Tile::setRotation(float rotation)
{
    _rotation = rotation;
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

void arcade::Tile::setSize(std::pair<std::size_t, std::size_t> size)
{
    _size = size;
}

// ---- MISC ---- //

/*void arcade::Tile::enableClick()
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
}*/

void arcade::Tile::setName(std::string name)
{
    _name = name;
}

std::string arcade::Tile::getName() const
{
    return _name;
}
