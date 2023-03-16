/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** main
*/

#include "test.hpp"
#include <dlfcn.h>

int main(int ac, char **av)
{
    void *handle;

    handle = dlopen("./bar.so", RTLD_LAZY);
    if (!handle)
    {
        printf("Error = %s", dlerror());
        return 84;
    }
    void *(*func)() = (void *(*)())dlsym(handle, "entry_point");
    if (func)
    {
        IDisplayModule *test = static_cast<IDisplayModule *>(func());
        test->init();
        test->stop();
        delete (test);
    }
    dlclose(handle);
    return 0;
}