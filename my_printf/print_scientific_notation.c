/*
** EPITECH PROJECT, 2024
** print_scientific_notation.c
** File description:
** e & E flags
*/

#include <stdlib.h>
#include "conversion_specifiers.h"
#include "my.h"

char *print_scientific_notation(
    const char *str, int str_i, va_list args_list, int *printed)
{
    double nbr = va_arg(args_list, double);
    char *buff = malloc(1);
    long long test = 74851.1651;

    buff[0] = '\0';
    power_notation(test);
    return buff;
}
