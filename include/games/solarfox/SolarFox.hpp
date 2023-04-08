/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SolarFox
*/

#ifndef SOLARFOX_HPP_
    #define SOLARFOX_HPP_
    #include "IGames.hpp"
    #include "IObject.hpp"
    #include "games/Tile.hpp"
    #include "games/Music.hpp"
    #include "games/Text.hpp"
    #include "games/ConfHandler.hpp"
    #include <vector>

namespace arcade {
    class SolarFox : public IGames {
        public:
            SolarFox();
            ~SolarFox();

            arcade::Input event(arcade::Input input);
            std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
            void restart();
            std::shared_ptr<arcade::ITile> createTile();
            std::shared_ptr<arcade::ISound> createSound();
            std::shared_ptr<arcade::IText> createText();
        protected:
        private:
            std::vector<std::shared_ptr<arcade::IObject>> _objs;
    };
}

#endif /* !SOLARFOX_HPP_ */
