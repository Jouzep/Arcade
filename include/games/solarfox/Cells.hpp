/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Cells
*/

#ifndef CELLS_HPP_
    #define CELLS_HPP_
    #include <vector>
    #include "IObject.hpp"
    #include "games/Tile.hpp"
    #include <memory>

namespace arcade {
    class Cells {
        public:
            Cells();
            ~Cells();

        void placeCell(int x, int y);
        void validateInit();
        void resetInit();

        void eatCell(int x, int y);
        std::vector<std::shared_ptr<arcade::IObject>> getCells();
        protected:
        private:
            bool isDoneInit = false;
            std::vector<std::pair<int, int>> _cellsPos;
            std::vector<std::shared_ptr<arcade::IObject>> _objs;

    };
}

#endif /* !CELLS_HPP_ */
