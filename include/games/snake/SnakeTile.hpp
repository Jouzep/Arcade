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
        std::string getTexture() const;
        std::pair<std::size_t, std::size_t> getPosition() const;
        char getCharacter() const;
        arcade::Color getColor() const;
        std::pair<float, float> getScale() const;
        float getRotation() const;

        // ----- SETTER -----
        void setTexture(std::string path);
        void setPosition(std::pair<std::size_t, std::size_t> position);
        void setCharacter(char c);
        void setColor(arcade::Color color);
        void setScale(std::pair<std::size_t, std::size_t> position);
        void setRotation(float rotation);

    private:
        std::pair<std::size_t, std::size_t> _position;
        char _char;
        std::string _texture;
        arcade::Color _color;
        std::pair<float, float> _scale;
        float _rotation;
        std::size_t _score;
    };
}

#endif /* !SNAKETILE_HPP_ */