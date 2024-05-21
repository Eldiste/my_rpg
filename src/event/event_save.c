/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_save
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

char *infile(rpg_t *rpg)
{
    char *tmp;
    tmp = my_strcat(my_strcat("lvl: ",
    my_int_to_strnum(rpg->game->skills->xp->lvl)), "\n");
    tmp = my_strcat(tmp, my_strcat
    (my_strcat("xp: ", my_int_to_strnum(rpg->game->skills->xp->xp)), "\n"));
    tmp = my_strcat(tmp, my_strcat
    (my_strcat("coins: ",
    my_int_to_strnum(rpg->game->skills->coins->coins)), "\n"));
    tmp = my_strcat(tmp, my_strcat
    (my_strcat("hp: ", my_int_to_strnum(rpg->game->skills->hp->hp)), "\n"));
    tmp = my_strcat(tmp, my_strcat
    (my_strcat("def: ", my_int_to_strnum(rpg->game->skills->def->def)), "\n"));
    tmp = infile2(rpg, tmp);
    return tmp;
}

void event_save1(rpg_t *rpg)
{
    char filename[] = "saves/s1.txt";
    char *new_content;
    new_content = infile(rpg);
    int new_content_size = my_strlen(new_content);
    int fp;
    fp = open(filename, O_WRONLY | O_TRUNC);
    write(fp, new_content, new_content_size);
    close(fp);
}

void event_save2(rpg_t *rpg)
{
    char filename[] = "saves/s2.txt";
    char *new_content;
    new_content = infile(rpg);
    int new_content_size = my_strlen(new_content);
    int fp;
    fp = open(filename, O_WRONLY | O_TRUNC);
    write(fp, new_content, new_content_size);
    close(fp);
}

void event_save3(rpg_t *rpg)
{
    char filename[] = "saves/s3.txt";
    char *new_content;
    new_content = infile(rpg);
    int new_content_size = my_strlen(new_content);
    int fp;
    fp = open(filename, O_WRONLY | O_TRUNC);
    write(fp, new_content, new_content_size);
    close(fp);
}

void event_save(rpg_t *rpg)
{
    if (rpg->head->event.type == sfEvtKeyPressed
        && rpg->head->event.key.code == sfKeyF2) {
            if (rpg->bg->wich == 0)
                event_save1(rpg);
            if (rpg->bg->wich == 1)
                event_save2(rpg);
            if (rpg->bg->wich == 2)
                event_save3(rpg);
    }
}
