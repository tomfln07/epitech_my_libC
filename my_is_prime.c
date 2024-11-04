/*
** EPITECH PROJECT, 2024
** my_is_prime.c
** File description:
** Write a function that returns 1 if the number is prime and 0 if not.
*/

#include "my.h"

int my_is_prime(int nb)
{
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
