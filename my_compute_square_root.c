/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** Returns the square root (if it is a whole number) of the number
** given as argument
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    for (int i = 1; i <= nb; i++) {
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}
