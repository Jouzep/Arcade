/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** bootstrap
*/

#include <dlfcn.h>

int main (int ac, char **av)
{
    void *handle;
    void (*test)(void);
    char *dico[] = {"foo.so", "bar.so", "gra.so"};


    handle = dlopen("./foo.so", RTLD_LAZY);
    if (!handle) {
        printf("Error = %s", dlerror());
        return 84;
    }
    *(void **) (&test) = dlsym(handle, "entrypoint");
    test();
    dlclose(handle);
    return 0;
}