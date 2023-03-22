/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeText
*/

#include "games/snake/SnakeText.hpp"

arcade::SnakeText::SnakeText::SnakeText()
{
}

arcade::SnakeText::~SnakeText()
{
}

// ***************** GETTER *****************

std::string arcade::SnakeText::getText() const
{
    return this->_text;
}

arcade::Color arcade::SnakeText::getColorText() const
{
    return this->_color;
}

std::pair<std::size_t, std::size_t> arcade::SnakeText::getPosition() const
{
    return this->_position;
}

// ***************** SETTER *****************

void arcade::SnakeText::setText(std::string text)
{
    this->_text = text;
}

void arcade::SnakeText::setColorText(arcade::Color color)
{
    this->_color = color;
}

void arcade::SnakeText::setPosition(std::pair<std::size_t, std::size_t> position)
{
    this->_position = position;
}