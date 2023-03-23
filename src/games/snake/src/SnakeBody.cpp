/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeBody
*/

#include "games/snake/SnakeBody.hpp"

arcade::SnakeBody::SnakeBody(std::pair<std::size_t, std::size_t> map)
{
    srand(time(NULL));
    this->_map = map;
    this->setSnakeBody();
}

arcade::SnakeBody::~SnakeBody()
{
}

// ******* GETTER *******
std::vector<std::pair<std::size_t, std::size_t>> arcade::SnakeBody::getSnakeBody() const
{
    return _snake;
}

std::pair<std::size_t, std::size_t> arcade::SnakeBody::getMove() const
{
    return _move;
}

// ******* SETTER *******
void arcade::SnakeBody::setSnakeBody(void)
{
    int a = _map.first * 0.2;
    int b = _map.second * 0.2;
    int x = (rand() % (_map.first - a)) + a / 2;
    int y = (rand() % (_map.second - b)) + b / 2;
    _snake.push_back(std::make_pair(x, y));
    for (int i = 0; i != 5; i++)
        _snake.push_back(std::make_pair(x, y + i));
    _move = std::make_pair(1, 0);
}

void arcade::SnakeBody::setMove(std::pair<std::size_t, std::size_t> move)
{
    // this->_move = move;
    this->_move.first = move.first;
    this->_move.second = move.second;
}

// ******* Move Snake *******

bool arcade::SnakeBody::moveSnakeBody(std::pair<std::size_t, std::size_t> food)
{
    bool grow = false;

    for (std::size_t i = _snake.size(); i != -1; i--)
    {
        if (i == 0)
        {
            _snake[i].first += _move.first;
            _snake[i].second += _move.second;
        }
        else
        {
            if (_snake[i] == food && grow == false)
            {
                _snake.push_back(std::make_pair(_snake[i].first, _snake[i].second));
                grow = true;
            }
            _snake[i].first = _snake[i - 1].first;
            _snake[i].second = _snake[i - 1].second;
        }
    }
    return grow;
}