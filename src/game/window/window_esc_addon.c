/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** window_esc_addon
*/

#include "rpg.h"

void window_esc_addon2(rpg_t *rpg)
{
    if (rpg->head->screen_st == 0) {
        sfRenderWindow_drawSprite(rpg->head->window,
        rpg->game->esc->off->texture_init, NULL);
    } else if (rpg->head->screen_st == 1) {
        sfRenderWindow_drawSprite(rpg->head->window,
        rpg->game->esc->on->texture_init, NULL);
    }
    window_esc_textdr(rpg);
    event_slider_frame(rpg, rpg->game->esc->frame_s, 61.f, &rpg->head->frame);
    event_slider(rpg, rpg->game->esc->music_s, 15.f, &rpg->head->music);
    event_slider(rpg, rpg->game->esc->effect_s, 15.f, &rpg->head->effect);
    event_slider(rpg, rpg->game->esc->light_s, 15.f, &rpg->utils->light);
}

void window_esc_addon(rpg_t *rpg, sfVector2f healthBarPos)
{
    window_esc_slide_pos(rpg->game->esc->frame_s,
    (sfVector2f){healthBarPos.x + 575, healthBarPos.y + 225});
    window_esc_slide_pos(rpg->game->esc->light_s,
    (sfVector2f){healthBarPos.x + 575, healthBarPos.y + 315});
    window_esc_slide_pos(rpg->game->esc->music_s,
    (sfVector2f){healthBarPos.x + 285, healthBarPos.y + 205});
    window_esc_slide_pos(rpg->game->esc->effect_s,
    (sfVector2f){healthBarPos.x + 285, healthBarPos.y + 305});
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->esc->bg, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->esc->back->texture_init, NULL);
}

void window_esc_settext(rpg_t *rpg, sfVector2f healthBarPos)
{
    set_text_position(rpg->game->esc->general,
    (sfVector2f){healthBarPos.x + 575, healthBarPos.y + 90});
    set_text_position(rpg->game->esc->audio,
    (sfVector2f){healthBarPos.x + 300, healthBarPos.y + 90});
    set_text_position(rpg->game->esc->fullscreen,
    (sfVector2f){healthBarPos.x + 540, healthBarPos.y + 145});
    set_text_position(rpg->game->esc->framerate,
    (sfVector2f){healthBarPos.x + 580, healthBarPos.y + 190});
    set_text_position(rpg->game->esc->music,
    (sfVector2f){healthBarPos.x + 315, healthBarPos.y + 170});
    set_text_position(rpg->game->esc->music_tex,
    (sfVector2f){healthBarPos.x + 320, healthBarPos.y + 220});
    set_text_position(rpg->game->esc->effect,
    (sfVector2f){healthBarPos.x + 310, healthBarPos.y + 265});
    window_esc_dr_2(rpg, healthBarPos);
}

void window_esc_start(rpg_t *rpg, sfVector2f healthBarPos)
{
    sfSprite_setPosition(rpg->game->esc->bg,
    (sfVector2f){healthBarPos.x + 210, healthBarPos.y + 50});
    sfSprite_setScale(rpg->game->esc->bg,
    (sfVector2f){0.7, 0.7});
    sfSprite_setPosition(rpg->game->esc->back->texture_init,
    (sfVector2f){healthBarPos.x + 685, healthBarPos.y + 25});
    sfSprite_setPosition(rpg->game->esc->off->texture_init,
    (sfVector2f){healthBarPos.x + 600, healthBarPos.y + 130});
    sfSprite_setPosition(rpg->game->esc->on->texture_init,
    (sfVector2f){healthBarPos.x + 600, healthBarPos.y + 130});
    sfRectangleShape_setPosition(rpg->utils->overlay, healthBarPos);
    sfSprite_setScale(rpg->game->esc->on->texture_init,
    (sfVector2f){0.3, 0.3});
    sfSprite_setScale(rpg->game->esc->off->texture_init,
    (sfVector2f){0.3, 0.3});
    sfSprite_setScale(rpg->game->esc->back->texture_init,
    (sfVector2f){0.7, 0.7});
}
