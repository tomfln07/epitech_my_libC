/*
** EPITECH PROJECT, 2024
** my_isneg.c
** File description:
** displays either N if the integer passed as parameter is negative or P,
** if positive or null.
*/

#include "my.h"

int my_isneg(int n)
{
    if (n) {
        if (n < 0) {
            my_putchar('N');
        } else {
            my_putchar('P');
        }
    } else {
        my_putchar('P');
    }
    return 0;
}
