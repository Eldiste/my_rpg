/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** particles_utils.c
*/

#include "rpg.h"

void initialize_all_particles(particles_t *particles)
{
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].life = 0;
    }
}

int hp_decreased(rpg_t *rpg)
{
    int current_hp = rpg->game->skills->hp->hp;
    int decreased = 0;
    if (current_hp < rpg->game->skills->hp->previous_hp)
        decreased = 1;
    rpg->game->skills->hp->previous_hp = current_hp;
    return decreased;
}
