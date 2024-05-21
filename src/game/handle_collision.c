/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** handle_collision.c
*/

#include "rpg.h"

int is_collidable(int tile)
{
    int collidable_tiles[] = {UPPER_LEFT_CORNER, LATERAL_UPPER_BAR,
                            UPPER_RIGHT_CORNER, INSIDE_BOTTOM_RIGHT_CORNER,
                            INSIDE_BOTTOM_LEFT_CORNER, VERTICAL_LEFT_BAR,
                            INSIDE_BLOCK, VERTICAL_RIGHT_BAR,
                            INSIDE_UP_RIGHT_CORNER, INSIDE_UP_LEFT_CORNER,
                            DOWN_LEFT_CORNER, LATERAL_DOWN_BAR,
                            DOWN_RIGHT_CORNER, FULL_BLOCK};
    int num_collidable_tiles =
        sizeof(collidable_tiles) / sizeof(collidable_tiles[0]);

    for (int i = 0; i < num_collidable_tiles; i++) {
        if (tile == collidable_tiles[i]) {
            return 1;
        }
    }
    return 0;
}

int collision_detector(int** map, sfFloatRect player_rect, float tileSize,
                        sfVector2i tile)
{
    if (is_collidable(map[tile.y][tile.x])) {
        sfFloatRect tile_rect =
        {tile.x * tileSize, tile.y * tileSize, tileSize, tileSize};
        if (sfFloatRect_intersects(&player_rect, &tile_rect, NULL))
            return 1;
    }
    return 0;
}

int is_colliding(int** map, sfFloatRect player_rect, float tileSize)
{
    int grid_left = (int)(player_rect.left / tileSize) - 1;
    int grid_top = (int)(player_rect.top / tileSize) - 1;
    int grid_right = (int)((player_rect.left + player_rect.width) /
                                                        tileSize) + 1;
    int grid_bottom = (int)((player_rect.top + player_rect.height) /
                                                        tileSize) + 1;
    int collision = 0;
    for (int y = grid_top; y <= grid_bottom && !collision; y++) {
        for (int x = grid_left; x <= grid_right && !collision; x++) {
            collision = collision_detector(map, player_rect, tileSize,
                                                    (sfVector2i){x, y});
        }
    }
    return collision;
}

void check_collision(player_t *player, float deltaSeconds,
                                    int** map, float tileSize)
{
    sfVector2f old_position = player->position;
    sfVector2f new_position;
    move_player(player, deltaSeconds);
    sfFloatRect player_rect = {player->position.x, player->position.y, 30, 45};
    new_position = player->position;
    new_position.y = old_position.y;
    player_rect.left = new_position.x;
    player_rect.top = new_position.y;
    if (is_colliding(map, player_rect, tileSize)) {
        player->position.x = old_position.x;
    }
    new_position = player->position;
    new_position.x = old_position.x;
    player_rect.left = new_position.x;
    player_rect.top = new_position.y;
    if (is_colliding(map, player_rect, tileSize)) {
        player->position.y = old_position.y;
    }
}
