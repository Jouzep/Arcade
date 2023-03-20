/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Snake
*/

#include "Snake.hpp"

arcade::Snake::Snake()
{
    srand(time(NULL));
    _map = std::make_pair(50, 100);
    this->restart();
}

arcade::Snake::~Snake()
{
}

// ***************** LOOP *****************
std::vector<std::shared_ptr<arcade::IObject>> arcade::Snake::loop(arcade::Input input)
{
    pushObjet();
}

void arcade::Snake::pushObjet()
{
    // ------ build ITile ------
    pushMap();
    pushSnake();
    // ------ build IText ------
    pushText();
    // ------ build ISound ------
    pushSound();
}

// ***************** BUILD ITile *****************
void arcade::Snake::pushSnake()
{
    for (std::size_t i = 0; i != _snake.size(); i++)
    {
        auto a = createTile();
        a->setCharacter(' ');
        a->setTexture("snake_body");
        a->setPosition(_snake[i]);
        a->setColor(arcade::Color::GREEN);
        a->setScale(std::make_pair(1, 1));
        a->setRotation(0);
        _objects.push_back(a);
        if (i == 0)
        {
            a->setCharacter(':');
            a->setColor(arcade::Color::RED);
        }
    }
}

void arcade::Snake::pushMap()
{
    std::size_t x = 0;
    std::size_t y = 0;
    for (; x != _map.first; x++)
        setMapTile(createTile(), std::make_pair(x, y));
    y++;
    x--;
    for (; y != _map.second; y++)
        setMapTile(createTile(), std::make_pair(x, y));
    y--;
    for (; x != -1; x--)
        setMapTile(createTile(), std::make_pair(x, y));
    x++;
    for (; y != -1; y--)
        setMapTile(createTile(), std::make_pair(x, y));
};

void arcade::Snake::setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<float, float> position)
{
    tile->setCharacter(' ');
    tile->setTexture("wall");
    tile->setPosition(position);
    tile->setColor(arcade::Color::WHITE);
    tile->setScale(std::make_pair(1, 1));
    tile->setRotation(0);
    _objects.push_back(tile); // add the tile to the vector
}

// ***************** BUILD IText *****************
void arcade::Snake::pushText()
{
    setText(createText(), "Your Score:", std::make_pair(_map.first + 5, _map.second + 5));
    setText(createText(), std::to_string(_score), std::make_pair(_map.first + 6, _map.second + 5));
}

void arcade::Snake::setText(std::shared_ptr<arcade::IText> text, std::string content, std::pair<std::size_t, std::size_t> position)
{
    text->setColorText(arcade::Color::WHITE);
    text->setPosition(position);
    text->setText(content);
    this->_objects.push_back(text);
}

// ***************** BUILD ISound *****************
void arcade::Snake::pushSound()
{
    setSound(createSound(), "path", 1);
}
void arcade::Snake::setSound(std::shared_ptr<arcade::ISound> sound, std::string soundPath, float volume)
{
    sound->setSoundPath(soundPath);
    sound->setVolume(volume);
    this->_objects.push_back(sound);
}

// ***************** CREATOR *****************
std::shared_ptr<arcade::ISound> arcade::Snake::createSound()
{
    return std::make_shared<arcade::SnakeSound>();
}

std::shared_ptr<arcade::ITile> arcade::Snake::createTile()
{
    return std::make_shared<arcade::SnakeTile>();
}

std::shared_ptr<arcade::IText> arcade::Snake::createText()
{
    return std::make_shared<arcade::SnakeText>();
}

// ***************** RESTART *****************
void arcade::Snake::restart()
{
    int a = _map.first * 0.2;
    int b = _map.second * 0.2;
    int x = (rand() % (_map.first - a)) + a / 2;
    int y = (rand() % (_map.second - b)) + b / 2;
    _snake.push_back(std::make_pair(x, y));
    for (int i = 0; i != 5; i++)
        _snake.push_back(std::make_pair(x, y + i));
    _move = std::make_pair(1, 0);
    _score = 0;
    _objects.clear();
}
