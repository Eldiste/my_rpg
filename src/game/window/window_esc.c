/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** window_esc
*/

#include "rpg.h"

void window_esc_slide_pos(slider_t *slider, sfVector2f pos)
{
    slider->trackPosition = pos;
    slider->thumbPosition =
    (sfVector2f){slider->trackPosition.x + slider->thumbRadius,
    slider->trackPosition.y + slider->tracksize.y - 12};
    sfRectangleShape_setPosition(slider->track, slider->trackPosition);
}

void window_esc_slide(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->game->esc->frame_s->track, NULL);
    sfRenderWindow_drawCircleShape(rpg->head->window,
    rpg->game->esc->frame_s->thumb, NULL);
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->game->esc->music_s->track, NULL);
    sfRenderWindow_drawCircleShape(rpg->head->window,
    rpg->game->esc->music_s->thumb, NULL);
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->game->esc->effect_s->track, NULL);
    sfRenderWindow_drawCircleShape(rpg->head->window,
    rpg->game->esc->effect_s->thumb, NULL);
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->game->esc->light_s->track, NULL);
    sfRenderWindow_drawCircleShape(rpg->head->window,
    rpg->game->esc->light_s->thumb, NULL);
    event_slider_frame(rpg, rpg->game->esc->frame_s, 45.f, &rpg->head->frame);
    event_slider(rpg, rpg->game->esc->music_s, 7.f, &rpg->head->music);
    event_slider(rpg, rpg->game->esc->effect_s, 7.f, &rpg->head->effect);
    event_slider(rpg, rpg->game->esc->light_s, 7.f, &rpg->utils->light);
}

void window_esc_textset(rpg_t *rpg)
{
    rpg->game->esc->frame_tex->str =
    my_strcat(my_int_to_strnum(rpg->head->frame), " FPS");
    rpg->game->esc->music_tex->str =
    my_strcat(my_int_to_strnum(rpg->head->music), " %");
    rpg->game->esc->effect_tex->str =
    my_strcat(my_int_to_strnum(rpg->head->effect), " %");
    rpg->game->esc->light_text->str =
    my_strcat(my_int_to_strnum(rpg->utils->light), " %");
    get_text(rpg, rpg->game->esc->frame_tex);
    get_text(rpg, rpg->game->esc->music_tex);
    get_text(rpg, rpg->game->esc->effect_tex);
    get_text(rpg, rpg->game->esc->light_text);
    get_text(rpg, rpg->game->esc->fullscreen);
    get_text(rpg, rpg->game->esc->framerate);
    get_text(rpg, rpg->game->esc->general);
    get_text(rpg, rpg->game->esc->audio);
    get_text(rpg, rpg->game->esc->music);
    get_text(rpg, rpg->game->esc->effect);
    get_text(rpg, rpg->game->esc->light);
}

void window_esc_textdr(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->fullscreen->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->framerate->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->general->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->audio->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->music->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->effect->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->light->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->esc->frame_tex->text, NULL);
    window_inv_dr_2(rpg);
}

void esc_main(rpg_t *rpg)
{
    rpg->game->esc->back->rect =
    sfSprite_getGlobalBounds(rpg->game->esc->back->texture_init);
    rpg->game->esc->on->rect =
    sfSprite_getGlobalBounds(rpg->game->esc->on->texture_init);
    rpg->game->esc->off->rect =
    sfSprite_getGlobalBounds(rpg->game->esc->off->texture_init);
    window_esc_textset(rpg);
    rpg->head->view_pos = sfView_getCenter(rpg->head->new_view);
    rpg->head->view_size = sfView_getSize(rpg->head->new_view);
    sfVector2f healthBarPos = {rpg->head->view_pos.x -
    rpg->head->view_size.x / 2, rpg->head->view_pos.y -
    rpg->head->view_size.y / 2};
    window_esc_start(rpg, healthBarPos);
    window_esc_settext(rpg, healthBarPos);
    window_esc_addon(rpg, healthBarPos);
    window_esc_slide(rpg);
    window_esc_addon2(rpg);
}
