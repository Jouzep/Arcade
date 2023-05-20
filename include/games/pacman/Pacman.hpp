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
#include "games/ConfHandler.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
    class Pacman : public IGames{
        std::string BLUEBOX = "assets/sprite/Bluebox_Pacman.png";
        std::string WHITEBOX = "assets/sprite/Whitebox_Pacman.png";
        std::string REDBOX = "assets/sprite/Redbox_Pacman.png";
        std::string YELLOWBOX = "assets/sprite/Yellowbox_Pacman.png";
        std::string BLACKBOX = "assets/sprite/Blackbox_Snake.png";
        std::string FOOD = "assets/sprite/pacmaneat.png";
        std::string LITTLEFOOD = "assets/sprite/littleeat.png";
        public:
            Pacman();
            ~Pacman();

            bool getLoose(std::vector<std::string> _map);
            std::pair<int, int> getPose(int index) const;

            void setPose(std::pair<int, int> pose);
            void setMove(std::pair<int, int> move, int mob);

            std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);

            void changePose(std::vector<std::string> map, size_t mob);


            std::vector<std::string> print_pacman(std::pair<int, int> pose, std::vector<std::string> _map);
            void print_ghost(std::pair<int, int> pose, int direction, int mob);

            void care_ghost(std::vector<std::string> _map);
            void do_game();
            void reset_ghost(int index, std::vector<std::string> _map);

            arcade::Input whichInput();
            void handlingEvent(arcade::Input input, int mob);

            // ***************** BUILD IObjet *****************

            void createObjet();
            void pushPacman();
            void pushEnemy(int mob);
            void pushFood(std::vector<std::string> _map);
            void createFoodTile(std::shared_ptr<arcade::ITile> tile, std::pair<std::size_t, std::size_t> position, std::string Texture);

            // ***************** BUILD ITile *****************

            void createMap(std::vector<std::string> _map);
            arcade::Color whichColor(std::vector<std::string> _map, std::pair<std::size_t, std::size_t> position);
            std::string whichSprite(std::vector<std::string> _map, std::pair<std::size_t, std::size_t> position);
            void setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<std::size_t, std::size_t> position);
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
            void endGame();
            arcade::Input event(arcade::Input input);

        protected:
        private:
            std::vector<std::pair<int, int>> _move;
            std::vector<std::pair<int, int>> _pose;
            std::vector<std::size_t> _mob;
            std::vector<int> direction;
            std::string username;
            std::size_t saveTick;
            std::size_t mobid;
            std::size_t tick;
            std::size_t mod;
            std::string highestscore;
            std::string highestname;
            std::size_t score;
            std::size_t win;
            std::vector<std::string> _map;
            std::pair<std::size_t, std::size_t> map;

            std::vector<std::shared_ptr<arcade::IObject>> _object;
            arcade::Input _input;
            ConfHandler conf;
    };
}

extern "C" arcade::Pacman *entryPoint();

#endif /* !PACMAN_HPP_ */
