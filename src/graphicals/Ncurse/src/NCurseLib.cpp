/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Test
*/

#include "IGraphics.hpp"
#include <iostream>
#include <ncurses.h>

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
            
    };
}

arcade::NCurseLib::NCurseLib()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(arcade::Color::BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(arcade::Color::RED, COLOR_RED, COLOR_RED);
    init_pair(arcade::Color::GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(arcade::Color::DARK, COLOR_BLACK, COLOR_BLACK);
    init_pair(arcade::Color::YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(arcade::Color::WHITE, COLOR_WHITE, COLOR_WHITE);
}

arcade::NCurseLib::~NCurseLib()
{
    endwin();
}

void arcade::NCurseLib::display()
{
    getch();
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
    // std::cout << "event" << std::endl;
    return arcade::Input::UNDEFINED;
}

extern "C" arcade::NCurseLib *entryPoint() {
    return new (arcade::NCurseLib);
}