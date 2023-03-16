/*
** EPITECH PROJECT, 2023
** bs
** File description:
** main
*/

#include <dlfcn.h>
#include <stdio.h>
#include <stdarg.h>

void main()
{
    void *handle_bar;
    void (*entrypoint_bar)();

    void *handle_foo;
    void (*entrypoint_foo)();

    void *handle_gra;
    void (*entrypoint_gra)();

    printf("[barlib] ");
    handle_bar = dlopen("./shared/barlib.so", RTLD_LAZY);
    printf("[foolib] ");
    handle_foo = dlopen("./shared/foolib.so", RTLD_LAZY);
    printf("[gralib] ");
    handle_gra = dlopen("./shared/gralib.so", RTLD_LAZY);
    if (!handle_bar || !handle_foo || !handle_gra) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }
    entrypoint_bar = dlsym(handle_bar, "entryPoint");
    entrypoint_foo = dlsym(handle_foo, "entryPoint");
    entrypoint_gra = dlsym(handle_gra, "entryPoint");

    printf("[barlib] ");
    entrypoint_bar();
    printf("[foolib] ");
    entrypoint_foo();
    printf("[gralib] ");
    entrypoint_gra();
    printf("[barlib] ");
    dlclose(handle_bar);
    printf("[foolib] ");
    dlclose(handle_foo);
    printf("[gralib] ");
    dlclose(handle_gra);
}