/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeFood
*/

#ifndef SNAKEFOOD_HPP_
#define SNAKEFOOD_HPP_

#include <string>
#include <iostream>
#include <vector>

namespace arcade
{

    class SnakeFood
    {
    public:
        SnakeFood(std::pair<std::size_t, std::size_t> map);
        ~SnakeFood();

        // ******* SETTER *******
        void setRandomPosition(void);

        // ******* GETTER *******
        std::pair<std::size_t, std::size_t> getPosition() const;

    protected:
    private:
        std::pair<std::size_t, std::size_t> _position;
        std::pair<std::size_t, std::size_t> _map;
    };
}
#endif /* !SNAKEFOOD_HPP_ */
