/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** particles.c
*/

#include "rpg.h"

void update_particles(particles_t *particles, float dt)
{
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].position.x += particles[i].velocity.x * dt;
        particles[i].position.y += particles[i].velocity.y * dt;
        particles[i].velocity.y += particles[i].gravity * dt;
        particles[i].life -= dt;
    }
}

void append_vertex(sfVertexArray *vertexArray, particles_t *particles, int i)
{
    sfVertex vertice[4] = {
        {.position = {particles[i].position.x - particles[i].size,
        particles[i].position.y - particles[i].size},
        .color = particles[i].color},
        {.position = {particles[i].position.x + particles[i].size,
        particles[i].position.y - particles[i].size},
        .color = particles[i].color},
        {.position = {particles[i].position.x + particles[i].size,
        particles[i].position.y + particles[i].size},
        .color = particles[i].color},
        {.position = {particles[i].position.x - particles[i].size,
        particles[i].position.y + particles[i].size},
        .color = particles[i].color}
    };
    for (int j = 0; j < 4; j++) {
        sfVertexArray_append(vertexArray, vertice[j]);
    }
}

void draw_particles(sfRenderWindow *window, particles_t *particles)
{
    sfVertexArray *vertexArray = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(vertexArray, sfQuads);
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (particles[i].life > 0) {
            append_vertex(vertexArray, particles, i);
        }
    }
    sfRenderWindow_drawVertexArray(window, vertexArray, NULL);
    sfVertexArray_destroy(vertexArray);
}

void init_particles (particles_t *particles, sfVector2f position)
{
    for (int i = 0; i < 10; i++) {
        int idx = rand() % MAX_PARTICLES;
        if (particles[idx].life <= 0) {
            particles[idx].position = position;
            particles[idx].velocity.x =
                    ((float)rand() / (float)RAND_MAX) * 400.0f - 200.0f;
            particles[idx].velocity.y =
                    ((float)rand() / (float)RAND_MAX) * 400.0f - 200.0f;
            particles[idx].color = (sfColor){150 + rand() % 106, 0, 0, 255};
            particles[idx].life = ((float)rand() / (float)RAND_MAX) * 0.5f;
            particles[idx].size = ((float)rand() / (float)RAND_MAX) * 3.0f;
            particles[idx].gravity = 500.0f;
        }
    }
}

void show_particles(rpg_t *rpg)
{
    float dt = sfTime_asSeconds(sfClock_restart(rpg->game->particles->clock));
    update_particles(rpg->game->particles, dt);
    if (hp_decreased(rpg)) {
        init_particles(rpg->game->particles,
        (sfVector2f){rpg->game->player->position.x + 25,
                    rpg->game->player->position.y + 32});

    }
    draw_particles(rpg->head->window, rpg->game->particles);
}
