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

flags_t get_flags(char *str, int *i_offset)
{
    int str_len = my_strlen(str);
    flags_t flags = { 0 };

    for (int i = 1; i < str_len; i++) {
        if (str[i] != '#' && str[i] != '0'
            && str[i] != '-' && str[i] != ' ' && str[i] != '+')
            break;
        *i_offset += 1;
        if (str[i] == '#')
            flags.hashtag = 1;
        if (str[i] == '0')
            flags.zero = 1;
        if (str[i] == '-')
            flags.minus = 1;
        if (str[i] == ' ')
            flags.space = 1;
        if (str[i] == '+')
            flags.plus = 1;
    }
    return flags;
}
