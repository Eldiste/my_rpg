/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** monster_manage_addon
*/

#include "my.h"
#include "rpg.h"

void kill_monster_addon(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        int dist = 100;
        if (rpg->game->end != 1)
            test_all_monster(rpg, rpg->monster->monster1, dist);
        if (rpg->game->end != 1)
            test_all_monster(rpg, rpg->monster->monster2, dist);
        if (rpg->game->end != 1)
            test_all_monster(rpg, rpg->monster->monster3, dist);
        if (rpg->game->end != 1)
            test_all_monster(rpg, rpg->monster->monster4, dist);
    }
}

void kill_monster(rpg_t *rpg)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (rpg->utils->clock_attack)) >= 325) {
        rpg->game->end = 0;
        sfClock_restart(rpg->utils->clock_attack);
        kill_monster_addon(rpg);
    }
}

void monster_rest(rpg_t *rpg)
{
    rpg->monster->spawn2 = 0;
    rpg->monster->spawn1 = 0;
    for (int i = 0; i < 100; i++) {
        rpg->monster->monster2[i].boss = 1;
        rpg->monster->monster1[i].life = 1;
        rpg->monster->monster1[i].spawn_time = 1;
        rpg->monster->monster2[i].life = 10;
        rpg->monster->monster2[i].spawn_time = 1;
    } for (int i = 0; i < 100; i++) {
        rpg->monster->monster1[i].dead = 1;
        rpg->monster->monster2[i].dead = 1;
        rpg->monster->monster3[i].dead = 1;
        rpg->monster->monster4[i].dead = 1;
    } rpg->game->player->position =
    (sfVector2f){GRID_WIDTH * TILE_SIZE / 2 - 15,
    GRID_HEIGHT * TILE_SIZE / 2 - 22.5};
}

void loot(rpg_t *rpg)
{
    if (rand() % 10 == 0) {
        rpg->game->inv->potion_left++;
    }
    if (rand() % 20 == 0) {
        rpg->game->inv->tp_left++;
    }
    rpg->game->pnj->obj->kill += 1;
    rpg->game->pnj->obj->earn += 1;
    rpg->game->skills->xp->xp += 5 * pow(1.2, rpg->game->skills->xp->lvl - 1);
    rpg->game->skills->coins->coins += 1;
}

void algo_loot(rpg_t *rpg, monster_sp_t *monster, int i)
{
    monster[i].life--;
    if (monster[i].life <= 0) {
        monster[i].dead = 1;
        loot(rpg);
    } rpg->utils->hero->rect.left = 48 * 4;
    rpg->game->end = 1;
}
