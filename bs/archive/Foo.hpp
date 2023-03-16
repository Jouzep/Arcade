/*
** EPITECH PROJECT, 2023
** bs
** File description:
** Foo
*/

#ifndef FOO_HPP_
#define FOO_HPP_

extern "C" void init() {
    std::cout << "Coucou" << std::endl;
}

extern "C" void unload() {
    std::cout << "Coucou" << std::endl;
}


class Foo {
    public:
        Foo()
        { 
            init(); 
        };
        ~Foo()
        {
            unload();
        };
        void entryPoint()
        {
            std::cout << "COCOC" << std::endl;
        };

    protected:
    private:
};

#endif /* !FOO_HPP_ */
