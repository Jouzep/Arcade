/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeText
*/

#ifndef SNAKETEXT_HPP_
#define SNAKETEXT_HPP_

#include "IObject.hpp"

namespace arcade
{
    class SnakeText : public IText
    {
    public:
        SnakeText();
        ~SnakeText();

        // ----- GETTER -----
        std::string getText() const;
        arcade::Color getColorText() const;
        std::pair<std::size_t, std::size_t> getPosition() const;

        // ----- SETTER -----
        void setText(std::string text);
        void setColorText(arcade::Color color);
        void setPosition(std::pair<std::size_t, std::size_t> position);

    protected:
    private:
        std::string _text;
        arcade::Color _color;
        std::pair<std::size_t, std::size_t> _position;
    };
}

#endif /* !SNAKETEXT_HPP_ */
