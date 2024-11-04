/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** Copies n characters from a string into another
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    if (my_strlen(src) < n) {
        dest[n + 1] = '\0';
    }
    return dest;
}
