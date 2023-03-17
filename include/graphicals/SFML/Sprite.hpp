/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
    #define SPRITE_HPP_
    #include "IObject.hpp"
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/Graphics/Texture.hpp>
    #include <string>

namespace arcade {
    class Sprite : public IObject {
        public:
            Sprite();
            Sprite(std::string filename);
            ~Sprite();

            // Getters
            sf::Texture getTexture();
            sf::Sprite getSprite();

            void setTexture(std::string filename);
        protected:
        private:
            sf::Sprite _sprite;
            sf::Texture _texture;

    };
}

#endif /* !SPRITE_HPP_ */
