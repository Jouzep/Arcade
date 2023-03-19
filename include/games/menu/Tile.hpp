/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Tile
*/

#ifndef TILE_HPP_
    #define TILE_HPP_
    #include "IObject.hpp"

namespace arcade {
    class Tile : virtual public ITile {
        public:
            Tile();
            ~Tile();
            std::string getTexture();
            std::pair<float, float> getPosition();
            char getCharacter();
            arcade::Color getColor();
            std::pair<float, float> getScale();
            float getRotation();
            void setTexture(std::string path);
            void setPosition(std::pair<float, float> position);
            void setCharacter(char c);
            void setColor(arcade::Color color);
            void setScale(std::pair<float, float> scale);
            void setRotation(float rotation);
        protected:
        private:
            std::pair<float, float> _scale = std::make_pair(1, 1);
            std::string _texture;
            std::pair<float, float> _position = std::make_pair(0, 0);
    };
}

#endif /* !TILE_HPP_ */
