/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_champ
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void event_champ_punk(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->champ->c2) && rpg->bg->st == 4
    && rpg->utils->st_f > 49) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed
            && sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_play(rpg->music->music_click_button);
            sfMusic_play(rpg->music->music_transition);
            sfMusic_play(rpg->music->music_game);
            set_music(rpg);
            rpg->bg->st = 5; rpg->hero->selected = 2;
            rpg->utils->st_f = 0;
        } anim_attack3(rpg, rpg->bg->champ->c2_s);
        sfText_setColor(rpg->bg->champ->c2t->text, sfMagenta);
        sfSprite_setColor(rpg->bg->champ->c2->texture_init, sfMagenta);
    } else {
        sfSprite_setTextureRect(rpg->bg->champ->c2_s, get_rect(0, 0, 48, 48));
        sfText_setColor(rpg->bg->champ->c2t->text, sfWhite);
        sfSprite_setColor(rpg->bg->champ->c2->texture_init, sfWhite);
    }
}

void event_champ_cyborg(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->champ->c3) && rpg->bg->st == 4
    && rpg->utils->st_f > 49) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed
            && sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_play(rpg->music->music_click_button);
            sfMusic_play(rpg->music->music_transition);
            sfMusic_play(rpg->music->music_game);
            set_music(rpg);
            rpg->bg->st = 5; rpg->hero->selected = 1;
            rpg->utils->st_f = 0;
        } anim_attack3(rpg, rpg->bg->champ->c3_s);
        sfText_setColor(rpg->bg->champ->c3t->text, sfMagenta);
        sfSprite_setColor(rpg->bg->champ->c3->texture_init, sfMagenta);
    } else {
        sfSprite_setTextureRect(rpg->bg->champ->c3_s, get_rect(0, 0, 48, 48));
        sfText_setColor(rpg->bg->champ->c3t->text, sfWhite);
        sfSprite_setColor(rpg->bg->champ->c3->texture_init, sfWhite);
    }
}

void event_champ(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->champ->c1) && rpg->bg->st == 4
    && rpg->utils->st_f > 49) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed
            && sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_play(rpg->music->music_click_button);
            sfMusic_play(rpg->music->music_transition);
            sfMusic_play(rpg->music->music_game);
            set_music(rpg);
            rpg->bg->st = 5; rpg->hero->selected = 0;
            rpg->utils->st_f = 0;
        } anim_attack3(rpg, rpg->bg->champ->c1_s);
        sfText_setColor(rpg->bg->champ->c1t->text, sfMagenta);
        sfSprite_setColor(rpg->bg->champ->c1->texture_init, sfMagenta);
    } else {
        sfSprite_setTextureRect(rpg->bg->champ->c1_s, get_rect(0, 0, 48, 48));
        sfText_setColor(rpg->bg->champ->c1t->text, sfWhite);
        sfSprite_setColor(rpg->bg->champ->c1->texture_init, sfWhite);
    } event_champ_cyborg(rpg); event_champ_punk(rpg);
}
