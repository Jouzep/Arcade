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
            std::string getTexture() const;
            std::pair<std::size_t, std::size_t> getPosition() const;
            char getCharacter() const;
            arcade::Color getColor() const;
            std::pair<float, float> getScale() const;
            float getRotation() const;
            void setTexture(std::string path);
            void setPosition(std::pair<std::size_t, std::size_t> position);
            void setCharacter(char c);
            void setColor(arcade::Color color);
            void setScale(std::pair<float, float> scale);
            void setRotation(float rotation);
            // bool isClickable();
            // void enableClick();
            // void disableClick();
            std::pair<float, float> getOriginScale();
            std::pair<std::size_t, std::size_t> getOriginPosition();
            void setOriginScale(std::pair<float, float> scale);
            void setOriginPosition(std::pair<std::size_t, std::size_t> position);
            void setEvent(arcade::Input event);
            arcade::Input getEvent() const;
            void setSize(std::pair<std::size_t, std::size_t> size);
            std::pair<std::size_t, std::size_t> getSize() const;
            void setName(std::string name);
            std::string getName() const;
        protected:
        private:
            char _char;
            arcade::Color _color;
            float _rotation;
            std::pair<float, float> _scale = std::make_pair(1, 1);
            std::pair<float, float> _originScale = std::make_pair(1, 1);
            std::string _texture;
            std::pair<std::size_t, std::size_t> _position = std::make_pair(0, 0);
            std::pair<std::size_t, std::size_t> _originPosition = std::make_pair(0, 0);
            // bool _clickable = false;
            arcade::Input _event = arcade::Input::UNDEFINED;
            std::pair<std::size_t, std::size_t> _size;
            std::string _name;
    };
}

#endif /* !TILE_HPP_ */
