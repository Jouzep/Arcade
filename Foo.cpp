/*
** EPITECH PROJECT, 2023
** Foo
** File description:
** Foo
*/

#include <iostream>
#include "IDisplayModule.hpp"

extern "C" void constructor () {
    std::cout << "constructor" << std::endl;
}
extern "C" void destructor () {
    std::cout << "destructor" << std::endl;
}

// extern "C" void init () {
//     std::cout << "init" << std::endl;
// }

// extern "C" void stop () {
//     std::cout << "stop" << std::endl;
// }

// extern "C" const std::string &getName () {
//     return "test";
// }

class Foo : public IDisplayModule {
    public:
        Foo() {
            constructor();
        }
        ~Foo() {
            destructor();
        }

        void init() {
            std::cout << "init" << std::endl;
        };
        void stop() {
            std::cout << "stop" << std::endl;
        };
        const std :: string &getName () const {
            return "ok";
        };
    protected:
    private:
};

extern "C" Foo *entryPoint() {
    return new (Foo);
}
