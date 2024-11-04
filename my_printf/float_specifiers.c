/*
** EPITECH PROJECT, 2024
** float_specifiers.c
** File description:
** Functions for printing floats
*/

#include <stdlib.h>
#include "conversion_specifiers.h"

static double round_double(double nbr)
{
    double decimal_in_int = (nbr - (int)nbr) * my_compute_power_rec(10, 6);
    double rounded = 0;
    double int_in_decimal = 0;

    if (nbr >= 0)
        rounded = decimal_in_int + 0.4;
    else
        rounded = decimal_in_int - 0.4;
    int_in_decimal = rounded / my_compute_power_rec(10, 6) + (int)nbr;
    return int_in_decimal;
}

static void get_decimal(char *double_to_str, double nbr, int start_i)
{
    char decimals_str[255];
    int decimals_left = (int)((nbr - (int)nbr) * 1000000);
    int i = 0;

    while (i != 6) {
        decimals_str[i] = decimals_left % 10 + 48;
        decimals_left = (int)(decimals_left / 10);
        i++;
    }
    decimals_str[i] = '\0';
    my_revstr(decimals_str);
    my_strcpy(double_to_str + start_i, decimals_str);
}

static void get_int_part(char *double_to_str, double nbr, int *i, int int_left)
{
    while ((int)(nbr / my_compute_power_rec(10, *i)) > 0) {
        double_to_str[*i] = (int)int_left % 10 + 48;
        int_left = (int)(int_left / 10);
        (*i)++;
    }
}

void put_neg(char *double_to_str, int is_neg, int *i)
{
    if (is_neg) {
        double_to_str[*i] = '-';
        double_to_str[*i + 1] = '\0';
        (*i)++;
    } else {
        double_to_str[*i] = '\0';
    }
}

int detect_neg(double *nbr)
{
    int is_neg = 0;

    if (*nbr < 0) {
        is_neg = 1;
        *nbr = -(*nbr);
    }
    *nbr = round_double(*nbr);
    return is_neg;
}

static void put_infinity(
    const char *str, char *double_to_str, int str_i, double nbr)
{
    if (str[str_i] == 'f' || str[str_i] == 'e') {
        my_strcpy(double_to_str, "inf");
    } else if (str[str_i] == 'F' || str[str_i] == 'E') {
        my_strcpy(double_to_str, "INF");
    }
    if (nbr < 0) {
        my_revstr(double_to_str);
        double_to_str[3] = '-';
        double_to_str[4] = '\0';
        my_revstr(double_to_str);
    }
}

char *print_float(
    const char *str, int str_i, va_list args_list, int *printed)
{
    double nbr = va_arg(args_list, double);
    int i = 0;
    char *double_to_str = malloc(255);
    double int_left = 0;
    double decimals_left = 0;
    int is_neg = 0;

    is_neg = detect_neg(&nbr);
    if (nbr == INFINITY || nbr == - INFINITY) {
        put_infinity(str, double_to_str, str_i, nbr);
    } else {
        int_left = (int)nbr;
        decimals_left = nbr - (int)nbr;
        get_int_part(double_to_str, nbr, &i, int_left);
        put_neg(double_to_str, is_neg, &i);
        my_revstr(double_to_str);
        double_to_str[i] = '.';
        get_decimal(double_to_str, nbr, i + 1);
    }
    return double_to_str;
}
