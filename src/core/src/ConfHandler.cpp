/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** ConfHandler
*/

#include "core/ConfHandler.hpp"

ConfHandler::ConfHandler()
{
}

ConfHandler::~ConfHandler()
{
    _file.close();
}

ConfHandler::ConfHandler(std::string configFile)
{
    setConfigFile(configFile);
}

void ConfHandler::setConfigFile(std::string configFile)
{
    _configFile = configFile;

    _file.open(_configFile);

    if (_file.fail()) {
        throw ConfHandler::ConfHandlerError("Cannot open file");
    }
    storeConfigToMap();
}

std::string ConfHandler::getConfigFileName()
{
    return _configFile;
}

void ConfHandler::storeConfigToMap()
{
    std::string line;

    while (std::getline(_file, line)) {
        if (line[0] != '#' && line.size() != 0) {
            std::stringstream ss(line);
            std::string key;
            std::string value;

            // Get the key
            ss >> key;
            // Then the value
            ss >> value;
            _configs.insert({key, value});
        }
    }
}

std::map<std::string, std::string> ConfHandler::getConfigData()
{
    return _configs;
}

void ConfHandler::saveConfig(std::string key, std::string value)
{
    std::string line;
    std::vector<std::string> lines;

    // reset the ifsteam
    _file.clear();
    _file.seekg(0, std::ios_base::beg);
    while (std::getline(_file, line)) {
        lines.push_back(line);
    }

    _ofile.open(_configFile);

    if (_ofile.fail()) {
        throw ConfHandler::ConfHandlerError("Cannot open file");
    }

    for (auto l : lines) {
        if (l[0] != '#' && l.size() != 0) {
            std::stringstream ss(l);
            std::string word;

            ss >> word;
            if (word == key) {
                l = key + " " + value;
            }
        }
        _ofile << l << std::endl;
    }
    _ofile.close();
}
