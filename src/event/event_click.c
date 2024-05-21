/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_click
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void event_click_menu_add(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->info)
    && (rpg->bg->st == 0 || rpg->bg->st == 2)) {
        rpg->bg->st = 2;
        sfSprite_setColor(rpg->bg->info->texture_init, sfMagenta);
    } else {
        if (rpg->bg->st == 2)
            rpg->bg->st = 0;
        sfSprite_setColor(rpg->bg->info->texture_init, sfWhite);
    }
}

void event_click_addo_menu(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->quit) && rpg->bg->st == 0) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed) {
            sfMusic_play(rpg->music->music_click_button);
            set_music(rpg);
            sfRenderWindow_close(rpg->head->window);
        }
        sfSprite_setColor(rpg->bg->quit->texture_init, sfMagenta);
    } else {
        sfSprite_setColor(rpg->bg->quit->texture_init, sfWhite);
    }
}

void event_click_menu(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->play) && rpg->bg->st == 0) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed) {
            sfMusic_play(rpg->music->music_click_button);
            sfMusic_play(rpg->music->music_transition);
            set_music(rpg);
            event_fade(rpg);
            rpg->bg->st = 3;
        } sfSprite_setColor(rpg->bg->play->texture_init, sfMagenta);
    } else {
        sfSprite_setColor(rpg->bg->play->texture_init, sfWhite);
    } if (is_clicked(rpg, rpg->bg->settings) && rpg->bg->st == 0) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed) {
            sfMusic_play(rpg->music->music_click_button);
            set_music(rpg);
            rpg->bg->st = 1;
        } sfSprite_setColor(rpg->bg->settings->texture_init, sfMagenta);
    } else {
        sfSprite_setColor(rpg->bg->settings->texture_init, sfWhite);
    } event_click_addo_menu(rpg);
    event_click_menu_add(rpg);
}

void event_click_settings_add(rpg_t *rpg)
{
    if (rpg->head->event.type == sfEvtMouseButtonPressed &&
        is_clicked(rpg, rpg->bg->opt->off) && rpg->head->screen_st == 0) {
        sfMusic_play(rpg->music->music_click_button);
        set_music(rpg);
        event_fullscreen_click(rpg);
        rpg->head->screen_st = 1;
    } else if (rpg->head->event.type == sfEvtMouseButtonPressed &&
        is_clicked(rpg, rpg->bg->opt->on) && rpg->head->screen_st == 1) {
        sfMusic_play(rpg->music->music_click_button);
        set_music(rpg);
        event_fullscreen_click(rpg);
        rpg->head->screen_st = 0;
    }
}

void event_click_settings(rpg_t *rpg)
{
    if ((is_clicked(rpg, rpg->bg->opt->on) ||
    is_clicked(rpg, rpg->bg->opt->off)) &&
    (rpg->bg->st == 1 || rpg->bg->st == 5 || rpg->bg->st == 6)) {
        event_click_settings_add(rpg);
    } else {
        sfSprite_setColor(rpg->bg->opt->off->texture_init, sfWhite);
        sfSprite_setColor(rpg->bg->opt->on->texture_init, sfWhite);
    }
}
