/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** convert str to int
*/

#include "my.h"

int pow_10(int pow)
{
    int r = 1;

    for (int i = 0; i < pow; i++) {
        r *= 10;
    }
    return r;
}

int int_at(int i, char *str)
{
    char c = str[i];

    return c - '0';
}

int convert_str_to_int(char *str, int size, int is_neg)
{
    int res = 0;

    if (size > 10) {
        return 0;
    }
    for (int i = 0; i < size; i++) {
        res += pow_10(size - i - 1) * int_at(i, str);
    }
    if (is_neg) {
        res *= (-1);
    }
    if (res > 2147483647 || res < -2147483648) {
        return 0;
    }
    return res;
}

int my_getnbr(char const *str)
{
    int i1 = 0;
    int i2;
    int is_neg = 0;
    int j = 0;
    char numStr[my_strlen(str)];

    while (str[i1] < 48 || str[i1] > 57)
        i1++;
    i2 = i1 + 1;
    while (str[i2] >= 48 && str[i2] <= 57)
        i2++;
    if (i1 != 0 && str[i1 - 1] == '-')
        is_neg = 1;
    for (int i = i1; i < i2; i++) {
        numStr[j] = str[i];
        j++;
    }
    return convert_str_to_int(numStr, j, is_neg);
}
