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
    #include <random>

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
            void setLimits(int x, int y);
            void pushEnemies();
            bool isPlayerTouched(int x, int y);
            void restart();
            std::vector<std::shared_ptr<arcade::IObject>> getEnemies();
        protected:
        private:
            void moveEnemies();
            void moveProjectiles();
            void enemyShoot();
            void createProjectile(DIRECTION direction, std::pair<int, int> pos);
            std::mt19937 _gen;
            size_t TOTAL_ENEMY = 4;
            std::pair<int, int> _borderLimit;
            std::array<DIRECTION, 4> _enemyDirection = {DIRECTION::RIGHT, DIRECTION::DOWN, DIRECTION::LEFT, DIRECTION::UP};
            std::array<std::pair<int, int>, 4> _enemyPos;
            std::vector<DIRECTION> _projectilesDirection;
            std::vector<arcade::Tile> _projectiles;
            std::vector<std::shared_ptr<arcade::IObject>> _objs;
    };
}

#endif /* !ENEMIES_HPP_ */
