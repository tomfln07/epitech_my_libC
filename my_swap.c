/*
** EPITECH PROJECT, 2024
** my_swap.c
** File description:
** waps the content of two integers, whose addresses are given
** as a parameter.
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}
