/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** xp
*/

#include "rpg.h"

void xp_rect_color(rpg_t *rpg)
{
    float size = 1000.0 / rpg->game->skills->xp->xp_max *
    rpg->game->skills->xp->xp;
    sfRectangleShape_setSize(rpg->game->skills->xp->xp_rect,
    (sfVector2f){size, 20});
    sfRectangleShape_setFillColor(rpg->game->skills->xp->xp_rect,
    sfBlue);
}

void xp_algo(rpg_t *rpg)
{
    if (rpg->game->skills->xp->xp >= rpg->game->skills->xp->xp_max) {
        sfMusic_play(rpg->music->music_next_level);
        set_music(rpg);
        rpg->game->skills->xp->xp = 0;
        rpg->game->skills->xp->lvl++;
        rpg->game->skills->xp->xp_max = 50 *
        pow(1.2, rpg->game->skills->xp->lvl - 1);
        rpg->game->skills->coins->coins += 10 *
        pow(1.1, rpg->game->skills->xp->lvl - 1);
        rpg->game->pnj->obj->earn += 10 *
        pow(1.1, rpg->game->skills->xp->lvl - 1);
    }
}

void xp_draw(rpg_t *rpg)
{
    sfVector2f healthBarPos = {rpg->head->view_pos.x -
    rpg->head->view_size.x / 2, rpg->head->view_pos.y -
    rpg->head->view_size.y / 2 + 530};
    sfVector2f text_pos = {rpg->head->view_pos.x -
    rpg->head->view_size.x / 2, rpg->head->view_pos.y -
    rpg->head->view_size.y / 2};
    sfRectangleShape_setPosition(rpg->game->skills->xp->xp_rect_base,
    healthBarPos);
    sfRectangleShape_setPosition(rpg->game->skills->xp->xp_rect, healthBarPos);
    rpg->game->skills->xp->xp_txt->str = my_strcat("LEVEL ",
    my_int_to_strnum(rpg->game->skills->xp->lvl));
    get_text(rpg, rpg->game->skills->xp->xp_txt);
    set_text_position(rpg->game->skills->xp->xp_txt,
    (sfVector2f){text_pos.x + 450, text_pos.y + 500});
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->game->skills->xp->xp_rect_base, NULL);
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->game->skills->xp->xp_rect, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->skills->xp->xp_txt->text, NULL);
}

void xp_manage(rpg_t *rpg)
{
    xp_rect_color(rpg);
    xp_draw(rpg);
    xp_algo(rpg);
}
