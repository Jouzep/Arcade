/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeFood
*/

#include "games/snake/SnakeFood.hpp"

arcade::SnakeFood::SnakeFood(std::pair<std::size_t, std::size_t> map)
{
    srand(time(NULL));
    this->_map = map;
    this->setRandomPosition();
}

arcade::SnakeFood::~SnakeFood()
{
}

// ******* SETTER *******
void arcade::SnakeFood::setRandomPosition(void)
{
    std::size_t x = rand() % (this->_map.first - 1) + 1;
    std::size_t y = rand() % (this->_map.second - 1) + 1;
    _position = std::make_pair(x, y);
}

// ******* GETTER *******
std::pair<std::size_t, std::size_t> arcade::SnakeFood::getPosition() const
{
    return this->_position;
}