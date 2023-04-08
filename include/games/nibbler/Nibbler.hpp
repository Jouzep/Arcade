/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "IGames.hpp"
#include "IObject.hpp"
#include "games/Tile.hpp"
#include "games/Music.hpp"
#include "games/Text.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include "games/ConfHandler.hpp"
#include "games/snake/SnakeBody.hpp"
#include <ncurses.h>

#define ALIVE 46
#define START 45
#define MOVE 44

#define PACMAN 0
#define ENEMY1 1
#define ENEMY2 2
#define ENEMY3 3
#define ENEMY4 4

namespace arcade {
    class Nibbler : public IGames{
        std::string BLUEBOX = "assets/sprite/Bluebox_Pacman.png";
        std::string WHITEBOX = "assets/sprite/Whitebox_Pacman.png";
        std::string REDBOX = "assets/sprite/Redbox_Pacman.png";
        std::string YELLOWBOX = "assets/sprite/Yellowbox_Pacman.png";
        std::string BLACKBOX = "assets/sprite/Blackbox_Snake.png";
        std::string FOOD = "assets/sprite/pacmaneat.png";
        std::string LITTLEFOOD = "assets/sprite/littleeat.png";
        public:
            Nibbler();
            ~Nibbler();


            std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
            void snakeDeplacement(std::pair<std::size_t, std::size_t> head);
            void changeDirection();
            void do_game();
            bool snakeCollision();

            void handlingEvent(arcade::Input input);

            // ***************** BUILD IObjet *****************

            void createObjet();
            void pushFood(std::vector<std::string> _map);
            void pushSnake();
            void createFoodTile(std::shared_ptr<arcade::ITile> tile, std::pair<std::size_t, std::size_t> position, std::string Texture);

            // ***************** BUILD ITile *****************

            void createMap(std::vector<std::string> _map);
            void setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<std::size_t, std::size_t> position, std::string text);
            // ***************** BUILD IText *****************
            void pushText();
            void setText(std::shared_ptr<arcade::IText> text, std::string content, std::pair<std::size_t, std::size_t> position);

            // ***************** BUILD ISound *****************
            void pushSound();
            void setSound(std::shared_ptr<arcade::ISound> sound, std::string soundPath, float volume);

            std::shared_ptr<arcade::ISound> createSound();
            std::shared_ptr<arcade::ITile> createTile();
            std::shared_ptr<arcade::IText> createText();

            void restart();
            arcade::Input event(arcade::Input input);
            void endGame();

        protected:
        private:
            std::vector<int> direction;
            std::size_t score;
            std::vector<std::string> _map;
            std::pair<std::size_t, std::size_t> map;
            std::vector<std::shared_ptr<arcade::IObject>> _object;
            std::unique_ptr<SnakeBody> _snake;
            arcade::Input _input;
            int foodleft;
            ConfHandler conf;
            std::string highestscore;
            std::string highestname;
    };
}

extern "C" arcade::Nibbler *entryPoint();

#endif /* !PACMAN_HPP_ */
