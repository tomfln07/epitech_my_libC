/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** displays the number given as a parameter.
*/

#include <stdio.h>
#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = - nb;
        my_putchar('-');
    }
    if (nb < 10) {
        nb = nb + 48;
        my_putchar(nb);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}
