/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include "IGraphics.hpp"

namespace arcade {
    class Core {
        public:
            Core();
            ~Core();

            void runCore(IGraphics *lib);

        protected:
        private:
    };
}

#endif /* !CORE_HPP_ */
