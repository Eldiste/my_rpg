/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** move_player.c
*/

#include "rpg.h"

void move_player(player_t *player, float deltaSeconds)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        player->position.x -= player->speed * deltaSeconds;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        player->position.x += player->speed * deltaSeconds;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        player->position.y -= player->speed * deltaSeconds;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        player->position.y += player->speed * deltaSeconds;
    }
}

void update_player_position(player_t *player,
            float deltaSeconds, int** map, float tileSize)
{
    check_collision(player, deltaSeconds, map, tileSize);
}
