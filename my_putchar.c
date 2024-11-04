/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** Prints a char in the terminal
*/

#include "my.h"
#include "unistd.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
