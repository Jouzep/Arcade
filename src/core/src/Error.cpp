/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Error
*/

#include "core/Error.hpp"

Error::Error(const std::string &message = "Unknow Error", const std::string &what = "Unknow") : _message(message), _what(what)
{
}

const char *Error::what() const noexcept
{
    return (this->_what.c_str());
}

const char *Error::message() const noexcept
{
    return (this->_message.c_str());
}