/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Enemies
*/

#ifndef ENEMIES_HPP_
    #define ENEMIES_HPP_
    #include <vector>
    #include "IObject.hpp"
    #include "games/Tile.hpp"
    #include <memory>
    #include <array>

namespace arcade {
    class Enemies {
        public:
            Enemies();
            ~Enemies();

            enum DIRECTION {
                UP,
                DOWN,
                RIGHT,
                LEFT
            };
            void pushEnemies();
            void getEnemies();
        protected:
        private:

            std::array<DIRECTION, 4> _enemyDirection;
            std::array<std::pair<int, int>, 4> _enemyPos;
            std::vector<std::shared_ptr<arcade::IObject>> _objs;
    };
}

#endif /* !ENEMIES_HPP_ */
