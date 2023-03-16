/*
** EPITECH PROJECT, 2023
** bs
** File description:
** barlib
*/

#include <stdio.h>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    printf("Loading bar library...\n");
}

void calledLast()
{
    printf("bar closing...\n");
}

void entryPoint()
{
    printf("Entry point for bar\n");
}