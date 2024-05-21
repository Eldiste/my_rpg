/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** displays one-by-one the characters of a string
*/

#include "../include/my.h"

void my_putstr(char const *str)
{
    while (*str)
        my_putchar(*str++);
}
