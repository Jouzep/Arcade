/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Main
*/

#include "core/Parsing.hpp"

int main(int argc, char **argv)
{
    try {
        Parsing content(argc, argv);
    }
    catch (const Error &error) {
        std::cout << error.what() << ": " << error.message() << '.' << std::endl;
        return 84;
    }
    return 0;
}
