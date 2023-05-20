/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Music
*/

#include "games/Music.hpp"

arcade::Music::Music()
{
}

arcade::Music::~Music()
{
}

// ---- GETTERS ---- //

std::string arcade::Music::getSoundPath() const
{
    return _soundPath;
}

float arcade::Music::getVolume() const
{
    return _volume;
}

// ---- SETTERS ---- //

void arcade::Music::setSoundPath(std::string path)
{
    _soundPath = path;
}

void arcade::Music::setVolume(float volume)
{
    _volume = volume;
}

// ---- MISC ---- //

void arcade::Music::pauseSound()
{

}

void arcade::Music::playSound()
{
    _playing = true;
}

void arcade::Music::stopSound()
{
    _playing = false;
}
