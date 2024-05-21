/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** window_settings
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void window_settings_slide(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->bg->opt->frame_s->track, NULL);
    sfRenderWindow_drawCircleShape(rpg->head->window,
    rpg->bg->opt->frame_s->thumb, NULL);
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->bg->opt->music_s->track, NULL);
    sfRenderWindow_drawCircleShape(rpg->head->window,
    rpg->bg->opt->music_s->thumb, NULL);
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->bg->opt->effect_s->track, NULL);
    sfRenderWindow_drawCircleShape(rpg->head->window,
    rpg->bg->opt->effect_s->thumb, NULL);
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->bg->opt->light_s->track, NULL);
    sfRenderWindow_drawCircleShape(rpg->head->window,
    rpg->bg->opt->light_s->thumb, NULL);
    event_slider_frame(rpg, rpg->bg->opt->frame_s, 45.f, &rpg->head->frame);
    event_slider(rpg, rpg->bg->opt->music_s, 7.f, &rpg->head->music);
    event_slider(rpg, rpg->bg->opt->effect_s, 7.f, &rpg->head->effect);
    event_slider(rpg, rpg->bg->opt->light_s, 7.f, &rpg->utils->light);
}

void window_settings_textdr(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->fullscreen->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->framerate->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->general->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->audio->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->music->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->effect->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->light->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->frame_tex->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->music_tex->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->effect_tex->text, NULL);
}

void window_settings_textset(rpg_t *rpg)
{
    rpg->bg->opt->frame_tex->str =
    my_strcat(my_int_to_strnum(rpg->head->frame), " FPS");
    rpg->bg->opt->music_tex->str =
    my_strcat(my_int_to_strnum(rpg->head->music), " %");
    rpg->bg->opt->effect_tex->str =
    my_strcat(my_int_to_strnum(rpg->head->effect), " %");
    rpg->bg->opt->light_text->str =
    my_strcat(my_int_to_strnum(rpg->utils->light), " %");
    get_text(rpg, rpg->bg->opt->frame_tex);
    get_text(rpg, rpg->bg->opt->music_tex);
    get_text(rpg, rpg->bg->opt->effect_tex);
    get_text(rpg, rpg->bg->opt->light_text);
}

void window_settings(rpg_t *rpg)
{
    window_settings_textset(rpg);
    sfRenderWindow_drawSprite(rpg->head->window, rpg->bg->opt->bg, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->opt->back->texture_init, NULL);
    window_settings_textdr(rpg);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->opt->light_text->text, NULL);
    if (rpg->head->screen_st == 0) {
        sfRenderWindow_drawSprite(rpg->head->window,
        rpg->bg->opt->off->texture_init, NULL);
    } else if (rpg->head->screen_st == 1) {
        sfRenderWindow_drawSprite(rpg->head->window,
        rpg->bg->opt->on->texture_init, NULL);
    } if (rpg->head->music == 0) {
        rpg->bg->son->st = 1;
    } else { rpg->bg->son->st = 0;
    } if (rpg->head->effect == 0) {
        rpg->bg->effect->st = 1;
    } else { rpg->bg->effect->st = 0;
    } window_settings_slide(rpg);
}
