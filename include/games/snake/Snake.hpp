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
#include "games/Tile.hpp"
#include "games/Music.hpp"
#include "games/Text.hpp"
#include "SnakeBody.hpp"
#include "SnakeFood.hpp"

namespace arcade
{

    class Snake : public IGames
    {
        std::string BLACKBOX = "assets/sprite/Blackbox_Snake.png";
        std::string GREENBOX = "assets/sprite/Grennbox_Snake.png";
        std::string GREYBOX = "assets/sprite/Greybox_Snake.png";
        std::string LIGHTGREENBOX = "assets/sprite/LightGreenbox_Snake.png";
        std::string YELLOWBOX = "assets/sprite/Yellowbox_Snake.png";
    public:
        Snake();
        ~Snake();
        void restart(); // RESET GAME

        // ***************** CREATOR *****************

        std::shared_ptr<arcade::ISound> createSound();
        std::shared_ptr<arcade::ITile> createTile();
        std::shared_ptr<arcade::IText> createText();

        // ***************** PLAY GAME *****************

        std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
        void do_game();
        void foodIsEaten(bool eaten);
        bool snakeCollision();
        void handlingEvent(arcade::Input input);
        // ***************** BUILD IObjet *****************

        void pushObjet();

        // ***************** BUILD ITile *****************

        void setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<float, float> position);
        void pushMap();
        void pushSnake();
        void pushFood();
        // ***************** BUILD IText *****************
        void pushText();
        void setText(std::shared_ptr<arcade::IText> text, std::string content, std::pair<std::size_t, std::size_t> position);

        // ***************** BUILD ISound *****************
        void pushSound();
        void setSound(std::shared_ptr<arcade::ISound> sound, std::string soundPath, float volume);

        arcade::Input event(arcade::Input input){};
    protected:
    private:
        std::vector<std::shared_ptr<arcade::IObject>> _objects;
        arcade::Input _input;
        // std::vector<std::pair<std::size_t, std::size_t>> _snake;
        // std::pair<std::size_t, std::size_t> _move;
        std::pair<std::size_t, std::size_t> _map;
        std::size_t _score;
        std::unique_ptr<SnakeBody> _snake;
        std::unique_ptr<SnakeFood> _food;
    };
}
#endif /* !SNAKE_HPP_ */
