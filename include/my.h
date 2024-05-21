/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-dorian.senecot
** File description:
** my
*/

#ifndef MY
    #define MY
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <errno.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <time.h>
    #include <math.h>

    void my_putchar(char c);
    void my_putstr(char const *str);
    int my_str_isalpha(char const *str, char c);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    int countc(char *str, char c);
    int my_compute_power_rec(int nb, int p);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    char *my_revstr(char *str);
    int my_strlen(char const *str);
    int my_str_islower(char const *str);
    int my_str_isnum(char const *str);
    int my_str_isprintable(char const *str);
    int my_str_isupper(char const *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strlowcase(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strupcase(char *str);
    void my_swap(int *a, int *b);
    int my_put_nbr(int nb);
    int my_getnbr(char const *str);
    char *my_int_to_strnum(int nb);
    int fs_open_file(char const *filepath);
    char **my_str_to_word_array(char *str);

#endif /* !MY */
