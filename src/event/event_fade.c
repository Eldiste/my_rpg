/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** fade
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void event_fade(rpg_t *rpg)
{
    if ((rpg->bg->st == 1 || rpg->bg->st == 3
    || rpg->bg->st == 4 || rpg->bg->st == 5)
    && rpg->utils->second > 0.001 && rpg->utils->st_f < 50) {
        sfRectangleShape_setFillColor(rpg->utils->overlay,
        (sfColor){0, 0, 0, rpg->utils->st_f * 5 + rpg->utils->light});
        rpg->utils->st_f++;
        sfRenderWindow_drawRectangleShape(rpg->head->window,
        rpg->utils->overlay, NULL);
        sfClock_restart(rpg->utils->clokck_f);
    } if (rpg->bg->st == 0) {
        rpg->utils->st_f = 0;
    }
}
