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
            std::string getText() const;
            arcade::Color getColorText() const;
            std::pair<std::size_t, std::size_t> getPosition() const;
            void setText(std::string text);
            void setColorText(arcade::Color);
            void setPosition(std::pair<std::size_t, std::size_t>);
        protected:
        private:
            std::string _text;
            std::pair<std::size_t, std::size_t> _position = std::make_pair(0, 0);
    };
}

#endif /* !TEXT_HPP_ */
