/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <ncurses.h>
#include "IGames.hpp"
#include "IObject.hpp"
#include "Game.hpp"
#include "games/Tile.hpp"
#include "games/Music.hpp"
#include "games/Text.hpp"

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
        public:
            Pacman();
            ~Pacman();

            bool getLoose(std::vector<std::string> _map);
            std::pair<int, int> getPose(int index) const;

            void setPose(std::pair<int, int> pose);

            std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);

            void change_direction(arcade::Input key, std::vector<std::string> _map, int mob);
            void changePose(std::vector<std::string> map, int mob);


            std::vector<std::string> print_pacman(std::pair<int, int> pose, std::vector<std::string> _map);
            void print_ghost(std::pair<int, int> pose, int direction, int mob);


            void care_ghost(std::vector<std::string> _map);
            void do_game();
            void reset_ghost(int index, std::vector<std::string> _map);

            arcade::Input whichInput();
            void handlingEvent(arcade::Input input, int mob);

            // ***************** BUILD IObjet *****************

            void createObjet();

            // ***************** BUILD ITile *****************

            void createMap(std::vector<std::string> _map);
            arcade::Color whichColor(std::vector<std::string> _map, std::pair<int, int> position);
            void setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<int, int> position);
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
        protected:
        private:
            std::vector<std::pair<int, int>> _move;
            std::vector<std::pair<int, int>> _pose;
            std::pair<int, int> _map;
            std::vector<int> _mob;
            std::vector<int> direction;
            int mobid;
            int dead;
            int tick;
            int mod;
            int touch;
            int score;
            std::vector<std::shared_ptr<arcade::IObject>> _object;
            std::unique_ptr<GamePacM> _game;
    };
}

#endif /* !PACMAN_HPP_ */
