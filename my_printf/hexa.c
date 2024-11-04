/*
** EPITECH PROJECT, 2024
** hexa.c
** File description:
** menfou
*/

//#include "conversion_specifiers.h"
#include <stdlib.h>

static void add_hexa_to_str(char *str, int i, int hexa, int is_maj)
{
    if (hexa > 9) {
        if (is_maj)
            str[i] = hexa + 55;
        else
            str[i] = hexa + 87;
    } else {
        str[i] = hexa + 48;
    }
}

char *get_hexa(long base_value, int is_maj)
{
    char *hexa = malloc(255);
    long quotient = base_value;
    long rest = 0;
    int i = 0;
    int is_neg = 0;

    if (hexa == NULL)
        return NULL;
    while (quotient != 0) {
        rest = quotient % 16;
        quotient = (long)(quotient / 16);
        add_hexa_to_str(hexa, i, rest, is_maj);
        i++;
    }
    hexa[i] = '\0';
    return hexa;
}
