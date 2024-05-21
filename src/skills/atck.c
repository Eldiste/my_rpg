/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** atck
*/

#include "rpg.h"

void speed_algo(rpg_t *rpg)
{
    if (rpg->game->skills->coins->coins >= rpg->game->pnj->price) {
        rpg->game->skills->coins->coins -= rpg->game->pnj->price;
        rpg->game->player->status++;
        rpg->game->player->speed = 100 * pow(1.1, rpg->game->player->status);
        rpg->game->pnj->price = 5 *
        pow(1.5, rpg->game->skills->atck->status +
        rpg->game->skills->def->status + rpg->game->skills->hp->status +
        rpg->game->player->status);
    }
}

void atck_algo(rpg_t *rpg)
{
    if (rpg->game->skills->coins->coins >= rpg->game->pnj->price) {
        rpg->game->skills->coins->coins -= rpg->game->pnj->price;
        rpg->game->skills->atck->status++;
        rpg->game->skills->atck->atck = 5 *
        pow(1.2, rpg->game->skills->atck->status);
        rpg->game->pnj->price = 5 *
        pow(1.5, rpg->game->skills->atck->status +
        rpg->game->skills->def->status + rpg->game->skills->hp->status +
        rpg->game->player->status);
    }
}
