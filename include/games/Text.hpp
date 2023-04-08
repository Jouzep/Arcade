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
            std::pair<float, float> getScale() const;
            void setScale(std::pair<float, float> scale);
            void setText(std::string text);
            void setColorText(arcade::Color);
            void setPosition(std::pair<std::size_t, std::size_t>);
            void setRotation(float rotation);
            bool isClickable();
            void enableClick();
            void disableClick();
            std::pair<float, float> getOriginScale();
            std::pair<std::size_t, std::size_t> getOriginPosition();
            void setOriginScale(std::pair<float, float> scale);
            void setOriginPosition(std::pair<std::size_t, std::size_t> position);
            void setEvent(arcade::Input event);
            arcade::Input getEvent() const;
        protected:
        private:
            arcade::Color _color = arcade::Color::WHITE;
            std::string _text;
            float _rotation = 0;
            std::pair<std::size_t, std::size_t> _position = std::make_pair(0, 0);
            std::pair<std::size_t, std::size_t> _originPosition = std::make_pair(0, 0);
            std::pair<float, float> _scale = std::make_pair(1, 1);
            std::pair<float, float> _originScale = std::make_pair(1, 1);
            arcade::Input _event = arcade::Input::UNDEFINED;
            bool _clickable = false;

    };
}

#endif /* !TEXT_HPP_ */
