/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeSound
*/

#ifndef SNAKESOUND_HPP_
#define SNAKESOUND_HPP_

#include "IObject.hpp"

namespace arcade
{
    class SnakeSound : public ISound
    {
    public:
        SnakeSound();
        ~SnakeSound();

        // ----- GETTER -----
        std::string getSoundPath();
        float getVolume();

        // ----- SETTER -----
        void setSoundPath(std::string path);
        void setVolume(float volume);
        void pauseSound();
        void playSound();
        void stopSound();

    protected:
    private:
        float _volume;
        std::string _sound;
    };
}
#endif /* !SNAKESOUND_HPP_ */
