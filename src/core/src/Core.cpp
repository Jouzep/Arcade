/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Core
*/

// #include "core/Core.hpp"
// #include "core/DLLoader.hpp"
// #include "IGames.hpp"
#include "../../../include/core/Core.hpp"
#include "../../../include/core/DLLoader.hpp"
#include "../../../include/IGames.hpp"
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
    IGames* game_lib = game_dl.getInstance();
    arcade::Input input;
    std::vector<std::shared_ptr<arcade::IObject>> objs;

    while (1) {
        input = lib->event();
        if (input == arcade::Input::EXIT) {
            break;
        }
        lib->clear();
        objs = game_lib->loop(input);
        for (auto o : objs) {
            lib->draw(o);
        }
        lib->display();
    }
    game_dl.closeInstance();
}