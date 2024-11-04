/*
** EPITECH PROJECT, 2024
** pointer_specifier.c
** File description:
** Print pointer
*/

#include "conversion_specifiers.h"
#include <stdlib.h>

char *print_pointer(
    const char *str, int str_i, va_list args_list, int *printed)
{
    void *ptr = va_arg(args_list, void *);
    long converted_ptr = (long)ptr;
    char *hexa = get_hexa(converted_ptr, 0);

    hexa[my_strlen(hexa)] = 'x';
    hexa[my_strlen(hexa)] = '0';
    my_revstr(hexa);
    return hexa;
}
