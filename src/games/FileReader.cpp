/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** FileReader
*/

#include "games/FileReader.hpp"

FileReader::FileReader()
{

}

FileReader::FileReader(std::string filename)
{
    open(filename);
}

FileReader::~FileReader()
{
}


void FileReader::open(std::string filename)
{
   if (_file.is_open()) {
        _file.close();
        _content.clear();
    }
    _file.open(filename);

    if (_file.fail()) {
        throw FileReader::FileReaderError("Cannot open file");
    }

    std::string line;

    while (std::getline(_file, line)) {
        _content.push_back(line);
    }
}

std::vector<std::string> FileReader::getContent()
{
    return _content;
}
