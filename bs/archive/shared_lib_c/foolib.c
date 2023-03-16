/*
** EPITECH PROJECT, 2023
** bs
** File description:
** foolib
*/

#include <stdio.h>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    printf("Loading foo library...\n");
}

void calledLast()
{
    printf("foo closing...\n");
}

void entryPoint()
{
    printf("Entry point for foo\n");
}