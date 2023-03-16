/*
** EPITECH PROJECT, 2023
** bs
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <string>

class IDisplayModule {
    public:
        ~IDisplayModule() = default;

        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;

    protected:
    private:
};

#endif /* !IDISPLAYMODULE_HPP_ */
