/*
** EPITECH PROJECT, 2023
** Arcade-Architecture
** File description:
** IObject
*/

#ifndef IOBJECT_HPP
#define IOBJECT_HPP
#include <iostream>
#include <vector>

namespace arcade
{
    /**
     * @brief Enumerate the possible actions in the arcarde box
     *
     */
    enum Input
    {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        ACTION1,
        NEXTGRAPH,
        NEXTGAME,
        PREVIOUSGRAPH,
        PREVIOUSGAME,
        RESTART,
        MENU,
        EXIT
    };

    /**
     * @brief Enumerate the possible colors in the arcarde box
     */
    enum Color
    {
        RED,
        BLUE,
        GREEN,
        DARK,
        YELLOW,
        WHITE
    };

    /**
     * @brief virtual class for all objects in the arcade box
     *
     */
    class IObject
    {
    public:
        virtual ~IObject() = default;
    };

    /**
     * @brief virtual class for all Tile in the arcade box
     *
     */
    class ITile : public IObject
    {
    public:
        virtual ~ITile() = default;

        /**
         * @brief Get the path for texture of the object for SFML & SDL Library
         *
         * @return std::string
         */
        virtual std::string getTexture() = 0;

        /**
         * @brief Get the Position x y of the object
         *
         * @return std::pair<float, float>
         */
        virtual std::pair<float, float> getPosition() = 0;

        /**
         * @brief Get the characters to display for the NCurses library
         *
         * @return char
         */
        virtual char getCharacter() = 0;

        /**
         * @brief Get the color of the object
         *
         * @return arcade::Color
         */
        virtual arcade::Color getColor() = 0;

        /**
         * @brief Get the scale of the object
         *
         * @return std::pair<float, float>
         */
        virtual std::pair<float, float> getScale() = 0;

        /**
         * @brief Get the rotation of the object
         *
         * @return float
         */
        virtual float getRotation() = 0;

        /**
         * @brief Set the path for texture of the object for SFML & SDL Library
         *
         * @params std::string
         *
         * @return void
         */
        virtual void setTexture(std::string path) = 0;

        /**
         * @brief Set the position of the object
         *
         * @params std::pair<float, float>
         *
         * @return void
         */
        virtual void setPosition(std::pair<float, float> position) = 0;

        /**
         * @brief Set the character of the object for NCurses library
         *
         * @params char
         *
         * @return void
         */
        virtual void setCharacter(char c) = 0;

        /**
         * @brief Set the color of the object
         *
         * @params arcade::Color
         *
         * @return void
         */
        virtual void setColor(arcade::Color color) = 0;

        /**
         * @brief Set the scale of the object
         *
         * @params std::pair<float, float>
         *
         * @return void
         */
        virtual void setScale(std::pair<float, float> position) = 0;

        /**
         * @brief Set the rotation of the object
         *
         * @params float
         *
         * @return void
         */
        virtual void setRotation(float rotation) = 0;
    };

    class IText : public IObject
    {
    public:
        virtual ~IText() = default;

        /**
         * @brief Get the text
         *
         * @return std::string
         */
        virtual std::string getText() = 0;

        /**
         * @brief Get the color of text
         *
         * @return arcade::Color
         */
        virtual arcade::Color getColorText() = 0;

        /**
         * @brief Get the position of text
         *
         * @return std::pair<float, float>
         */
        virtual std::pair<float, float> getPosition() = 0;

        /**
         * @brief Set the text
         *
         * @params std::string
         *
         * @return void
         */
        virtual void setText(std::string text) = 0;

        /**
         * @brief Set the color of the text
         *
         * @params arcade::Color
         *
         * @return void
         */
        virtual void setColorText(arcade::Color) = 0;

        /**
         * @brief Set the position of the text
         *
         * @params std::pair<float, float>
         *
         * @return void
         */
        virtual void setPosition(std::pair<float, float>) = 0;
    };

    class ISound : public IObject
    {
    public:
        virtual ~ISound() = default;

        /**
         * @brief Get the sound path
         *
         * @return std::string
         */
        virtual std::string getSoundPath() = 0;

        /**
         * @brief Get the volume of the sound
         *
         * @return float
         */
        virtual float getVolume() = 0;

        /**
         * @brief Set the sound path
         *
         * @params std::string
         *
         * @return void
         */
        virtual void setSoundPath(std::string path) = 0;

        /**
         * @brief Set the volume of the sound
         *
         * @params float
         *
         * @return void
         */
        virtual void setVolume(float volume) = 0;

        /**
         * @brief Pause the sound
         *
         *
         *
         * @return void
         */
        virtual void pauseSound() = 0;

        /**
         * @brief Start or resume the sound
         *
         *
         *
         * @return void
         */
        virtual void playSound() = 0;

        /**
         * @brief Stop the sound and reset it (unlike pauseSound())
         *
         *
         *
         * @return void
         */
        virtual void stopSound() = 0;
    };
}

#endif
