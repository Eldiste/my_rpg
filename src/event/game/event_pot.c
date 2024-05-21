/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_pot
*/


#include "my.h"
#include "rpg.h"

char *infile2(rpg_t *rpg, char *tmp)
{
    tmp = my_strcat(tmp, my_strcat
    (my_strcat("atck: ",
    my_int_to_strnum(rpg->game->skills->atck->atck)), "\n"));
    tmp = my_strcat(tmp, my_strcat
    (my_strcat("speed: ", my_int_to_strnum(rpg->game->player->speed)), "\n"));
    tmp = my_strcat(tmp, my_strcat
    (my_strcat("potion: ",
    my_int_to_strnum(rpg->game->inv->potion_left)), "\n"));
    tmp = my_strcat(tmp, my_strcat
    (my_strcat("tp: ", my_int_to_strnum(rpg->game->inv->tp_left)), "\n"));
    tmp = my_strcat(tmp, my_strcat
    (my_strcat("price: ", my_int_to_strnum(rpg->game->pnj->price)), "\n"));
    return tmp;
}

void potion_clicked(rpg_t *rpg, sfBool *button_pressed)
{
    if (is_clicked(rpg, rpg->game->inv->potion)
        && rpg->bg->st == 5) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed
            && !(*button_pressed)) {
                algo_pot(rpg);
            *button_pressed = sfTrue;
        }
        rpg->game->inv->poition_txt->color = sfMagenta;
        sfSprite_setColor(rpg->game->inv->potion->texture_init,
        sfMagenta);
    } else {
        rpg->game->inv->poition_txt->color = sfWhite;
        sfSprite_setColor(rpg->game->inv->potion->texture_init,
        sfWhite);
    }
}

void event_pot(rpg_t *rpg)
{
    static sfBool button_pressed = sfFalse;

    potion_clicked(rpg, &button_pressed);

    if (rpg->head->event.type == sfEvtMouseButtonReleased) {
        button_pressed = sfFalse;
    }
}
