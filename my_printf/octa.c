/*
** EPITECH PROJECT, 2024
** octa.c
** File description:
** octa
*/

#include <stdio.h>
#include <stdlib.h>

static void rest_octal(unsigned int nb, int base, char *result, int *index)
{
    if (nb > 0) {
        rest_octal(nb / base, base, result, index);
        result[*index] = (nb % base) + '0';
        (*index)++;
    }
}

char *octa(unsigned int nb, int base)
{
    char *result = malloc(20);
    int index = 0;

    if (result == NULL)
        return NULL;
    if (nb == 0) {
        result[index] = '0';
        index++;
    } else {
        rest_octal(nb, base, result, &index);
    }
    result[index] = '\0';
    return result;
}
