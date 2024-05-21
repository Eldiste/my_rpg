/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** init_main_utils.c
*/

#include "rpg.h"

bg_t *init_bg(void)
{
    bg_t *bg = malloc(sizeof(bg_t));
    bg->opt = init_opt();
    bg->but = sfTexture_createFromFile
    ("sprite/button_init.png", NULL);
    bg->play = init_button(bg->but, get_rect(7, 7, 201, 66));
    bg->settings = init_button(bg->but, get_rect(152, 7, 201, 66));
    bg->quit = init_button(bg->but, get_rect(367, 7, 201, 66));
    bg->son = init_button(bg->but, get_rect(296, 491, 65, 65));
    bg->effect = init_button(bg->but, get_rect(296, 422, 65, 65));
    bg->info = init_button(bg->but, get_rect(152, 560, 65, 65));
    bg->bg = get_sprite(sfTexture_createFromFile
    ("sprite/bg.png", NULL));
    bg->logo = get_sprite(sfTexture_createFromFile
    ("sprite/logo.png", NULL));
    init_pos_button(bg);
    bg->st = 0; bg->wich = 0;
    bg->play_m = init_playm(bg);
    bg->champ = init_champ();
    bg->clock = sfClock_create();
    return bg;
}

xp_t *init_xp(void)
{
    xp_t *xp = malloc(sizeof(xp_t));
    xp->xp_rect = sfRectangleShape_create();
    xp->xp_rect_base = sfRectangleShape_create();
    sfRectangleShape_setFillColor(xp->xp_rect_base,
    (sfColor){35, 35, 35, 255});
    sfRectangleShape_setSize(xp->xp_rect_base, (sfVector2f){1920, 10});
    xp->xp_txt = init_text((sfVector2f){0, 0},
    sfWhite, 20, "LEVEL");
    xp->lvl = 1;
    xp->xp_max = 50 * pow(1.5, xp->lvl - 1);
    xp->xp = 0;
    return xp;
}
