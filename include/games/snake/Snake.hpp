/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "IGames.hpp"
#include "IObject.hpp"
#include "SnakeTile.hpp"
#include "SnakeSound.hpp"
#include "SnakeText.hpp"

namespace arcade
{
    class Snake : public IGames
    {
    public:
        Snake();
        ~Snake();
        std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
        void restart();

        // ***************** CREATOR *****************

        std::shared_ptr<arcade::ISound> createSound();
        std::shared_ptr<arcade::ITile> createTile();
        std::shared_ptr<arcade::IText> createText();

        // ***************** BUILD ITile *****************

        void setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<float, float> position);
        void pushMap();
        void pushSnake();

        // ***************** BUILD IText *****************
        void pushText();
        void setText(std::shared_ptr<arcade::IText> text, std::string content, std::pair<std::size_t, std::size_t> position);

        // ***************** BUILD ISound *****************
        void pushSound();
        void setSound(std::shared_ptr<arcade::ISound> sound, std::string soundPath, float volume);

        // ***************** BUILD IObjet *****************

        void pushObjet();

    protected:
    private:
        std::vector<std::shared_ptr<arcade::IObject>> _objects;
        arcade::Input _input;
        std::vector<std::pair<std::size_t, std::size_t>> _snake;
        std::pair<std::size_t, std::size_t> _move;
        std::pair<std::size_t, std::size_t> _map;
        std::size_t _score;
    };
}
#endif /* !SNAKE_HPP_ */
