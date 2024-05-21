/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** save_manage
*/

#include "my.h"
#include "rpg.h"

void init_s1(rpg_t *rpg, char **tab)
{
    rpg->game->skills->xp->lvl = my_getnbr(tab[1]);
    rpg->game->skills->xp->xp = my_getnbr(tab[2]);
    rpg->game->skills->coins->coins = my_getnbr(tab[3]);
    rpg->game->skills->hp->hp = my_getnbr(tab[4]);
    rpg->game->skills->def->def = my_getnbr(tab[5]);
    rpg->game->skills->atck->atck = my_getnbr(tab[6]);
    rpg->game->player->speed = my_getnbr(tab[7]);
    rpg->game->inv->potion_left = my_getnbr(tab[8]);
    rpg->game->inv->tp_left = my_getnbr(tab[9]);
    rpg->game->pnj->price = my_getnbr(tab[10]);
}

void save_2(rpg_t *rpg)
{
    char *buffer;
    char **tab;
    struct stat s;
    stat("./saves/s2.txt", &s);
    buffer = malloc(sizeof(char) * s.st_size + 1);
    read(open("./saves/s2.txt", O_RDONLY),
    buffer, s.st_size);
    tab = my_str_to_word_array(buffer);
    init_s1(rpg, tab);
}

void save_3(rpg_t *rpg)
{
    char *buffer;
    char **tab;
    struct stat s;
    stat("./saves/s3.txt", &s);
    buffer = malloc(sizeof(char) * s.st_size + 1);
    read(open("./saves/s3.txt", O_RDONLY),
    buffer, s.st_size);
    tab = my_str_to_word_array(buffer);
    init_s1(rpg, tab);
}

void save_1(rpg_t *rpg)
{
    char *buffer;
    char **tab;
    struct stat s;
    stat("./saves/s1.txt", &s);
    buffer = malloc(sizeof(char) * s.st_size + 1);
    read(open("./saves/s1.txt", O_RDONLY),
    buffer, s.st_size);
    tab = my_str_to_word_array(buffer);
    init_s1(rpg, tab);
}
