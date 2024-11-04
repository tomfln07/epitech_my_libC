/*
** EPITECH PROJECT, 2024
** int_specifiers.c
** File description:
** Function for int-related specifiers
*/

#include <stdlib.h>
#include "conversion_specifiers.h"
#include "my.h"

static int get_nbr_len(int nb, int len)
{
    if (nb < 0) {
        nb = - nb;
        len++;
    }
    if (nb < 10) {
        return len;
    } else {
        return len + get_nbr_len(nb / 10, len + 1);
    }
}

static void serialize(char *str, int size, int is_neg)
{
    str[size] = '\0';
    while (size > 1 && str[size - 1] == '0') {
        str[size - 1] = '\0';
        size--;
    }
    if (is_neg) {
        str[size] = '-';
        str[size + 1] = '\0';
    }
    my_revstr(str);
}

char *print_int(
    const char *str, int str_i, va_list args_list, int *printed)
{
    int nbr = va_arg(args_list, int);
    char *nbr_to_str = malloc(11);
    int i = 0;
    int is_neg = 0;

    if (nbr_to_str == NULL)
        return NULL;
    if (nbr < 0) {
        is_neg = 1;
        nbr = -nbr;
    }
    while (i < 11) {
        nbr_to_str[i] = (nbr % 10) + 48;
        nbr /= 10;
        i++;
    }
    serialize(nbr_to_str, i, is_neg);
    return nbr_to_str;
}

char *print_unsigned_int(
    const char *str, int str_i, va_list args_list, int *printed)
{
    unsigned int nbr = va_arg(args_list, unsigned int);
    char *nbr_to_str = malloc(11);
    int i = 0;
    int is_neg = 0;

    if (nbr_to_str == NULL)
        return NULL;
    if (nbr < 0) {
        is_neg = 1;
        nbr = -nbr;
    }
    while (i < 11) {
        nbr_to_str[i] = (nbr % 10) + 48;
        nbr /= 10;
        i++;
    }
    serialize(nbr_to_str, i, is_neg);
    return nbr_to_str;
}

char *print_octal(
    const char *str, int str_i, va_list args_list, int *printed)
{
    return octa(va_arg(args_list, unsigned int), 8);
}

char *print_hex_height(
    const char *str, int str_i, va_list args_list, int *printed)
{
    char *hexa = get_hexa(va_arg(args_list, long), 1);

    my_revstr(hexa);
    return hexa;
}

char *print_hex_min(
    const char *str, int str_i, va_list args_list, int *printed)
{
    char *hexa = get_hexa(va_arg(args_list, long), 0);

    my_revstr(hexa);
    return hexa;
}
