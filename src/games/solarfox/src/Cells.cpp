/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Cells
*/

#include "games/solarfox/Cells.hpp"

arcade::Cells::Cells()
{
}

arcade::Cells::~Cells()
{
}

void arcade::Cells::placeCell(int x, int y)
{
    arcade::Tile cell;

    if (!isDoneInit) {
        cell.setTexture("assets/sprite/solarfox/cell.png");
        cell.setOriginPosition(std::make_pair(x, y));
        _cellsPos.push_back(std::make_pair(x, y));
        _objs.push_back(std::make_shared<arcade::Tile>(cell));
    }
}

void arcade::Cells::validateInit()
{
    isDoneInit = true;
}

void arcade::Cells::resetInit()
{
    isDoneInit = false;
    _objs.clear();
    _cellsPos.clear();
}

void arcade::Cells::eatCell(int x, int y)
{
    for (int i = 0; i < _cellsPos.size(); i++) {
        if (x == _cellsPos[i].first && y == _cellsPos[i].second) {
            _cellsPos.erase(_cellsPos.begin() + i);
            _objs.erase(_objs.begin() + i);
            break;
        }
    }
}

std::vector<std::shared_ptr<arcade::IObject>> arcade::Cells::getCells()
{
    return _objs;
}
