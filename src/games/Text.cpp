/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Text
*/

#include "games/Text.hpp"

arcade::Text::Text()
{
}

arcade::Text::~Text()
{
}

// ---- GETTERS ---- //

std::pair<float, float> arcade::Text::getScale() const
{
    return _scale;
}

std::string arcade::Text::getText() const
{
    return _text;
}

arcade::Color arcade::Text::getColorText() const
{
    return _color;
}

std::pair<std::size_t, std::size_t> arcade::Text::getPosition() const
{
    return _position;
}

std::pair<float, float> arcade::Text::getOriginScale()
{
    return _originScale;
}

std::pair<std::size_t, std::size_t> arcade::Text::getOriginPosition()
{
    return _originPosition;
}

arcade::Input arcade::Text::getEvent() const
{
    return _event;
}

// ---- SETTERS ---- //

void arcade::Text::setText(std::string text)
{
    _text = text;
}

void arcade::Text::setColorText(arcade::Color color)
{
    _color = color;
}

void arcade::Text::setPosition(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
}

void arcade::Text::setRotation(float rotation)
{
    _rotation = rotation;
}

void arcade::Text::setOriginScale(std::pair<float, float> scale)
{
    _scale = scale;
    _originScale = scale;
}

void arcade::Text::setOriginPosition(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
    _originPosition = position;
}

void arcade::Text::setEvent(arcade::Input event)
{
    _event = event;
}

void arcade::Text::setScale(std::pair<float, float> scale)
{
    _scale = scale;
}

// ---- MISC ---- //

bool arcade::Text::isClickable()
{
    return _clickable;
}

void arcade::Text::enableClick()
{
    _clickable = true;
}

void arcade::Text::disableClick()
{
    _clickable = false;
}
