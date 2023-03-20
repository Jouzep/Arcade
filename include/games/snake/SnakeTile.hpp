/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SnakeTile
*/

#ifndef SNAKETILE_HPP_
#define SNAKETILE_HPP_

#include "IObject.hpp"

namespace arcade
{
    class SnakeTile : public ITile
    {
    public:
        SnakeTile();
        ~SnakeTile();

        // ----- GETTER -----
        std::string getTexture();
        std::pair<float, float> getPosition();
        char getCharacter();
        arcade::Color getColor();
        std::pair<float, float> getScale();
        float getRotation();

        // ----- SETTER -----
        void setTexture(std::string path);
        void setPosition(std::pair<float, float> position);
        void setCharacter(char c);
        void setColor(arcade::Color color);
        void setScale(std::pair<float, float> position);
        void setRotation(float rotation);

    private:
        std::pair<float, float> _position;
        char _char;
        std::string _texture;
        arcade::Color _color;
        std::pair<float, float> _scale;
        float _rotation;
        std::size_t _score;
    };
}

#endif /* !SNAKETILE_HPP_ */
