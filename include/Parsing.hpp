/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
#define PARSING_HPP_

#include "Error.hpp"
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>

class Parsing {
    public:
        Parsing(int ac, char **av);
        ~Parsing();

        std::string getLib() const;

    private:
        std::string _path_lib;
};

#endif /* !PARSING_HPP_ */
