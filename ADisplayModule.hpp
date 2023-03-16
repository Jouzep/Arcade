/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** ADisplayModule
*/

#ifndef ADISPLAYMODULE_HPP_
    #define ADISPLAYMODULE_HPP_
    #include "IDisplayModule.hpp"
    #include <iostream>

extern "C" void init () {
    std::cout << "init" << std::endl;
}

extern "C" void stop () {
    std::cout << "stop" << std::endl;
}

class ADisplayModule : public IDisplayModule {
    public:
        ADisplayModule() {};
        ~ADisplayModule() {};
        void init ();
        void stop ();
        const std :: string &getName () const {
            return "ok";
        };

    protected:
    private:
};

#endif /* !ADISPLAYMODULE_HPP_ */
