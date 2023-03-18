/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Core
*/

#include "core/Core.hpp"
#include "core/DLLoader.hpp"
#include "IGames.hpp"
#include <iostream>

arcade::Core::Core()
{
}

arcade::Core::~Core()
{
}

void arcade::Core::runCore(IGraphics *lib)
{
    DLLoader<arcade::IGames> game_dl("lib/arcade_menu.so");
    game_dl.closeInstance();
    while (1) {
        if (lib->event() == arcade::Input::EXIT) {
            break;
        };
        lib->clear();
        lib->draw(nullptr);
        lib->display();
    }
}