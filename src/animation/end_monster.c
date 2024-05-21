/*
** EPITECH PROJECT, 2023
** end_monster
** File description:
** end_monster
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void end_take_damage(rpg_t *rpg, monster_sp_t *monster, int i)
{
    if (rpg->game->player->position.x < monster[i].pos.x
    && rpg->game->player->position.y > monster[i].pos.y) {
        if ((monster[i].pos.x - rpg->game->player->position.x < 40)
        && (rpg->game->player->position.y - monster[i].pos.y < 40)) {
            dealt_damage(rpg);
        }
    }
    if (monster[i].pos.x < rpg->game->player->position.x
    && monster[i].pos.y > rpg->game->player->position.y) {
        if ((rpg->game->player->position.x - monster[i].pos.x < 40)
        && (monster[i].pos.y - rpg->game->player->position.y < 40)) {
            dealt_damage(rpg);
        }
    }
}

void end_move(rpg_t *rpg, float speed, int i, monster_sp_t *monster)
{
    if (rpg->game->player->position.y < monster[i].pos.y) {
        monster[i].pos.y -= speed;
        if (monster[i].pos.y - rpg->game->player->position.y > 400) {
            monster[i].dead = 1;
        }
    } else {
        monster[i].pos.y += speed;
        if (rpg->game->player->position.y - monster[i].pos.y > 400) {
            monster[i].dead = 1;
        }
    }
}
