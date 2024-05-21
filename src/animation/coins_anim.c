/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** coins_anim
*/

#include "rpg.h"

void coin_anim_sp(int left, int lenx, sfVector2i addon, coins_t *coins)
{
    if (coins->rect.left >= left * lenx)
        coins->rect.left = 0;
    else
        coins->rect.left += left;
    coins->rect.top = addon.x + addon.y;
}

void coins_anim(rpg_t *rpg, sfSprite *coins, coins_t *co)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(rpg->utils->clock_coins))
    > 150) {
        sfSprite_setTextureRect(coins, co->rect);
        sfClock_restart(rpg->utils->clock_coins);
        sfVector2i addon = {0, 0};
        coin_anim_sp(147, 5, addon, co);
    } sfRenderWindow_drawSprite(rpg->head->window, coins, NULL);
}
