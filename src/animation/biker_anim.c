/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** biker_anim
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void ch_anim2(rpg_t *rpg, sfSprite *champ, hero_t *hero)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        sfSprite_setScale(champ, get_vector(-1.5, 1.5));
        sfSprite_setPosition(champ,
        get_vector(rpg->game->player->position.x + 48,
        rpg->game->player->position.y));
    } else {
        sfSprite_setScale(champ, get_vector(1.5, 1.5));
        sfSprite_setPosition(champ, get_vector(rpg->game->player->position.x,
        rpg->game->player->position.y));
    } sfSprite_setTextureRect(champ, hero->rect);
}

void ch_anim(rpg_t *rpg, hero_t *hero)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(rpg->utils->clock_sp))
    > 150 && rpg->game->anim_ack == 0) {
        sfClock_restart(rpg->utils->clock_sp);
        sfVector2i addon = {10, 10};
        if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            browse_sprite(48, 5, addon, hero);
        } if (sfKeyboard_isKeyPressed(sfKeyD)
        || sfKeyboard_isKeyPressed(sfKeyS)) {
            browse_sprite(48, 5, addon, hero);
        } if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            browse_sprite(48, 5, addon, hero);
        } if (!sfKeyboard_isKeyPressed(sfKeyQ) &&
        !sfKeyboard_isKeyPressed(sfKeyD)
        && !sfKeyboard_isKeyPressed(sfKeyS) &&
        !sfKeyboard_isKeyPressed(sfKeyZ)) {
            sfVector2i addon = {7, 10};
            browse_sprite(48, 3, addon, hero);
        }
    }
}

void character_animation(rpg_t *rpg, sfSprite *champ, hero_t *hero)
{
    ch_anim2(rpg, champ, hero);
    ch_anim(rpg, hero);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (rpg->utils->clock_anim_attack))
    > 150 && (rpg->game->end == 1 || rpg->game->anim_ack == 1)) {
        if (rpg->game->anim_ack == 0)
            rpg->utils->hero->rect.left = 48 * 3;
        rpg->game->anim_ack = 1;
        sfClock_restart(rpg->utils->clock_anim_attack);
        rpg->utils->hero->rect.left += 48;
        rpg->utils->hero->rect.top = 48 * 2 + 5;
        if (rpg->utils->hero->rect.left > 48 * 5)
            rpg->game->anim_ack = 0;
    } sfRenderWindow_drawSprite(rpg->head->window, champ, NULL);
}

void anim_attack3(rpg_t *rpg, sfSprite *champ)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(rpg->utils->clock_sp))
        > 100) {
        sfClock_restart(rpg->utils->clock_sp);
        if (rpg->bg->champ->rect.left == 48 * 7)
            rpg->bg->champ->rect.left = 0;
        else
            rpg->bg->champ->rect.left += 48;
        sfSprite_setTextureRect(champ, rpg->bg->champ->rect);
    }
}
