/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_click_sound
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void event_click_effect_add(rpg_t *rpg)
{
    if (rpg->head->event.type == sfEvtMouseButtonPressed
    && rpg->bg->effect->st == 0) {
        rpg->bg->effect->st = 1;
        rpg->head->effect = 0;
        set_music_end(rpg);
        sfSprite_setColor(rpg->bg->effect->texture_init, sfRed);
    } else if (rpg->head->event.type == sfEvtMouseButtonPressed
    && rpg->bg->effect->st == 1) {
        rpg->bg->effect->st = 0;
        rpg->head->effect = 50;
        set_music_end(rpg);
        sfSprite_setColor(rpg->bg->effect->texture_init, sfWhite);
    }
}

void event_click_music_add(rpg_t *rpg)
{
    if (((rpg->head->event.type == sfEvtMouseButtonPressed)
    || rpg->head->music == 0) && rpg->bg->son->st == 0) {
        rpg->bg->son->st = 1;
        rpg->head->music = 0;
        sfMusic_setVolume(rpg->music->music_menu, rpg->head->music);
        sfMusic_setVolume(rpg->music->music_game, rpg->head->music);
        sfSprite_setColor(rpg->bg->son->texture_init, sfRed);
    } else if (rpg->head->event.type == sfEvtMouseButtonPressed
    && rpg->bg->son->st == 1) {
        rpg->bg->son->st = 0;
        rpg->head->music = 50;
        sfMusic_setVolume(rpg->music->music_menu, rpg->head->music);
        sfMusic_setVolume(rpg->music->music_game, rpg->head->music);
        sfSprite_setColor(rpg->bg->son->texture_init, sfWhite);
    }
}

void event_click_effect(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->effect)) {
        event_click_effect_add(rpg);
        sfSprite_setColor(rpg->bg->effect->texture_init, sfMagenta);
    } else {
        rpg->bg->effect->st == 0 ?
        sfSprite_setColor(rpg->bg->effect->texture_init, sfWhite) :
        sfSprite_setColor(rpg->bg->effect->texture_init, sfRed);
    }
}

void event_click_music(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->son)) {
        event_click_music_add(rpg);
        sfSprite_setColor(rpg->bg->son->texture_init, sfMagenta);
    } else {
        rpg->bg->son->st == 0 ?
        sfSprite_setColor(rpg->bg->son->texture_init, sfWhite) :
        sfSprite_setColor(rpg->bg->son->texture_init, sfRed);
    }
}
