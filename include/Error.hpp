/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <iostream>
#include <exception>

class Error : public std::exception
{
public:
    Error(const std::string &message, const std::string &what);
    ~Error() noexcept {};
    const char *message() const noexcept;
    const char *what() const noexcept;

private:
    std::string _message;
    std::string _what;
};

#endif /* !ERROR_HPP_ */
