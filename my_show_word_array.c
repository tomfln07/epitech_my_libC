/*
** EPITECH PROJECT, 2024
** my_show_word_array.c.c
** File description:
** Displays the content of an array of words
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    int i = 0;

    while (tab[i] != '\0') {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
