/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** counts and returns the number of characters found in the string
** passed as parameter.
*/

#include "my.h"

int my_strlen(char const *str)
{
    int size = 0;

    while (str[size] != '\0') {
        size++;
    }
    return size;
}
