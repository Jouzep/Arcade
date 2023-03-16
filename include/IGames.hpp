/*
** EPITECH PROJECT, 2023
** Arcade-Architecture
** File description:
** IGames
*/

#ifndef IGAMES_HPP
    #define IGAMES_HPP

namespace arcade {
    class IGames {
        virtual ~IGames() = default;

        /**
         * @brief Handle events from the current loaded game
         *
         * @return void
         */
        virtual void event() = 0;

        /**
         * @brief Loop the game
         *
         * @return void
         */
        virtual void loop() = 0;

        /**
         * @brief Restart the entire game or the current loaded game
         *
         * @return void
         */
        virtual void restart() = 0;
    };
}

#endif
