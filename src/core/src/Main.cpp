/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Main
*/

#include "core/Parsing.hpp"
#include "core/DLLoader.hpp"
#include "IGraphics.hpp"
#include "core/Core.hpp"

int main(int argc, char **argv)
{
    arcade::Core core;
    try {
        Parsing content(argc, argv);
    }
    catch (const Error &error) {
        std::cout << error.what() << ": " << error.message() << '.' << std::endl;
        return 84;
    }
    DLLoader<arcade::IGraphics> dl(argv[1]);

    core.runCore(dl.getInstance());
    dl.closeInstance();
    return 0;
}
