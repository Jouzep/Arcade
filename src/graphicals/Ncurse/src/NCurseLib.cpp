/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Test
*/

#include "IGraphics.hpp"
#include <iostream>
#include <ncurses.h>

const int UP_NCURSE =  259;
const int DOWN_NCURSE =  258;
const int LEFT_NCURSE =  260;
const int RIGHT_NCURSE =  261;
const int G_NCURSE =  103;
const int H_NCURSE =  104;
const int B_NCURSE = 98;
const int N_NCURSE = 110;

namespace arcade {
    class NCurseLib : public IGraphics {
        public:
            NCurseLib();
            ~NCurseLib();

            void display();
            void clear();

            void draw(std::shared_ptr<arcade::IObject> object);
            void drawTile(arcade::ITile* tile);
            void drawText(arcade::IText* text);
            arcade::Input event(std::vector<std::shared_ptr<arcade::IObject>> objs);

        protected:
        private:
            SCREEN *_screen;
    };
}

arcade::NCurseLib::NCurseLib()
{
    _screen = newterm(getenv("term"), stdout, stdin);
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(arcade::Color::BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(arcade::Color::RED, COLOR_RED, COLOR_RED);
    init_pair(arcade::Color::GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(arcade::Color::DARK, COLOR_BLACK, COLOR_BLACK);
    init_pair(arcade::Color::YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(arcade::Color::WHITE, COLOR_WHITE, COLOR_WHITE);
}

arcade::NCurseLib::~NCurseLib()
{
    endwin();
    delscreen(_screen);
}

void arcade::NCurseLib::display()
{
    // std::cout << "display" << std::endl;
}

void arcade::NCurseLib::clear()
{
    // clear();
    wclear(stdscr);
    // std::cout << "clear" << std::endl;
}

void arcade::NCurseLib::draw(std::shared_ptr<arcade::IObject> object)
{
    arcade::ITile* _tile = dynamic_cast<arcade::ITile*>(object.get());
    if (_tile != nullptr) {
            _tile->setPosition(std::make_pair(_tile->getPosition().second, _tile->getPosition().first));
            drawTile(_tile);
            return;
    }

    // arcade::ISound* _sound = dynamic_cast<arcade::ISound*>(object.get());
    // if (_sound != nullptr) {
    //     if (_music.getStatus() != sf::Music::Playing) {
    //         if (_music.openFromFile(_sound->getSoundPath())) {
    //             std::cout << "ok " << _music.getStatus() << std::endl;
    //             _music.setLoop(true);
    //             _music.play();
    //         }
    //     }
    // }

    arcade::IText* text = dynamic_cast<arcade::IText*>(object.get());
    if (text != nullptr) {
        text->setPosition(std::make_pair(text->getPosition().second, text->getPosition().first));
        drawText(text);
        return;
    }
}

void arcade::NCurseLib::drawText(arcade::IText* text)
{
    auto position = text->getPosition();
    auto content = text->getText();
    auto color = text->getColorText();

    // attron(COLOR_PAIR(color));
    mvprintw(position.first, position.second, "%s", content.c_str());
    // attroff(COLOR_PAIR(color));
}
void arcade::NCurseLib::drawTile(arcade::ITile* tile)
{
    auto position = tile->getPosition();
    auto character = tile->getCharacter();
    auto color = tile->getColor();

    attron(COLOR_PAIR(color));
    mvprintw(position.first, position.second, "%c", character);
    attroff(COLOR_PAIR(color));

}

arcade::Input arcade::NCurseLib::event(std::vector<std::shared_ptr<arcade::IObject>> objs)
{
    int input = getch(); // atted

    if (input == B_NCURSE)
        return arcade::Input::PREVIOUSGAME;
    if (input == N_NCURSE)
        return arcade::Input::NEXTGAME;
    if (input == G_NCURSE)
        return arcade::Input::PREVIOUSGRAPH;
    if (input == H_NCURSE)
        return arcade::Input::NEXTGRAPH;
    if (input == UP_NCURSE)
        return arcade::Input::RIGHT;
    if (input == LEFT_NCURSE)
        return arcade::Input::UP;
    if (input == RIGHT_NCURSE)
        return arcade::Input::DOWN;
    if (input == DOWN_NCURSE)
        return arcade::Input::LEFT;
    return arcade::Input::UNDEFINED;
}

extern "C" arcade::NCurseLib *entryPoint() {
    return new (arcade::NCurseLib);
}