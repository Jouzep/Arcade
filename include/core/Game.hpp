/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_
    #include "IGraphics.hpp"

namespace arcade {
    class Game {
        public:
            Game();
            ~Game();

            void runGame(IGraphics *lib);

        protected:
        private:
    };
}

#endif /* !GAME_HPP_ */
