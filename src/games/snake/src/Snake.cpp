/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Snake
*/

#include "games/snake/Snake.hpp"
#include "unistd.h"

arcade::Snake::Snake()
{
    _map = std::make_pair(50, 100);
    this->restart();
}

arcade::Snake::~Snake()
{
}

// ***************** PLAY GAME *****************
std::vector<std::shared_ptr<arcade::IObject>> arcade::Snake::loop(arcade::Input input)
{
    do_game();
    pushObjet();
    return this->_objects;
}

void arcade::Snake::do_game()
{
    // auto eaten = this->_snake->moveSnakeBody(this->_food->getPosition()); // move snake body
    // this->foodIsEaten(eaten);
    // if (this->snakeCollision() == true) // check if snake collide
    //     this->restart();
}

void arcade::Snake::foodIsEaten(bool eaten)
{
    if (eaten)
    {
        this->_food->setRandomPosition();
        this->_score++;
    }
}

bool arcade::Snake::snakeCollision()
{
    auto head_position = this->_snake->getSnakeBody()[0]; // get head position
    auto body_positions = this->_snake->getSnakeBody();   // get snake body

    for (std::size_t i = 1; i != body_positions.size(); i++) // check if snake touch his body
    {
        auto tmp = body_positions[i];
        if (head_position == tmp)
            return true;
    }
    if (head_position.second == 0 || head_position.second == _map.second) // check if snake touch the horizontal border
        return true;
    if (head_position.first == 0 || head_position.first == _map.first) // check if snake touch the vertical border
        return true;
    return false;
}

void arcade::Snake::handlingEvent(arcade::Input input)
{
    switch (input)
    {
    case arcade::Input::UNDEFINED:
        break;
    case arcade::Input::LEFT:
        if (this->_move.second != -1)
            this->_move = std::make_pair(0, 1);
        break;
    case arcade::Input::RIGHT:
        if (this->_move.second != 1)
            this->_move = std::make_pair(0, -1);
        break;
    case arcade::Input::UP:
        if (this->_move.first != 1)
            this->_move = std::make_pair(-1, 0);
        break;
    case arcade::Input::DOWN:
        if (this->_move.first != -1)
            this->_move = std::make_pair(1, 0);
        break;
    case arcade::Input::ACTION1:
        break;
    case arcade::Input::NEXTGRAPH:
        break;
    case arcade::Input::NEXTGAME:
        break;
    case arcade::Input::PREVIOUSGRAPH:
        break;
    case arcade::Input::PREVIOUSGAME:
        break;
    case arcade::Input::RESTART:
        break;
    case arcade::Input::MENU:
        break;
    case arcade::Input::EXIT:
        break;
    }
}

// ***************** BUILD IObjet *****************

void arcade::Snake::pushObjet()
{
    this->_objects.clear();
    // ------ build ITile ------
    pushMap();
    pushSnake();
    pushFood();
    // ------ build IText ------
    pushText();
    // ------ build ISound ------
    pushSound();
}

// ***************** BUILD ITile *****************

void arcade::Snake::pushFood()
{
    auto a = createTile();
    a->setCharacter(' ');
    a->setPosition(this->_food->getPosition());
    a->setColor(arcade::Color::YELLOW);
    a->setScale(std::make_pair(1, 1));
    a->setRotation(0);
    a->setTexture(YELLOWBOX);
    _objects.push_back(a);
}

void arcade::Snake::pushSnake()
{
    auto body = _snake->getSnakeBody();
    for (std::size_t i = 0; i != body.size(); i++)
    {
        auto a = createTile();
        a->setCharacter(' ');
        a->setPosition(body[i]);
        a->setColor(arcade::Color::GREEN);
        a->setScale(std::make_pair(1, 1));
        a->setRotation(0);
        a->setTexture(GREENBOX);
        _objects.push_back(a);
        if (i == 0)
        {
            a->setTexture(GREENBOX);
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
    tile->setPosition(position);
    tile->setColor(arcade::Color::WHITE);
    tile->setScale(std::make_pair(1, 1));
    tile->setRotation(0);
    tile->setTexture(GREYBOX);
    _objects.push_back(tile); // add the tile to the vector
}

// ***************** BUILD IText *****************
void arcade::Snake::pushText()
{
    setText(createText(), "Your Score:", std::make_pair((_map.first + 1), (_map.second + 1)));
    setText(createText(), std::to_string(_score), std::make_pair(_map.first + 2, _map.second + 1));
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
    return std::make_shared<arcade::Music>();
}

std::shared_ptr<arcade::ITile> arcade::Snake::createTile()
{
    return std::make_shared<arcade::Tile>();
}

std::shared_ptr<arcade::IText> arcade::Snake::createText()
{
    return std::make_shared<arcade::Text>();
}

// ***************** RESTART *****************
void arcade::Snake::restart()
{
    this->_snake = std::make_unique<SnakeBody>(this->_map); // Build Snake Body
    this->_food = std::make_unique<SnakeFood>(this->_map);  // Build Snake Food
    _score = 0;
    _objects.clear();
}

extern "C" arcade::Snake *entryPoint() {
    return new (arcade::Snake);
}
