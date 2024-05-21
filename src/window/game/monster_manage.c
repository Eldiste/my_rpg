/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** monster_manage
*/

#include "my.h"
#include "rpg.h"

void test_all_monster_addon2b(rpg_t *rpg, monster_sp_t *monster,
int dist, int i)
{
    if (rpg->game->player->position.y <= monster[i].pos.y) {
        if ((rpg->game->player->position.x - monster[i].pos.x < dist)
    && (monster[i].pos.y - rpg->game->player->position.y < dist)
    && rpg->head->mouse_pos.x <= (int)rpg->head->video_mode.width / 2 + 60
    && rpg->head->mouse_pos.y >= (int)rpg->head->video_mode.height / 2 - 80) {
            algo_loot(rpg, monster, i);
        }
    }
    if (rpg->game->player->position.y > monster[i].pos.y) {
        if ((rpg->game->player->position.x - monster[i].pos.x < dist)
    && (rpg->game->player->position.y - monster[i].pos.y < dist)
    && rpg->head->mouse_pos.x <= (int)rpg->head->video_mode.width / 2 + 60
    && rpg->head->mouse_pos.y <= (int)rpg->head->video_mode.height / 2 + 80) {
            algo_loot(rpg, monster, i);
        }
    }
}

void test_all_monster_addon2h(rpg_t *rpg, monster_sp_t *monster,
int dist, int i)
{
    if (rpg->game->player->position.y <= monster[i].pos.y) {
        if (((monster[i].pos.x - rpg->game->player->position.x < dist)
    && (monster[i].pos.y - rpg->game->player->position.y < dist))
    && rpg->head->mouse_pos.x >= (int)rpg->head->video_mode.width / 2 - 60
    && rpg->head->mouse_pos.y >= (int)rpg->head->video_mode.height / 2 - 80) {
            algo_loot(rpg, monster, i);
        }
    }
    if (rpg->game->player->position.y > monster[i].pos.y) {
        if ((monster[i].pos.x - rpg->game->player->position.x < dist)
    && (rpg->game->player->position.y - monster[i].pos.y < dist)
    && rpg->head->mouse_pos.x >= (int)rpg->head->video_mode.width / 2 - 60
    && rpg->head->mouse_pos.y <= (int)rpg->head->video_mode.height / 2 + 80) {
            algo_loot(rpg, monster, i);
        }
    }
}

void test_all_monster_addonb(rpg_t *rpg, monster_sp_t *monster,
int dist, int i)
{
    if (rpg->game->player->position.x > monster[i].pos.x) {
        test_all_monster_addon2b(rpg, monster, dist, i);
    }
}

void test_all_monster_addonh(rpg_t *rpg, monster_sp_t *monster,
int dist, int i)
{
    if (rpg->game->player->position.x <= monster[i].pos.x) {
        test_all_monster_addon2h(rpg, monster, dist, i);
    }
}

void test_all_monster(rpg_t *rpg, monster_sp_t *monster, int dist)
{
    for (int i = 0; i < monster->nb_monster; i++) {
        if (monster[i].dead == 0) {
            test_all_monster_addonh(rpg, monster, dist, i);
            test_all_monster_addonb(rpg, monster, dist, i);
        }
    }
}
