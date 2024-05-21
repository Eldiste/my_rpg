/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_tp
*/

#include "my.h"
#include "rpg.h"

void tp_clicked(rpg_t *rpg, sfBool *button_pressed)
{
    if (is_clicked(rpg, rpg->game->inv->tp)
        && rpg->bg->st == 5) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed
            && !(*button_pressed)) {
                algo_tp(rpg);
            *button_pressed = sfTrue;
        }
        rpg->game->inv->tp_txt->color = sfMagenta;
        sfSprite_setColor(rpg->game->inv->tp->texture_init,
        sfMagenta);
    } else {
        rpg->game->inv->tp_txt->color = sfWhite;
        sfSprite_setColor(rpg->game->inv->tp->texture_init,
        sfWhite);
    }
}

void event_tp(rpg_t *rpg)
{
    static sfBool button_pressed = sfFalse;

    tp_clicked(rpg, &button_pressed);

    if (rpg->head->event.type == sfEvtMouseButtonReleased) {
        button_pressed = sfFalse;
    }
}
