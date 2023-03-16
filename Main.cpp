/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Main
*/

#include <dlfcn.h>
#include "IDisplayModule.hpp"
#include "DLLoadder.hpp"

int main(int argc, char **argv)
{
    DLLoadder<int> dl;
    void *handle;
    handle = dlopen("./lib.so", RTLD_LAZY);
    if (!handle) {
        // std::cout << "error" << std::endl;
        return 84;
    }
    IDisplayModule *lib_instance = nullptr;
    void *(*entryPoint)() = (void *(*)())dlsym(handle, "entryPoint");
    if (entryPoint) {
        lib_instance = static_cast<IDisplayModule*>(entryPoint());
        lib_instance->init();
    }
    dl.getInstance();
    delete(lib_instance);
    // (*entryPoint)();
    dlclose(handle);
    return 0;
}