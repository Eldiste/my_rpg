/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** init_pos_button
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void init_pos_champ(champ_t *champ)
{
    sfSprite_setPosition(champ->c1->texture_init,
    (sfVector2f){1920 / 2 - 600, 150});
    sfSprite_setPosition(champ->c1_s,
    (sfVector2f){1920 / 2 - 515, 150});
    sfSprite_setPosition(champ->c2->texture_init,
    (sfVector2f){1920 / 2 + 300, 150});
    sfSprite_setPosition(champ->c2_s,
    (sfVector2f){1920 / 2 + 390, 150});
    sfSprite_setPosition(champ->c3->texture_init,
    (sfVector2f){1920 / 2 - 150, 600});
    sfSprite_setPosition(champ->c3_s,
    (sfVector2f){1920 / 2 - 60, 600});
    sfSprite_setTextureRect(champ->c1_s, get_rect(0, 0, 48, 48));
    sfSprite_setTextureRect(champ->c2_s, get_rect(0, 0, 48, 48));
    sfSprite_setTextureRect(champ->c3_s, get_rect(0, 0, 48, 48));
    champ->c1->rect = sfSprite_getGlobalBounds(champ->c1->texture_init);
    champ->c2->rect = sfSprite_getGlobalBounds(champ->c2->texture_init);
    champ->c3->rect = sfSprite_getGlobalBounds(champ->c3->texture_init);
}

void init_pos_playm(play_t *playm)
{
    sfSprite_setPosition(playm->s1->texture_init,
    (sfVector2f){1920 / 2 - 425, 35});
    sfSprite_setPosition(playm->s2->texture_init,
    (sfVector2f){1920 / 2 - 425, 365});
    sfSprite_setPosition(playm->s3->texture_init,
    (sfVector2f){1920 / 2 - 425, 685});
    sfSprite_setPosition(playm->quit->texture_init,
    (sfVector2f){5, 1000});
    playm->t2 = init_text((sfVector2f){1920 / 2 - 550, 355},
    sfWhite, 25, wichsave("saves/s2.txt"));
    playm->t3 = init_text((sfVector2f){1920 / 2 - 550, 680},
    sfWhite, 25, wichsave("saves/s3.txt"));
    playm->s1->rect = sfSprite_getGlobalBounds(playm->s1->texture_init);
    playm->s2->rect = sfSprite_getGlobalBounds(playm->s2->texture_init);
    playm->s3->rect = sfSprite_getGlobalBounds(playm->s3->texture_init);
    playm->quit->rect = sfSprite_getGlobalBounds(playm->quit->texture_init);
}

void init_pos_button_rect(bg_t *bg)
{
    bg->play->rect = sfSprite_getGlobalBounds(bg->play->texture_init);
    bg->settings->rect = sfSprite_getGlobalBounds(bg->settings->texture_init);
    bg->quit->rect = sfSprite_getGlobalBounds(bg->quit->texture_init);
    bg->son->rect = sfSprite_getGlobalBounds(bg->son->texture_init);
    bg->effect->rect = sfSprite_getGlobalBounds(bg->effect->texture_init);
    bg->info->rect = sfSprite_getGlobalBounds(bg->info->texture_init);
    bg->opt->back->rect =
    sfSprite_getGlobalBounds(bg->opt->back->texture_init);
    bg->opt->on->rect = sfSprite_getGlobalBounds(bg->opt->on->texture_init);
    bg->opt->off->rect = sfSprite_getGlobalBounds(bg->opt->off->texture_init);
}

void init_pos_button(bg_t *bg)
{
    sfSprite_setPosition(bg->play->texture_init,
    (sfVector2f){1920 / 2 - 105, 1080 / 2 - 50});
    sfSprite_setPosition(bg->settings->texture_init,
    (sfVector2f){1920 / 2 - 105, 1080 / 2 + 50});
    sfSprite_setPosition(bg->quit->texture_init,
    (sfVector2f){1920 / 2 - 105, 1080 / 2 + 150});
    sfSprite_setPosition(bg->son->texture_init,
    (sfVector2f){1920 / 2 - 880, 5});
    sfSprite_setPosition(bg->effect->texture_init, (sfVector2f){0, 5});
    sfSprite_setPosition(bg->info->texture_init, (sfVector2f){1850, 5});
    sfSprite_setPosition(bg->opt->back->texture_init, (sfVector2f){1460, 5});
    sfSprite_setPosition(bg->opt->bg, (sfVector2f){325, 20});
    sfSprite_setPosition(bg->opt->on->texture_init,
    (sfVector2f){1920 / 2 + 350, 172});
    sfSprite_setPosition(bg->opt->off->texture_init,
    (sfVector2f){1920 / 2 + 350, 172});
    init_pos_button_rect(bg);
}
