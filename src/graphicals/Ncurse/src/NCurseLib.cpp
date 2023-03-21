/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Test
*/

#include "IGraphics.hpp"
#include <iostream>

namespace arcade {
    class NCurseLib : public IGraphics {
        public:
            NCurseLib();
            ~NCurseLib();

            void display();
            void clear();
            void draw(std::shared_ptr<arcade::IObject> object);
            arcade::Input event(std::vector<std::shared_ptr<arcade::IObject>> objs);
        protected:
        private:
            
    };
}

arcade::NCurseLib::NCurseLib()
{

}

arcade::NCurseLib::~NCurseLib()
{

}

void arcade::NCurseLib::display()
{
    std::cout << "display" << std::endl;
}

void arcade::NCurseLib::clear()
{
    std::cout << "clear" << std::endl;
}

void arcade::NCurseLib::draw(std::shared_ptr<arcade::IObject> object)
{
    std::cout << "draw" << std::endl;
}

arcade::Input arcade::NCurseLib::event(std::vector<std::shared_ptr<arcade::IObject>> objs)
{
    std::cout << "event" << std::endl;
    return arcade::Input::UNDEFINED;
}

extern "C" arcade::NCurseLib *entryPoint() {
    return new (arcade::NCurseLib);
}