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

        // Not used
        void setRotation(float rotation) {};
        bool isClickable() {};
        void unableClick() {};
        void disableClick() {};
        std::pair<float, float> getOriginScale() {};
        std::pair<std::size_t, std::size_t> getOriginPosition() {};
        std::pair<float, float> setOriginScale(std::pair<float, float> scale) {};
        std::pair<std::size_t, std::size_t> setOriginPosition(std::pair<std::size_t, std::size_t> position) {};
        void setEvent(arcade::Input event) {};
        arcade::Input getEvent() const {};
        std::pair<float, float> getScale() const {};
        void setScale(std::pair<float, float> scale) {};
        void setSize(std::pair<std::size_t, std::size_t> size) {};
        std::pair<std::size_t, std::size_t> getSize() const {};
    protected:
    private:
        std::string _text;
        arcade::Color _color;
        std::pair<std::size_t, std::size_t> _position;
    };
}

#endif /* !SNAKETEXT_HPP_ */
