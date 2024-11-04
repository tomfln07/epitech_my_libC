/*
** EPITECH PROJECT, 2024
** my_compute_power_rec.c
** File description:
** returns the first argument raised to the power
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    long int power;

    if (p < 0) {
        return 0;
    } else if (p == 0) {
        return 1;
    }
    power = nb * my_compute_power_rec(nb, p - 1);
    return power;
}
