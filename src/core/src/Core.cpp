/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Core
*/

#include "core/Core.hpp"
#include <iostream>

arcade::Core::Core()
{
}

arcade::Core::~Core()
{
}

void arcade::Core::runCore(IGraphics *lib)
{
    while (1) {
        if (lib->event() == arcade::IGraphics::Input::EXIT) {
            break;
        };
        lib->clear();
        lib->display();
    }
}