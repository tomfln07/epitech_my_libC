/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** Same behavior as my_strcmp but for the first n-bytes
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int ascii_sum_s1 = 0;
    int ascii_sum_s2 = 0;
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);

    for (int i = 0; i < s1_len; i++) {
        if (i + 1 > n) {
            break;
        }
        ascii_sum_s1 += s1[i];
    }
    for (int i = 0; i < s2_len; i++) {
        if (i + 1 > n) {
            break;
        }
        ascii_sum_s2 += s2[i];
    }
    return ascii_sum_s1 - ascii_sum_s2;
}
