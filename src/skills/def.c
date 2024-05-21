/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** def
*/

#include "rpg.h"

void def_algo(rpg_t *rpg)
{
    if (rpg->game->skills->coins->coins >= rpg->game->pnj->price) {
        rpg->game->skills->coins->coins -= rpg->game->pnj->price;
        rpg->game->skills->def->status++;
        rpg->game->skills->def->def = 5 *
        pow(1.2, rpg->game->skills->def->status);
        rpg->game->pnj->price = 5 *
        pow(1.5, rpg->game->skills->atck->status +
        rpg->game->skills->def->status +
        rpg->game->skills->hp->status + rpg->game->player->status);
    }
}
