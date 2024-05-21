/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_esc
*/

#include "my.h"
#include "rpg.h"

void event_inv_press(rpg_t *rpg)
{
    if (rpg->bg->st == 5
        && rpg->game->inv_st == 0
            && rpg->game->settings == 0) {
        rpg->game->inv_st = 1;
    } else if (rpg->bg->st == 5
        && rpg->game->inv_st == 1) {
        rpg->game->inv_st = 0;
    }
}

void event_esc_press(rpg_t *rpg)
{
    if (rpg->bg->st == 5 &&
            rpg->game->settings == 0 && rpg->game->inv_st == 0) {
            rpg->game->settings = 1;
            rpg->bg->st = 6;
    } else if (rpg->bg->st == 6
        && rpg->game->settings == 1) {
            rpg->game->settings = 0;
            rpg->bg->st = 5;
    }
}

void event_click_esc_add(rpg_t *rpg)
{
    if (rpg->head->event.type == sfEvtMouseButtonPressed &&
        is_clicked(rpg, rpg->game->esc->off) && rpg->head->screen_st == 0) {
        sfMusic_play(rpg->music->music_click_button);
        set_music(rpg);
        event_fullscreen_click(rpg);
        rpg->head->screen_st = 1;
    } else if (rpg->head->event.type == sfEvtMouseButtonPressed &&
        is_clicked(rpg, rpg->game->esc->on) && rpg->head->screen_st == 1) {
        sfMusic_play(rpg->music->music_click_button);
        set_music(rpg);
        event_fullscreen_click(rpg);
        rpg->head->screen_st = 0;
    }
}

void event_click_esc(rpg_t *rpg)
{
    if ((is_clicked(rpg, rpg->game->esc->on) ||
    is_clicked(rpg, rpg->game->esc->off)) &&
    (rpg->bg->st == 5 || rpg->bg->st == 6)) {
        sfMusic_play(rpg->music->music_click_button);
        set_music(rpg);
        event_click_esc_add(rpg);
    } else {
        sfSprite_setColor(rpg->game->esc->off->texture_init, sfWhite);
        sfSprite_setColor(rpg->game->esc->on->texture_init, sfWhite);
    }
}
