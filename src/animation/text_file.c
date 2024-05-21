/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** text_file
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void text_file(rpg_t *rpg)
{
    float speed = 1;
    sfVector2f pos;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(rpg->bg->clock)) > 50) {
        pos = sfText_getPosition(rpg->bg->text_anim->text);
        pos.y -= speed;
        sfText_setPosition(rpg->bg->text_anim->text, pos);
        sfClock_restart(rpg->bg->clock);
    }
    sfRenderWindow_drawText(rpg->head->window, rpg->bg->text_anim->text, NULL);
}
