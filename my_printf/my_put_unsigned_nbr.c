/*
** EPITECH PROJECT, 2024
** my_put_unsigned_nbr.h
** File description:
** Prints unsinged int
*/

#include "my.h"
#include "conversion_specifiers.h"

int my_put_unsigned_nbr(unsigned int nb)
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
