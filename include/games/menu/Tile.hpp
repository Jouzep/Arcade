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
            bool isClickable();
            void unableClick();
            void disableClick();
            std::pair<float, float> getOriginScale();
            std::pair<float, float> getOriginPosition();
            std::pair<float, float> setOriginScale(std::pair<float, float> scale);
            std::pair<float, float> setOriginPosition(std::pair<float, float> position);
        protected:
        private:
            std::pair<float, float> _scale = std::make_pair(1, 1);
            std::pair<float, float> _originScale = std::make_pair(1, 1);
            std::string _texture;
            std::pair<float, float> _position = std::make_pair(0, 0);
            std::pair<float, float> _originPosition = std::make_pair(0, 0);
            bool _clickable = false;
    };
}

#endif /* !TILE_HPP_ */
