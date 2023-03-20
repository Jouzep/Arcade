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
        std::string getText();
        arcade::Color getColorText();
        std::pair<float, float> getPosition();

        // ----- SETTER -----
        void setText(std::string text);
        void setColorText(arcade::Color color);
        void setPosition(std::pair<float, float> position);

    protected:
    private:
        std::string _text;
        arcade::Color _color;
        std::pair<float, float> _position;
    };
}

#endif /* !SNAKETEXT_HPP_ */
