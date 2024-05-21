/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_is_on
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void is_on_manage_addon(rpg_t *rpg)
{
    if (rpg->bg->st == 1)
        rpg->bg->st = 0;
    if ((rpg->bg->st == 5 || rpg->bg->st == 6))
        rpg->game->settings = 0;
}

void is_on_manage_game_addoon(rpg_t *rpg)
{
    if (rpg->bg->st == 1)
        rpg->bg->st = 0;
    else if (rpg->bg->st == 5 || rpg->bg->st == 6) {
        rpg->game->settings = 0;
        rpg->bg->st = 5;
    }
}

void is_on_manage_game(rpg_t *rpg)
{
    event_click_menu(rpg);
    event_click_settings(rpg);
    event_click_esc(rpg);
    event_save(rpg);
    if (is_clicked(rpg, rpg->game->esc->back) &&
        (rpg->bg->st == 5 || rpg->bg->st == 6)) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed) {
            sfMusic_play(rpg->music->music_click_button);
            set_music(rpg);
            is_on_manage_game_addoon(rpg);
        } sfSprite_setColor(rpg->game->esc->back->texture_init, sfMagenta);
    } else {
        sfSprite_setColor(rpg->game->esc->back->texture_init, sfWhite);
    }
}

void is_on_manage(rpg_t *rpg)
{
    event_click_menu(rpg);
    event_click_settings(rpg);
    event_play_save(rpg);
    event_champ(rpg);
    if (is_clicked(rpg, rpg->bg->opt->back) &&
    (rpg->bg->st == 1 || rpg->bg->st == 5 || rpg->bg->st == 6)) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed) {
            sfMusic_play(rpg->music->music_click_button);
            set_music(rpg);
            is_on_manage_addon(rpg);
        } sfSprite_setColor(rpg->bg->opt->back->texture_init, sfMagenta);
    } else {
        sfSprite_setColor(rpg->bg->opt->back->texture_init, sfWhite);
    }
}
