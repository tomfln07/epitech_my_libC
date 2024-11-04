/*
** EPITECH PROJECT, 2024
** flags_fn.h
** File description:
** Function prototypes for printing different
** types of vars
*/

#ifndef FLAGS_FN_H
    #define FLAGS_FN_H
    #define NBR_SPECIFIERS 11
    #include <stdarg.h>
    #include "my.h"

char *print_percent(
    const char *str, int str_i, va_list args_list, int *printed);
char *print_int(const char *str, int str_i, va_list args_list, int *printed);
char *print_str(const char *str, int str_i, va_list args_list, int *printed);
char *print_char(const char *str, int str_i, va_list args_list, int *printed);
char *print_octal(
    const char *str, int str_i, va_list args_list, int *printed);
char *print_hex_height(
    const char *str, int str_i, va_list args_list, int *printed);
char *print_hex_min(
    const char *str, int str_i, va_list args_list, int *printed);
char *print_float(const char *str, int str_i, va_list args_list, int *printed);
char *print_unsigned_int(
    const char *str,
    int str_i,
    va_list args_list,
    int *printed);
char *print_pointer(
    const char *str, int str_i, va_list args_list, int *printed);
char *print_scientific_notation(
    const char *str, int str_i, va_list args_list, int *printed);
char *get_hexa(long base_value, int is_maj);
char *octa(unsigned int nb, int base);
int my_put_unsigned_nbr(unsigned int nb);
void power_notation(long double number);
struct conversion_specifier {
    char specifier;
    char *(*printer)(
        const char *str,
        int str_i,
        va_list args_list,
        int *printed);
};
typedef struct conversion_specifier conversion_specifier_t;
#endif
