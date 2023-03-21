/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeBody
*/

#ifndef SNAKEBODY_HPP_
#define SNAKEBODY_HPP_

#include <string>
#include <iostream>
#include <vector>

namespace arcade
{
    class SnakeBody
    {
    public:
        SnakeBody(std::pair<std::size_t, std::size_t> map);
        ~SnakeBody();

        // ******* GETTER *******
        std::vector<std::pair<std::size_t, std::size_t>> getSnakeBody() const;
        std::pair<std::size_t, std::size_t> getMove() const;

        // ******* SETTER *******
        void setSnakeBody();
        void setMove(std::pair<std::size_t, std::size_t>);

        // ******* Move Snake *******
        bool moveSnakeBody(std::pair<std::size_t, std::size_t> food);

    protected:
    private:
        std::vector<std::pair<std::size_t, std::size_t>> _snake;
        std::pair<std::size_t, std::size_t> _move;
        std::pair<std::size_t, std::size_t> _map;
    };
}
#endif /* !SNAKEBODY_HPP_ */
