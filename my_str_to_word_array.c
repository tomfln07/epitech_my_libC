/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** Splits a string into words
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static int is_separator(char c)
{
    if (48 <= c && c <= 57
        || 65 <= c && c <= 90
        || 97 <= c && c <= 122) {
        return 0;
    } else {
        return 1;
    }
}

static int append_array(
    char **arr,
    char const *str,
    int str_len,
    int separator_i)
{
    int to_append_len = 0;
    char *new_str;

    if (str[separator_i] == NULL)
        return 1;
    for (int i = separator_i; is_separator(str[i]) == 0; i++)
        to_append_len++;
    new_str = malloc(to_append_len + 1);
    if (new_str == NULL)
        return 1;
    for (int i = 0; i < to_append_len; i++)
        new_str[i] = str[separator_i + i];
    new_str[separator_i + to_append_len] = '\0';
    if (my_strlen(new_str) == 0) {
        free(new_str);
        return 1;
    }
    arr[str_len] = new_str;
    return 0;
}

static char **create_arr(char const *str, int str_len)
{
    char **arr;
    int arr_len = 0;

    for (int i = 0; i < str_len; i++) {
        if (is_separator(str[i]) && is_separator(str[i + 1]) == 0
            || i == 0 && is_separator(str[i]) == 0) {
            arr_len++;
        }
    }
    arr_len++;
    arr = malloc(8 * arr_len + 1);
    return arr;
}

static int increment_if_ok(int is_not_ok, int added_in_arr)
{
    if (is_not_ok != 1) {
        return added_in_arr + 1;
    }
    return added_in_arr;
}

char **my_str_to_word_array(char const *str)
{
    int str_len = my_strlen(str);
    int added_in_arr = 0;
    char **arr = create_arr(str, str_len);
    int is_not_ok = 0;

    if (arr == NULL) {
        return NULL;
    }
    for (int i = 0; i < str_len; i++) {
        if (i == 0 && is_separator(str[i]) == 0) {
            is_not_ok = append_array(arr, str, added_in_arr, i);
            added_in_arr = increment_if_ok(is_not_ok, added_in_arr);
        }
        if (is_separator(str[i]) && is_separator(str[i + 1]) == 0) {
            is_not_ok = append_array(arr, str, added_in_arr, i + 1);
            added_in_arr = increment_if_ok(is_not_ok, added_in_arr);
        }
    }
    arr[added_in_arr] = '\0';
    return arr;
}
