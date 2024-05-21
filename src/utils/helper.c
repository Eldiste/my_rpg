/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-dorian.senecot
** File description:
** helper
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

int helperprint(rpg_t *rpg)
{
    char *buffer;
    struct stat s;
    stat("./src/utils/help.txt", &s);
    buffer = malloc(sizeof(char) * s.st_size + 1);
    read(open("./src/utils/help.txt", O_RDONLY),
    buffer, s.st_size);
    buffer[s.st_size] = '\0';
    rpg->help = buffer;
    my_putstr(rpg->help);
    free(buffer);
    return 0;
}
