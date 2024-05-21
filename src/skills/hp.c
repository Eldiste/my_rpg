/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** hp
*/

#include "rpg.h"

void set_text_position(text_t *text, sfVector2f position)
{
    text->vect = position;
    sfText_setPosition(text->text, position);
}

void hp_rect_color(rpg_t *rpg)
{
    float size = 200.0 / rpg->game->skills->hp->hp_max *
    rpg->game->skills->hp->hp;
    sfRectangleShape_setSize(rpg->game->skills->hp->hp_rect,
    (sfVector2f){size, 15});
    sfRectangleShape_setFillColor(rpg->game->skills->hp->hp_rect,
        (sfColor){255, 20, 0, 255});
    if (rpg->game->skills->hp->hp >= rpg->game->skills->hp->hp_max / 5 * 1)
        sfRectangleShape_setFillColor(rpg->game->skills->hp->hp_rect,
        (sfColor){255, 100, 0, 255});
    if (rpg->game->skills->hp->hp >= rpg->game->skills->hp->hp_max / 5 * 2)
        sfRectangleShape_setFillColor(rpg->game->skills->hp->hp_rect,
        (sfColor){230, 190, 0, 255});
    if (rpg->game->skills->hp->hp >= rpg->game->skills->hp->hp_max / 5 * 3)
        sfRectangleShape_setFillColor(rpg->game->skills->hp->hp_rect,
        (sfColor){120, 190, 0, 255});
    if (rpg->game->skills->hp->hp >= rpg->game->skills->hp->hp_max / 5 * 4)
        sfRectangleShape_setFillColor(rpg->game->skills->hp->hp_rect,
        (sfColor){0, 190, 0, 255});
}

void hp_algo(rpg_t *rpg)
{
    if (rpg->game->skills->coins->coins >= rpg->game->pnj->price) {
        rpg->game->skills->coins->coins -= rpg->game->pnj->price;
        rpg->game->skills->hp->status++;
        rpg->game->skills->hp->hp_max = 100 *
        pow(1.2, rpg->game->skills->hp->status);
        rpg->game->skills->hp->hp = rpg->game->skills->hp->hp_max;
        rpg->game->pnj->price = 5 *
        pow(1.5, rpg->game->skills->atck->status +
        rpg->game->skills->def->status +
        rpg->game->skills->hp->status + rpg->game->player->status);
    }
}

void hp_draw(rpg_t *rpg)
{
    sfVector2f healthBarPos = {rpg->head->view_pos.x -
    rpg->head->view_size.x / 2, rpg->head->view_pos.y -
    rpg->head->view_size.y / 2};
    sfRectangleShape_setPosition(rpg->game->skills->hp->hp_rect_base,
    (sfVector2f){healthBarPos.x + 5, healthBarPos.y + 5});
    sfRectangleShape_setPosition(rpg->game->skills->hp->hp_rect,
    (sfVector2f){healthBarPos.x + 5, healthBarPos.y + 5});
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->game->skills->hp->hp_rect_base, NULL);
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->game->skills->hp->hp_rect, NULL);
}

void hp_manage(rpg_t *rpg)
{
    hp_rect_color(rpg);
    hp_draw(rpg);
}
