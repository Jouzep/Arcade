/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** IGames
*/

#include "IGames.hpp"

namespace arcade {
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
            std::vector<std::shared_ptr<arcade::IObject>> _objs;
    };
}

arcade::MenuLib::MenuLib()
{
    // _background.setTexture("assets/gui/menu_bg.jpg");
    // _objs.push_back(std::make_shared<arcade::Sprite>(_background));
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
