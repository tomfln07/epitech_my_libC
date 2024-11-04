/*
** EPITECH PROJECT, 2024
** my_strlowcase.c
** File description:
** Puts every letter of every word in it in lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (65 <= str[i] && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
