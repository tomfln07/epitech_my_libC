/*
** EPITECH PROJECT, 2024
** formalize_precision.c
** File description:
** Formalize the [precision] part of printf
*/

#include <stdio.h>
#include "my.h"
#include "formalize.h"

static void add_zeros_precision(int *i, char *buff, int precision)
{
    int nbr_int = 0;
    int nbr_decimal = 0;

    nbr_decimal = my_strlen(buff) - (*i + 1);
    nbr_int = my_strlen(buff) - nbr_decimal;
    *i = 0;
    while (*i < precision) {
        buff[nbr_int + nbr_decimal + *i] = '0';
        (*i)++;
    }
    buff[nbr_int + *i] = '\0';
    my_revstr(buff);
}

static void dbl_precision(int precision, char *buff)
{
    int i = 0;

    my_revstr(buff);
    while (buff[i] != '.') {
        i++;
    }
    if (precision == 0)
        buff[i] = '\0';
    if (my_strlen(buff) - i > precision) {
        buff[i + precision + 1] = '\0';
        my_revstr(buff);
    } else {
        add_zeros_precision(&i, buff, precision);
    }
}

static void int_precision(int precision, char *buff, int *i, int size)
{
    while (precision - size != *i) {
        buff[size + *i] = '0';
        buff[size + *i + 1] = '\0';
        (*i)++;
    }
}

void apply_precision(char *buff, char type, int precision)
{
    int i = 0;
    int nbr_decimals = 0;
    int size = my_strlen(buff);
    char precision_categ_1[] = "diouUxX";
    char precision_categ_2[] = "eEfFaA";

    if (precision == -1)
        return;
    if (type == 's' && size > precision) {
        my_revstr(buff);
        buff[precision] = '\0';
        my_revstr(buff);
    }
    if (is_in_char_list(type, precision_categ_1) && precision > size)
        int_precision(precision, buff, &i, size);
    if (is_in_char_list(type, precision_categ_2))
        dbl_precision(precision, buff);
}
