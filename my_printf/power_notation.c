/*
** EPITECH PROJECT, 2024
** power_notation.c
** File description:
** power_notation
*/

#include "my.h"

static int power(int number, int it)
{
    int result = 1;

    while (it != 0) {
        result *= number;
        it--;
    }
    return result;
}

static void print_unit_number(long double unit_number)
{
    long long int whole_part = (long long int)unit_number;

    my_put_nbr(whole_part);
    my_putchar('.');
}

static void print_deci(long double rest)
{
    long long int temp = 0;

    for (int j = 0; j < 6; j++) {
        rest *= 10;
        temp = (long long int)rest;
        my_put_nbr(temp);
        rest -= temp;
    }
}

static void print_sign(int i, char sign)
{
    my_putchar('e');
    my_putchar(sign);
    if (i < 10) {
        my_putchar('0');
    }
    my_put_nbr(i);
}

static int is_null(long double number)
{
    if (number == 0) {
        my_putchar('0');
        my_putchar('.');
        for (int i = 0; i < 6; i++) {
            my_putchar('0');
        }
        my_putchar('e');
        my_putchar('+');
        my_putchar('0');
        my_putchar('0');
        return 1;
    }
    return 0;
}

static int is_neg(long double *number)
{
    if (*number < 0) {
        my_putchar('-');
        *number = -(*number);
        return 1;
    }
    return 0;
}

void positive(long double unit_number, int *i)
{
    while (unit_number >= 10) {
            unit_number /= 10;
            i++;
        }
    unit_number += 0.000004;
    my_put_nbr((int)unit_number);
    my_putchar('.');
    print_deci(unit_number - (int)unit_number);
    print_sign(*i, '+');
}

void zero(long double unit_number, int *i)
{
    unit_number + 0.0000004;
    while ((int)unit_number == 0) {
        i++;
        unit_number *= 10;
    }
    my_put_nbr((int)unit_number);
    my_putchar('.');
    print_deci(unit_number - (int)unit_number);
    print_sign(*i, '-');
}

void power_notation(long double number)
{
    long double unit_number;
    int i = 0;

    if (is_null(number))
        return;
    if (is_neg(&number));
    unit_number = number;
    if ((int)unit_number == 0) {
        zero(unit_number, &i);
    } else {
        positive(unit_number, &i);
    }
}
