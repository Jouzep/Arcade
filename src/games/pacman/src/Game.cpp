/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Game
*/

#include "games/pacman/Game.hpp"

std::vector<std::string> get_file_content(const std::string filename) {
    std::ifstream _file(filename);
    std::vector<std::string> content;
    std::string line;
    if (_file.is_open())
    {
        while (std::getline(_file, line))
            content.push_back(line);
        _file.close();
    }
    else
        exit;
    return content;
}

arcade::GamePacM::GamePacM()
{
    this->win = 220;
    this->_map = get_file_content("map.txt");
    // initscr();
    // noecho();
    // keypad(stdscr, TRUE);
    // curs_set(0);
    // start_color();
    // // init_pair(1, COLOR_BLACK, COLOR_BLUE);
    // // init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    // // init_pair(3, COLOR_WHITE, COLOR_BLACK);
    // // init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    // // init_pair(5, COLOR_GREEN, COLOR_BLACK);
    // // init_pair(6, COLOR_BLUE, COLOR_BLACK);
    // // init_pair(7, COLOR_WHITE, COLOR_BLACK);
    // // init_pair(8, COLOR_WHITE, COLOR_WHITE);
}

arcade::GamePacM::~GamePacM()
{
}

int arcade::GamePacM::getWin() const
{
    return this->win;
}

int arcade::GamePacM::getScore() const
{
    return this->score;
}

std::vector<std::string> arcade::GamePacM::getMap() const
{
    return this->_map;
}

void arcade::GamePacM::setWin(int _win)
{
    this->win = _win;
}

void arcade::GamePacM::setMap(std::vector<std::string> modif_map)
{
    this->_map = modif_map;
}

void arcade::GamePacM::setScore(int _score)
{
    this->score += _score;
}

void arcade::GamePacM::print_other()
{
    mvprintw(26, 30, "%d", this->score);
    for (int i = 0; i < 25; i++) {
        for (int a = 0; a < 25 ; a++) {
            print_map(i , a);
            print_food(i, a);
        }
    }
}

void arcade::GamePacM::print_map(int i, int a)
{
    if (_map[i][a] == '1') {
        attron(COLOR_PAIR(BLUE) | A_BOLD);
        mvprintw(i, a, " ");
        attroff(COLOR_PAIR(BLUE) | A_BOLD);
    }
}

void arcade::GamePacM::print_food(int i, int a)
{
    switch (_map[i][a]) {
        case '0' : {
            attron(COLOR_PAIR(2));
            mvprintw(i, a, ".");
            attroff(COLOR_PAIR(2));
            break;
        }
        case '2' : {
            attron(COLOR_PAIR(2) | A_BOLD);
            mvprintw(i, a, ".");
            attroff(COLOR_PAIR(2) | A_BOLD);
            break;
        }
        case '9' : {
            attron(COLOR_PAIR(8));
            mvprintw(i, a, " ");
            attroff(COLOR_PAIR(8));
        }
    }
}