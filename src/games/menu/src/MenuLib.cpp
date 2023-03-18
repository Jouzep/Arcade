/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** IGames
*/

#include "../../../../include/IGames.hpp"

namespace arcade {
    class Tile : virtual public ITile {
        public:
            Tile() {};
            ~Tile() {};
            std::string getTexture() {
                return _texture;
            }
            std::pair<float, float> getPosition() {};
            char getCharacter() {};
            arcade::Color getColor() {};
            std::pair<float, float> getScale() {};
            float getRotation() {};
            void setTexture(std::string path) {
                _texture = path;
            };
            void setPosition(std::pair<float, float> position) {};
            void setCharacter(char c) {};
            void setColor(arcade::Color color) {};
            void setScale(std::pair<float, float> position) {};
            void setRotation(float rotation) {};
        protected:
        private:
            std::string _texture;
    };

    class MenuLib : public IGames {
        public:
            MenuLib();
            ~MenuLib();

            void event();
            std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
            void restart();
            std::shared_ptr<arcade::ITile> createTile();
            std::shared_ptr<arcade::ISound> createSound();
            std::shared_ptr<arcade::IText> createText();
        protected:
        private:
            arcade::Tile _background;
            std::vector<std::shared_ptr<arcade::IObject>> _objs;
    };
}

arcade::MenuLib::MenuLib()
{
    _background.setTexture("assets/gui/menu_bg.jpg");
    _objs.push_back(std::make_shared<arcade::Tile>(_background));
}

arcade::MenuLib::~MenuLib()
{

}

void arcade::MenuLib::event()
{

}

std::vector<std::shared_ptr<arcade::IObject>> arcade::MenuLib::loop(arcade::Input input)
{
    return _objs;
}

void arcade::MenuLib::restart()
{

}

std::shared_ptr<arcade::ITile> arcade::MenuLib::createTile()
{

}

std::shared_ptr<arcade::ISound> arcade::MenuLib::createSound()
{

}

std::shared_ptr<arcade::IText> arcade::MenuLib::createText()
{

}


extern "C" arcade::MenuLib *entryPoint() {
    return new (arcade::MenuLib);
}
