/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Text
*/

#include "games/menu/Text.hpp"

arcade::Text::Text()
{
}

arcade::Text::~Text()
{
}

std::string arcade::Text::getText() const
{
    return _text;
}

arcade::Color arcade::Text::getColorText() const
{

}

std::pair<std::size_t, std::size_t> arcade::Text::getPosition() const
{
    return _position;
}

void arcade::Text::setText(std::string text)
{
    _text = text;
}

void arcade::Text::setColorText(arcade::Color)
{

}

void arcade::Text::setPosition(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
}
