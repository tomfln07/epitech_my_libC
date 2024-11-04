/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** Reproduce the behavior of the strcmp function
*/

#include <string.h>
#include <stdio.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int ascii_sum_s1 = 0;
    int ascii_sum_s2 = 0;
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);

    for (int i = 0; i < len_s1; i++) {
        ascii_sum_s1 += s1[i];
    }
    for (int i = 0; i < len_s2; i++) {
        ascii_sum_s2 += s2[i];
    }
    return ascii_sum_s1 - ascii_sum_s2;
}
