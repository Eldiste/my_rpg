/*
** EPITECH PROJECT, 2023
** monster
** File description:
** monster
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

sfIntRect browse_sprite_monster(int top, sfIntRect rect, monster_sp_t *monster)
{
    if (rect.left >= monster->left * monster->lenx)
        rect.left = 0;
    else
        rect.left += monster->left;
    rect.top = 48 * top + monster->leny + monster->top_less;
    return rect;
}

void test_dead_monster(monster_sp_t *monster, int *j)
{
    for (int i = 0; i < monster->nb_monster; i++) {
        if (monster[i].dead == 1) {
            *j = i;
            monster[i].dead = 0;
            sfClock_restart(monster[i].clock);
            break;
        }
    }
}

void random_pos(rpg_t *rpg, int *angle, int *y, monster_sp_t *monster)
{
    if (*angle != 0) {
        int j = monster->nb_monster;
        test_dead_monster(monster, &j);
        *y = 0;
        if (*angle > 180)
            *y = -200;
        else
            *y = 200;
        if ((*angle < 90 && *angle >= 0) || (*angle > 270 && *angle <= 360)) {
            *angle = -(*angle - 50);
        } else {
            *angle = (*angle - 50);
        }
        monster[j].pos = get_vector(rpg->game->player->position.x + *angle,
        rpg->game->player->position.y + *y);
        sfSprite_setPosition(monster[j].walk, monster[j].pos);
        if (j == monster->nb_monster)
            monster->nb_monster++;
    }
}

void monster_animation(rpg_t *rpg, monster_sp_t *monster, int spawn)
{
    int angle = 0, y = 0;
    if (sfTime_asSeconds(sfClock_getElapsedTime(monster->clock_1))
    >= monster->spawn_time && (monster->nb_monster < 100 && spawn < 1)) {
        angle = rand() % 360;
        sfClock_restart(monster->clock_1);
    } random_pos(rpg, &angle, &y, monster);
    move_monster(rpg, monster);
    for (int i = 0; i < monster->nb_monster; i++) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(monster[i].clock))
        >= 125) {
            sfSprite_setTextureRect(monster[i].walk, rpg->utils->monster->rect);
            sfClock_restart(monster[i].clock);
            rpg->utils->monster[i].rect =
            browse_sprite_monster(5, rpg->utils->monster[i].rect, monster);
        }
        if (monster[i].dead == 0) {
            sfRenderWindow_drawSprite(rpg->head->window, monster[i].walk, NULL);
        }
    }
}
