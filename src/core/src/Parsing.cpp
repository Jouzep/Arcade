/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Parsing
*/

#include "core/Parsing.hpp"
#include <fstream>
#include <iostream>

Parsing::Parsing(int ac, char **av)
{
    std::ifstream file(av[1]);
    if (ac != 2)
        throw Error(std::to_string(ac) + "Arguments", "Should only contain 1 argument");
    if (!file)
        throw Error(av[1], "No such file");
    _path_lib = std::string(av[1]);
}

Parsing::~Parsing()
{
}

std::string Parsing::getLib() const
{
    return _path_lib;
}