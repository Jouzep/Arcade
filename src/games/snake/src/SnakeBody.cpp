/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeBody
*/

#include "games/snake/SnakeBody.hpp"

arcade::SnakeBody::SnakeBody(std::pair<std::size_t, std::size_t> map, std::pair<int, int> pose)
{
    srand(time(NULL));
    this->_map = map;
    this->setSnakeBody(pose);
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
void arcade::SnakeBody::setSnakeBody(std::pair<int, int> pose)
{
    int x = (pose.first);
    int y = (pose.second);
    for (int i = 0; i != 5; i++)
        _snake.push_back(std::make_pair(x, y));
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

    for (std::size_t i = (_snake.size() - 1); i != -1; i--)
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

std::vector<std::string> arcade::SnakeBody::moveSnakeBody(std::vector<std::string> _map)
{
    int foodid = 0;
    auto headCharacter = _map[this->_snake[0].first][this->_snake[0].second];

    if (headCharacter == '2')
        _map[this->_snake[0].first][this->_snake[0].second] = ' ';
    for (std::size_t i = (_snake.size() - 1); i != -1; i--)
    {
        if (i == 0)
        {
            _snake[i].first += _move.first;
            _snake[i].second += _move.second;
        }
        else
        {
            if (headCharacter == '2' && i == _snake.size() - 1)
            {
                _snake.push_back(std::make_pair(_snake[i].first, _snake[i].second));
            }
            _snake[i].first = _snake[i - 1].first;
            _snake[i].second = _snake[i - 1].second;
        }
    }
    return _map;
}