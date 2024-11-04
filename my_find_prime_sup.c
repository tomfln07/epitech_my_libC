/*
** EPITECH PROJECT, 2024
** my_find_prime_sup.c
** File description:
** eturns the smallest prime number that is greater than,
** or equal to, the number given as a parameter
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int greater_g = -1;
    int j = nb;

    while (greater_g == -1) {
        if (my_is_prime(j)) {
            greater_g = j;
        } else {
            j++;
        }
    }
    return greater_g;
}
