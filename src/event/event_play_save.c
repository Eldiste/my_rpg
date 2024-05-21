/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_play
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void event_play_save_addon(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->play_m->s3) && rpg->bg->st == 3
    && rpg->utils->st_f > 49) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed) {
            save_3(rpg);
            sfMusic_play(rpg->music->music_click_button);
            set_music(rpg); rpg->bg->wich = 2;
            rpg->bg->st = 4;
            rpg->utils->st_f = 0;
        } sfText_setColor(rpg->bg->play_m->s3t->text, sfMagenta);
        rpg->bg->play_m->t3->color = sfMagenta;
        sfSprite_setColor(rpg->bg->play_m->s3->texture_init, sfMagenta);
    } else {
        sfText_setColor(rpg->bg->play_m->s3t->text, sfWhite);
        rpg->bg->play_m->t3->color = sfWhite;
        sfSprite_setColor(rpg->bg->play_m->s3->texture_init, sfWhite);
    }
}

void event_play_addon(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->play_m->quit)
    && (rpg->bg->st == 3 || rpg->bg->st == 4)) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed) {
            sfMusic_play(rpg->music->music_click_button);
            set_music(rpg);
            rpg->bg->st = 0;
        } sfSprite_setColor(rpg->bg->play_m->quit->texture_init, sfMagenta);
    } else {
        sfSprite_setColor(rpg->bg->play_m->quit->texture_init, sfWhite);
    }
}

void event_play_addon2(rpg_t *rpg)
{
    if (is_clicked(rpg, rpg->bg->play_m->s2) && rpg->bg->st == 3
        && rpg->utils->st_f > 49) {
            if (rpg->head->event.type == sfEvtMouseButtonPressed) {
                sfMusic_play(rpg->music->music_click_button);
                set_music(rpg); rpg->bg->wich = 1;
                rpg->bg->st = 4; rpg->utils->st_f = 0;
            } sfText_setColor(rpg->bg->play_m->s2t->text, sfMagenta);
            rpg->bg->play_m->t2->color = sfMagenta;
            sfSprite_setColor(rpg->bg->play_m->s2->texture_init, sfMagenta);
        } else {
            sfText_setColor(rpg->bg->play_m->s2t->text, sfWhite);
            rpg->bg->play_m->t2->color = sfWhite;
            sfSprite_setColor(rpg->bg->play_m->s2->texture_init, sfWhite);
    } event_play_save_addon(rpg);
}

void event_play_save(rpg_t *rpg)
{
    event_play_addon(rpg);
    if (is_clicked(rpg, rpg->bg->play_m->s1) && rpg->bg->st == 3
    && rpg->utils->st_f > 49) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed) {
            sfMusic_play(rpg->music->music_click_button);
            set_music(rpg); rpg->bg->wich = 0;
            save_1(rpg);
            rpg->bg->st = 4; rpg->utils->st_f = 0;
        } sfText_setColor(rpg->bg->play_m->s1t->text, sfMagenta);
        rpg->bg->play_m->t1->color = sfMagenta;
        sfSprite_setColor(rpg->bg->play_m->s1->texture_init, sfMagenta);
    } else {
        sfText_setColor(rpg->bg->play_m->s1t->text, sfWhite);
        rpg->bg->play_m->t1->color = sfWhite;
        sfSprite_setColor(rpg->bg->play_m->s1->texture_init, sfWhite);
    } event_play_addon2(rpg);
}
