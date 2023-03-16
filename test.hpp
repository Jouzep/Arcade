/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** test
*/

#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>

class IDisplayModule
{
public:
    virtual ~IDisplayModule() = default;
    virtual void init() = 0;
    virtual void stop() = 0;
    virtual const std::string &getName() const = 0;
};

#endif /* !TEST_HPP_ */
