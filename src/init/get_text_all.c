/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** get_text_all
*/

#include "rpg.h"

void getinfo(rpg_t *rpg)
{
    rpg->bg->play_m->t1->str = wichsave("saves/s1.txt");
    rpg->bg->play_m->t2->str = wichsave("saves/s2.txt");
    rpg->bg->play_m->t3->str = wichsave("saves/s3.txt");
    get_text(rpg, rpg->bg->play_m->t1);
    get_text(rpg, rpg->bg->play_m->t2);
    get_text(rpg, rpg->bg->play_m->t3);
}

void get_text_all(rpg_t *rpg)
{
    get_text(rpg, rpg->bg->opt->fullscreen);
    get_text(rpg, rpg->bg->opt->general);
    get_text(rpg, rpg->bg->opt->audio);
    get_text(rpg, rpg->bg->opt->framerate);
    get_text(rpg, rpg->bg->opt->music);
    get_text(rpg, rpg->bg->opt->effect);
    get_text(rpg, rpg->bg->opt->light);
    get_text(rpg, rpg->bg->play_m->s1t);
    get_text(rpg, rpg->bg->play_m->s2t);
    get_text(rpg, rpg->bg->play_m->s3t);
    get_text(rpg, rpg->bg->champ->c1t);
    get_text(rpg, rpg->bg->champ->c2t);
    get_text(rpg, rpg->bg->champ->c3t);
    get_text(rpg, rpg->game->death);
    get_text(rpg, rpg->bg->text_anim);
}
