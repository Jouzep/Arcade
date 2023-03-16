/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** DLLoadder
*/

#ifndef DLLOADDER_HPP_
    #define DLLOADDER_HPP_

template <typename T>
class DLLoadder {
    public:
        DLLoadder() {};
        ~DLLoadder() {};
        void setInstance(T* instance) {
            _instance = instance;
        }
        T *getInstance() {};

    protected:
    private:
        T _instance;
};

#endif /* !DLLOADDER_HPP_ */
