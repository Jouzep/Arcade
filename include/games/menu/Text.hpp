/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Text
*/

#ifndef TEXT_HPP_
    #define TEXT_HPP_
    #include "IObject.hpp"

namespace arcade {
    class Text : public IText {
        public:
            Text();
            ~Text();
            std::string getText();
            arcade::Color getColorText();
            std::pair<float, float> getPosition();
            void setText(std::string text);
            void setColorText(arcade::Color);
            void setPosition(std::pair<float, float>);
        protected:
        private:
            std::string _text;
            std::pair<float, float> _position = std::make_pair(0, 0);
    };
}

#endif /* !TEXT_HPP_ */
