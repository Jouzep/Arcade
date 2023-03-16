/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include "test.hpp"

template<typename T>

class DLLoader {
    public:
        DLLoader();
        ~DLLoader();
        void *setInstance(IDisplayModule *_fill)
        {
            this->test = _fill;
        };
        T *getInstance(void) const
        {
            return ;
        };

    protected:
    private:
        T *test;
};

#endif /* !DLLOADER_HPP_ */
