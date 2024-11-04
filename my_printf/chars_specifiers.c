/*
** EPITECH PROJECT, 2024
** flags_fn.c
** File description:
** Functions for printing different
** types of vars
*/

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "conversion_specifiers.h"

char *print_percent(
    const char *str, int str_i, va_list args_list, int *printed)
{
    char *buff = malloc(255);

    if (buff == NULL)
        return NULL;
    if (str[str_i] == '%') {
        buff[0] = '%';
        buff[1] = '\0';
    }
    return buff;
}

char *print_str(const char *str, int str_i, va_list args_list, int *printed)
{
    char *word = NULL;

    word = va_arg(args_list, char *);
    return word;
}

char *print_char(const char *str, int str_i, va_list args_list, int *printed)
{
    char *word = malloc(2);

    word[0] = va_arg(args_list, int);
    word[1] = '\n';
    return word;
}
