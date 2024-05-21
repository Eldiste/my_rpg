/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** init_map.c
*/

#include "rpg.h"

void create_quad(sfVertexArray* vertexArray, sfVector2f coord,
                                float tileSize, sfVector2f tile)
{
    float texX = tile.x * tileSize;
    float texY = tile.y * tileSize;
    sfVertex vertices[] = {
        { { coord.x, coord.y }, sfWhite, { texX, texY } },
        { { coord.x + tileSize, coord.y }, sfWhite, { texX + tileSize, texY } },
        { { coord.x + tileSize, coord.y + tileSize },
                                sfWhite, { texX + tileSize, texY + tileSize } },
        { { coord.x, coord.y + tileSize }, sfWhite, { texX, texY + tileSize } },
    };
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(vertexArray, vertices[i]);
}

void init_game2(game_t *game)
{
    game->clock = sfClock_create();
    game->view = sfView_create();
    game->settings = 0;
    game->inv_st = 0;
    sfView_setCenter(game->view, (sfVector2f){960, 540});
    sfView_setSize(game->view, (sfVector2f){1920, 1080});
    game->player->speed = 100.0f;
    game->esc = init_esc();
    game->inv = init_inv();
    game->pnj = init_pnj();
    game->death = init_text((sfVector2f){GRID_WIDTH * TILE_SIZE / 2 - 120,
    GRID_HEIGHT * TILE_SIZE / 2 - 80},
    sfRed, 80, "GAME OVER");
}

game_t* init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->skills = init_skills();
    game->map = malloc(sizeof(map_t));
    game->player = malloc(sizeof(player_t));
    game->particles = malloc(sizeof(particles_t) * MAX_PARTICLES);
    game->particles->clock = sfClock_create();
    initialize_all_particles(game->particles);
    sfTexture *player_texture = sfTexture_createFromFile("sprite/bg.png", NULL);
    game->player->status = 0;
    game->anim_ack = 0;
    game->player->sprite = sfSprite_create();
    sfSprite_setTexture(game->player->sprite, player_texture, sfTrue);
    sfSprite_setTextureRect(game->player->sprite, (sfIntRect){0, 0, 30, 45});
    game->player->position = (sfVector2f){GRID_WIDTH * TILE_SIZE / 2 - 15,
                                        GRID_HEIGHT * TILE_SIZE / 2 - 22.5};
    sfSprite_setPosition(game->player->sprite, game->player->position);
    game->map->is_generated = sfFalse;
    init_game2(game);
    return game;
}

void generate_map(game_t *game)
{
    game->map->texture = sfTexture_createFromFile("sprite/tiles/Tiles.png",
                                                                        NULL);
    game->map->vertexArray = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(game->map->vertexArray, sfQuads);
    game->map->renderStates.texture = game->map->texture;
    game->map->renderStates.blendMode = sfBlendAlpha;
    game->map->renderStates.transform = sfTransform_Identity;
    game->map->renderStates.shader = NULL;
    game->map->tileSize = TILE_SIZE;
    game->map->gridWidth = GRID_WIDTH;
    game->map->gridHeight = GRID_HEIGHT;
    game->map->wallPercentage = WALL_PERCENTAGE;
    game->map->iterations = ITERATIONS;
    game->map->map = procedural_map(
        (sfVector2i){game->map->gridWidth, game->map->gridHeight},
                game->map->wallPercentage, game->map->iterations);
    game->map->is_generated = sfTrue;
}
