/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** bar
*/

#include "test.hpp"

// void __attribute__((constructor)) constructor();
// void __attribute__((destructor)) destructor();

// void entrypoint()
// {
    // printf("[libbar] Entry point for bar!\n");
// }

class Bar : public IDisplayModule
{
    public:
    Bar() {
        this->_name = "Bar";
        std::cout << "[libar] Loading bar library..." << std::endl;
    };
    ~Bar() {
        std::cout << "[libbar] bar closing..." << std::endl;
    };
    void init() {
        std::cout << "[libbar] bar init..." << std::endl;
    };
    void stop() {
        std::cout << "[libbar] bar stop..." << std::endl;
    };
    const std::string &getName() const {
        return this->_name;
    };
    private:
        std::string _name;
};

extern "C" IDisplayModule *entry_point()
{
    return new (Bar);
}