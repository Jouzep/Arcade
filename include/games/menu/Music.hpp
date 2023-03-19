/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Music
*/

#ifndef MUSIC_HPP_
    #define MUSIC_HPP_
    #include "IObject.hpp"

namespace arcade {
    class Music : virtual public ISound {
        public:
            Music();
            ~Music();
            std::string getSoundPath();
            float getVolume();
            void setSoundPath(std::string path);
            void setVolume(float volume);
            void pauseSound();
            void playSound();
            void stopSound();
        protected:
        private:
            std::string _soundPath;
            float _volume;
            bool _playing = false;
    };
}

#endif /* !MUSIC_HPP_ */
