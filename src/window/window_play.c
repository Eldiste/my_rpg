/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** window_play
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void window_play_addon(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->play_m->s3t->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->play_m->t1->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->play_m->t2->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->play_m->t3->text, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->play_m->quit->texture_init, NULL);
}

void window_play(rpg_t *rpg)
{
    getinfo(rpg);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->play_m->s1->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->play_m->s2->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->play_m->s3->texture_init, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->play_m->s1t->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->play_m->s2t->text, NULL);
    window_play_addon(rpg);
}
