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
    #include "games/FileReader.hpp"

namespace arcade {
    class SolarFox : public IGames {
        public:
            SolarFox();
            ~SolarFox();

            enum DIRECTION {
                UP,
                DOWN,
                RIGHT,
                LEFT
            };

            arcade::Input event(arcade::Input input);
            std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
            void restart();
            std::shared_ptr<arcade::ITile> createTile();
            std::shared_ptr<arcade::ISound> createSound();
            std::shared_ptr<arcade::IText> createText();

            void pushWalls();
            void pushPlayer();
            void pushGui();
            void changeDirection(arcade::Tile &player);
            void setDirection(arcade::Input input);
        protected:
        private:
            arcade::SolarFox::DIRECTION _direction = LEFT;
            std::pair<int, int> _playerPos = std::make_pair(16, 10);
            FileReader _fr;
            std::vector<std::shared_ptr<arcade::IObject>> _objs;
    };
}

#endif /* !SOLARFOX_HPP_ */
