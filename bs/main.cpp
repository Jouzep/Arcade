/*
** EPITECH PROJECT, 2023
** bs
** File description:
** main
*/

#include <dlfcn.h>
#include <stdio.h>
#include <stdarg.h>
#include <iostream>

#include "IDisplayModule.hpp"
#include "DLLoader.hpp"

int main()
{
    std::string path = "./FooLib.so";
    DLLoader<IDisplayModule> lib1(path);
    DLLoader<IDisplayModule> lib2(path);
    DLLoader<IDisplayModule> lib3(path);
    IDisplayModule *test = lib1.getInstance();
    // std::cout << test->getName() << std::endl;
    // void *handle;
    // // IDisplayModule (*entryPoint)();
    // handle = dlopen("./FooLib.so", RTLD_LAZY);
    // if (!handle)
    //     std::cout << "failed" << std::endl;
    // IDisplayModule *AS = nullptr;
    // void *(*entryPoint)() = (void *(*)())dlsym(handle, "entryPoint");

    // if (entryPoint)
    //     AS = static_cast<IDisplayModule *>(entryPoint());
    // std::cout << AS->getName() << std::endl;
    // delete (AS);
    // dlclose(handle);
    return 0;
}