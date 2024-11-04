/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** Reproduce the behavior of the strstr function
*/

#include <stdio.h>
#include "my.h"

static int is_occurence_valid(char *str, char const *to_find, int i)
{
    for (int j = 0; j < my_strlen(to_find); j++) {
        if (str[i + j] != to_find[j]) {
            return 0;
        }
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == to_find[0] && is_occurence_valid(str, to_find, i)) {
            return str[i];
        }
    }
    return NULL;
}
