/*
** EPITECH PROJECT, 2023
** Arcade-Architecture
** File description:
** IGames
*/

#ifndef IGAMES_HPP
    #define IGAMES_HPP
    #include <memory>
    #include "IObject.hpp"

namespace arcade {
     /**
     * @brief Enumerate the possible actions in the arcarde box
     * 
     */
    enum Input {LEFT, RIGHT, UP, DOWN, ACTION1, NEXTGRAPH, NEXTGAME, PREVIOUSGRAPH, PREVIOUSGAME, RESTART, MENU, EXIT};
    class IGames {
        public:
            virtual ~IGames() = default;

            /**
             * @brief Loop the game
             *
             * @return std::vector<std::shared_ptr<IObject>> to be draw in the current graphical display
             */
            virtual std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input) = 0;

            /**
             * @brief Restart the entire game or the current loaded game
             *
             * @return void
             */
            virtual void restart() = 0;

            /**
            * @brief Create a squared object to display
            *
            * @return std::shared_ptr<arcade::ITile> a pointer to the tile object
            */
            virtual std::shared_ptr<arcade::ITile> createTile() = 0;

            /**
            * @brief Create a sound object to display
            *
            * @return std::shared_ptr<arcade::ISound>  a pointer to the sound object
            */
            virtual std::shared_ptr<arcade::ISound> createSound() = 0;

            /**
            * @brief Create a text object to display
            *
            * @return std::shared_ptr<arcade::IText>  a pointer to the text object
            */
            virtual std::shared_ptr<arcade::IText> createText() = 0;
    };
}

#endif
