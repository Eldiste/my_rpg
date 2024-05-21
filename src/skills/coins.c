/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** coins
*/

#include "rpg.h"

void algo_quest(rpg_t *rpg)
{
    if (rpg->game->pnj->obj->kill >= rpg->game->pnj->obj->kill_obj) {
        rpg->game->pnj->obj->kill = 0;
        rpg->game->pnj->obj->earn += 10 *
        pow(1.1, rpg->game->skills->xp->lvl - 1);
        rpg->game->skills->coins->coins += 10 *
        pow(1.1, rpg->game->skills->xp->lvl - 1);
        rpg->game->pnj->obj->kill_obj += 10;
    } if (rpg->game->pnj->obj->earn >= rpg->game->pnj->obj->earn_obj) {
        if (rpg->game->skills->hp->hp + 50 > rpg->game->skills->hp->hp_max)
            rpg->game->skills->hp->hp = rpg->game->skills->hp->hp_max;
        else
            rpg->game->skills->hp->hp += 50;
        rpg->game->pnj->obj->earn = 0;
        rpg->game->pnj->obj->earn_obj += 5;
    }
}

void coins_draw(rpg_t *rpg)
{
    sfVector2f healthBarPos = {rpg->head->view_pos.x -
    rpg->head->view_size.x / 2, rpg->head->view_pos.y -
    rpg->head->view_size.y / 2};
    rpg->game->skills->coins->coins_txt->str =
    my_strcat(" : ", my_int_to_strnum(rpg->game->skills->coins->coins));
    get_text(rpg, rpg->game->skills->coins->coins_txt);
    set_text_position(rpg->game->skills->coins->coins_txt,
    (sfVector2f){healthBarPos.x + 875, healthBarPos.y + 3});
    sfSprite_setPosition(rpg->game->skills->coins->sprite,
    (sfVector2f){healthBarPos.x + 850, healthBarPos.y});
    sfSprite_setScale(rpg->game->skills->coins->sprite, get_vector(0.2, 0.2));
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->skills->coins->coins_txt->text, NULL);
    coins_anim(rpg, rpg->game->skills->coins->sprite,
    rpg->game->skills->coins);
}

void coin_manage(rpg_t *rpg)
{
    coins_draw(rpg);
}
