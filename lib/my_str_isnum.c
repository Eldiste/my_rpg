/*
** EPITECH PROJECT, 2022
** isnum
** File description:
** d
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 48 || str[i] > 57))
            return 0;
    }
    return 1;
}
