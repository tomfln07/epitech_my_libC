/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** Reverses a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char buff;

    for (int i = 0; i < len / 2; i++) {
        buff = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = buff;
    }
    str[len] = '\0';
    return str;
}
