/*
** EPITECH PROJECT, 2022
** strlowcase
** File description:
** d
*/

int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] <= 65 && str[i] >= 90) {
            str[i] += 32;
        }
    }
    return str;
}
