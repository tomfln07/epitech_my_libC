/*
** EPITECH PROJECT, 2024
** flags.h
** File description:
** Fn prototypes for applying flags
*/

#ifndef FLAGS_H
    #define FLAGS_H

struct flags {
    int hashtag;
    int minus;
    int plus;
    int space;
    int zero;
};
typedef struct flags flags_t;
struct args {
    flags_t flags;
    int min_width;
    int precision;
};
typedef struct args args_t;
flags_t get_flags(char *str, int *i_offset);
void formalize(args_t args, char type, char *buff, int *printed);
#endif
