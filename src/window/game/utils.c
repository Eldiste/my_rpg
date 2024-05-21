/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** utils
*/

#include "my.h"
#include "rpg.h"

void vague20(rpg_t *rpg)
{
    for (int i = 0; i < 100; i++) {
        rpg->monster->monster2[i].boss = 0;
        rpg->monster->monster1[i].life = 2;
        rpg->monster->monster1[i].spawn_time = 0.5;
        rpg->monster->monster2[i].life = 5;
        rpg->monster->monster2[i].spawn_time = 4;
    }
}

void window_vague2(rpg_t *rpg)
{
    if (rpg->game->skills->xp->lvl >= 20) {
        if (rpg->monster->spawn1 == 0) {
            vague20(rpg);
        } rpg->monster->spawn1 = 1;
        monster_animation(rpg, rpg->monster->monster1, 0);
        monster_animation(rpg, rpg->monster->monster2, 0);
    }
}

void pnj_animation(rpg_t *rpg)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(rpg->utils->clock_pnj))
    > 150) {
        sfSprite_setTextureRect(rpg->game->pnj->intertaction,
        rpg->game->pnj->intertaction_rect);
        sfSprite_setTextureRect(rpg->game->pnj->crampteur->sprite,
        rpg->game->pnj->crampteur->rect);
        sfSprite_setTextureRect(rpg->game->pnj->quest->sprite,
        rpg->game->pnj->quest->rect);
        sfClock_restart(rpg->utils->clock_pnj); sfVector2i addon = {0, 0};
        sfSprite_setScale(rpg->game->pnj->intertaction, get_vector(0.75, 0.75));
        pnj_browse_sprite(48, 3, addon, rpg->game->pnj->crampteur);
        pnj_browse_sprite(48, 3, addon, rpg->game->pnj->quest);
        if (rpg->game->pnj->intertaction_rect.left >= 32 * 1)
            rpg->game->pnj->intertaction_rect.left = 0;
        else
            rpg->game->pnj->intertaction_rect.left += 32;
    } sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->pnj->crampteur->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->pnj->quest->sprite, NULL);
}

void pnj_browse_sprite(int left, int lenx, sfVector2i addon, pnjst_t *pnj)
{
    if (pnj->rect.left >= left * lenx)
        pnj->rect.left = 0;
    else
        pnj->rect.left += left;
    pnj->rect.top = addon.x + addon.y;
}

void browse_sprite(int left, int lenx, sfVector2i addon, hero_t *hero)
{
    if (hero->rect.left >= left * lenx)
        hero->rect.left = 0;
    else
        hero->rect.left += left;
    hero->rect.top = 48 * addon.x + addon.y;
}
