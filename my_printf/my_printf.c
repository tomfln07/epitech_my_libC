/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** Print all the characters in the string
** format and print variable when % is used before
*/

#include <stdio.h>
#include <stdarg.h>
#include "conversion_specifiers.h"
#include "flags.h"

const conversion_specifier_t specifiers_list[] = {
    { '%', print_percent },
    { 'i', print_int },
    { 'd', print_int },
    { 's', print_str },
    { 'c', print_char },
    { 'X', print_hex_height },
    { 'x', print_hex_min },
    { 'u', print_unsigned_int },
    { 'o', print_octal },
    { 'f', print_float },
    { 'F', print_float },
    { 'p', print_pointer },
    { 'e', print_scientific_notation }
};

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int get_min_field_width(const char *str, int str_i, int *i_offset)
{
    int str_len = my_strlen(str);
    int width = -1;
    int i = 1;

    if (!is_digit(str[str_i]) || str[str_i + *i_offset] == '%') {
        return width;
    }
    width = str[str_i] - 48;
    while (is_digit(str[str_i + i])) {
        width = width * 10 + (str[str_i + i] - 48);
        i++;
    }
    *i_offset += i;
    return width;
}

int get_precision(const char *str, int str_i, int *i_offset)
{
    int i = 2;
    int precision = -1;

    if (str[str_i] != '.')
        return -1;
    if (!is_digit(str[str_i + 1])) {
        *i_offset += 1;
        return 0;
    }
    precision = str[str_i + 1] - 48;
    while (is_digit(str[str_i + i])) {
        precision = precision * 10 + (str[str_i + i] - 48);
        i++;
    }
    *i_offset += i;
    return precision;
}

static int print_flag(
    const char *str, int str_i, va_list args_list, int *printed)
{
    args_t args;
    int i_offset = 1;
    char *str_to_serialize = NULL;

    if (my_strlen(str) <= str_i + i_offset)
        return 0;
    args.flags = get_flags((char *)(str + str_i), &i_offset);
    args.min_width = get_min_field_width(str, str_i + i_offset, &i_offset);
    args.precision = get_precision(str, str_i + i_offset, &i_offset);
    for (int i = 0; i < NBR_SPECIFIERS; i++) {
        if (specifiers_list[i].specifier == str[str_i + i_offset]) {
            str_to_serialize = specifiers_list[i].printer(
                str, str_i + i_offset, args_list, printed);
            formalize(args, str[str_i + i_offset], str_to_serialize, printed);
            break;
        }
    }
    return i_offset;
}

int my_printf(const char *restrict format, ...)
{
    int printed = 0;
    int str_len = my_strlen(format);
    va_list args_list;

    va_start(args_list, format);
    for (int i = 0; i < str_len; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            printed++;
        } else {
            i += print_flag(format, i, args_list, &printed);
        }
    }
    return printed - 1;
}
