/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** Puts every letter of every word in it in uppercase
*/

#include <stdio.h>
#include "my.h"

char *my_strupcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (97 <= str[i] && str[i] <= 122) {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
