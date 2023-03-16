/*
** EPITECH PROJECT, 2023
** bs
** File description:
** gralib
*/

#include <stdio.h>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    printf("Loading gra library...\n");
}

void calledLast()
{
    printf("Gra 's getting out...\n");
}

void entryPoint()
{
    printf("Another entry point!\n");
}