/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SolarFox
*/

#include "games/solarfox/SolarFox.hpp"

arcade::SolarFox::SolarFox()
{
}

arcade::SolarFox::~SolarFox()
{
}

arcade::Input arcade::SolarFox::event(arcade::Input input)
{
    return arcade::Input::UNDEFINED;
}

std::vector<std::shared_ptr<arcade::IObject>> arcade::SolarFox::loop(arcade::Input input)
{
    return _objs;
}

void arcade::SolarFox::restart()
{

}

std::shared_ptr<arcade::ITile> arcade::SolarFox::createTile()
{

}

std::shared_ptr<arcade::ISound> arcade::SolarFox::createSound()
{

}

std::shared_ptr<arcade::IText> arcade::SolarFox::createText()
{

}

extern "C" arcade::SolarFox *entryPoint() {
    return new (arcade::SolarFox);
}