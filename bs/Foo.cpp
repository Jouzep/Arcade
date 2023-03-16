/*
** EPITECH PROJECT, 2023
** bs
** File description:
** Foo
*/

#include "IDisplayModule.hpp"
#include <string>
#include <iostream>

class Foo : public IDisplayModule
{
public:
    Foo()
    {
        init();
        _name = "Foo";
    };
    ~Foo()
    {
        stop();
    };
    void stop()
    {
        std::cout << "Unload" << std::endl;
    };
    void init()
    {
        std::cout << "Init" << std::endl;
    };
    const std::string &getName() const
    {
        std::cout << "eee" << std::endl;
        return _name;
    }
    void test()
    {
        std::cout << "hello" << std::endl;
    }

protected:
private:
    std::string _name;
};

// static Foo foo_init;

extern "C" IDisplayModule *entryPoint()
{
    return new (Foo);
}