/*
** EPITECH PROJECT, 2024
** flags.h
** File description:
** Fn prototypes for applying flags
*/

#include "flags.h"
#include "my.h"
#include "conversion_specifiers.h"
#include <stdio.h>

void get_flags(char *str, int *i_offset, args_t *args)
{
    int str_len = my_strlen(str);

    for (int i = 1; i < str_len; i++) {
        if (str[i] != '#' && str[i] != '0'
            && str[i] != '-' && str[i] != ' ' && str[i] != '+')
            break;
        *i_offset += 1;
        if (str[i] == '#')
            args->flags.hashtag = 1;
        if (str[i] == '0')
            args->flags.zero = 1;
        if (str[i] == '-')
            args->flags.minus = 1;
        if (str[i] == ' ')
            args->flags.space = 1;
        if (str[i] == '+')
            args->flags.plus = 1;
    }
}
