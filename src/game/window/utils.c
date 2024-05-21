/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** utils
*/

#include "rpg.h"

void window_inv_dr_2(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->music_tex->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->effect_tex->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->light_text->text, NULL);
}

void window_esc_dr_2(rpg_t *rpg, sfVector2f healthBarPos)
{
    set_text_position(rpg->game->esc->effect_tex,
    (sfVector2f){healthBarPos.x + 320, healthBarPos.y + 320});
    set_text_position(rpg->game->esc->light,
    (sfVector2f){healthBarPos.x + 590, healthBarPos.y + 275});
    set_text_position(rpg->game->esc->frame_tex,
    (sfVector2f){healthBarPos.x + 595, healthBarPos.y + 240});
    set_text_position(rpg->game->esc->light_text,
    (sfVector2f){healthBarPos.x + 610, healthBarPos.y + 328});
}
