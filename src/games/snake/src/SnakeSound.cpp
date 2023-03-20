/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeSound
*/

#include "SnakeSound.hpp"

arcade::SnakeSound::SnakeSound()
{
}

arcade::SnakeSound::~SnakeSound()
{
}

// ***************** GETTER *****************

std::string arcade::SnakeSound::getSoundPath()
{
    return _sound;
}

float arcade::SnakeSound::getVolume()
{
    return _volume;
}

// ***************** SETTER *****************

void arcade::SnakeSound::setSoundPath(std::string path)
{
}

void arcade::SnakeSound::setVolume(float volume)
{
}

void arcade::SnakeSound::pauseSound()
{
}

void arcade::SnakeSound::playSound()
{
}

void arcade::SnakeSound::stopSound()
{
}