/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

// #include "Pacman.hpp"
#include "IObject.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <ncurses.h>

namespace arcade {
    class GamePacM {
        public:
            GamePacM();
            ~GamePacM();

            int getWin() const;
            int getScore() const;
            std::vector<std::string> getMap() const;

            void setWin(int _win);
            void setMap(std::vector<std::string> modif_map);
            void setScore(int _score);

            void print_other();
            void print_map(int i, int a);
            void print_food(int i, int a);
            protected:
            private:
                std::vector<std::string> _map;
                int score;
                int win;
    };
}

#endif /* !GAME_HPP_ */
