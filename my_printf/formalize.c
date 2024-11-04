/*
** EPITECH PROJECT, 2024
** serialize.c
** File description:
** Formalize char * buffer to printf
*/

#include <stdlib.h>
#include "flags.h"
#include "my.h"
#include "formalize.h"

int is_in_char_list(char type, char *valid_types)
{
    int size = my_strlen(valid_types);

    for (int i = 0; i < size; i++) {
        if (type == valid_types[i]) {
            return 1;
        }
    }
    return 0;
}

static void hashtag(args_t args, char type, char *buff)
{
    int size = my_strlen(buff);

    if (type == 'X') {
        buff[size] = 'X';
        buff[size + 1] = '0';
        buff[size + 2] = '\0';
    }
    if (type == 'x') {
        buff[size] = 'x';
        buff[size + 1] = '0';
        buff[size + 2] = '\0';
    }
    if (type == 'o') {
        buff[size] = '0';
        buff[size + 1] = '\0';
    }
}

static void plus(args_t args, char type, char *buff)
{
    char valid_types[] = "dieEfFgGaA";
    int size = my_strlen(buff);

    if (is_in_char_list(type, valid_types) && buff[size - 1] != '-') {
        buff[size] = '+';
        buff[size + 1] = '\0';
    }
}

static void space(char *buff, char type)
{
    char valid_types[] = "dieEfFgGaA";
    int size = my_strlen(buff);

    if (is_in_char_list(type, valid_types) && buff[size - 1] != '-') {
        buff[size] = ' ';
        buff[size + 1] = '\0';
    }
}

static void apply_flags(args_t args, int type, char *buff)
{
    int size = my_strlen(buff);

    if (args.flags.hashtag) {
        hashtag(args, type, buff);
    }
    if (args.flags.plus) {
        plus(args, type, buff);
    }
    if (args.flags.space) {
        space(buff, type);
    }
}

static void fill_buff(char *buff, int min_width, int *i, flags_t flags)
{
    int size = my_strlen(buff);

    while (size + *i < min_width) {
        if (flags.zero && !flags.minus) {
            buff[size + *i] = '0';
        } else {
            buff[size + *i] = ' ';
        }
        (*i)++;
    }
}

static void apply_width(char *buff, char type, int min_width, flags_t flags)
{
    int size = my_strlen(buff);
    int i = 0;

    if (size < min_width) {
        if (flags.minus) {
            my_revstr(buff);
        }
        fill_buff(buff, min_width, &i, flags);
        buff[size + i + 1] = '\0';
        if (flags.minus) {
            my_revstr(buff);
        }
    }
}

void formalize(args_t args, char type, char *buff, int *printed)
{
    my_revstr(buff);
    apply_precision(buff, type, args.precision);
    apply_flags(args, type, buff);
    apply_width(buff, type, args.min_width, args.flags);
    my_revstr(buff);
    my_putstr(buff);
    *printed += my_strlen(buff);
    free(buff);
}
