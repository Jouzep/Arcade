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

std::string arcade::Text::getText()
{
    return _text;
}

arcade::Color arcade::Text::getColorText()
{

}

std::pair<float, float> arcade::Text::getPosition()
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

void arcade::Text::setPosition(std::pair<float, float> position)
{
    _position = position;
}
