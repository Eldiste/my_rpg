/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** place_tiles.c
*/

#include "rpg.h"

void create_lobby(int** map, sfVector2i size, sfVector2i lobbySize)
{
    int startX = (size.x - lobbySize.x) / 2;
    int startY = (size.y - lobbySize.y) / 2;

    for (int y = startY; y < startY + lobbySize.y; y++) {
        for (int x = startX; x < startX + lobbySize.x; x++) {
            map[y][x] = 4 + 4 * 32;
        }
    }
}

void init_corner_info(corner_info_t *info, int **original_map,
                                sfVector2i tile, sfVector2i size)
{
    info->up = tile.y > 0 &&
                    original_map[tile.y - 1][tile.x] == 0;
    info->down = tile.y < size.y - 1 &&
                    original_map[tile.y + 1][tile.x] == 0;
    info->left = tile.x > 0 &&
                    original_map[tile.y][tile.x - 1] == 0;
    info->right = tile.x < size.x - 1 &&
                    original_map[tile.y][tile.x + 1] == 0;
    info->up_left = tile.y > 0 && tile.x > 0 &&
                    original_map[tile.y - 1][tile.x - 1] == 0;
    info->up_right = tile.y > 0 && tile.x < size.x - 1 &&
                    original_map[tile.y - 1][tile.x + 1] == 0;
    info->down_left = tile.y < size.y - 1 && tile.x > 0 &&
                    original_map[tile.y + 1][tile.x - 1] == 0;
    info->down_right = tile.y < size.y - 1 && tile.x < size.x - 1 &&
                    original_map[tile.y + 1][tile.x + 1] == 0;
}

int get_tile_type_next(corner_info_t *info)
{
    if (!info->up && !info->right && !info->left &&
                            !info->down && info->down_right)
        return INSIDE_BOTTOM_RIGHT_CORNER;
    if (!info->up && !info->right && !info->left &&
                            !info->down && info->up_left)
        return INSIDE_UP_LEFT_CORNER;
    if (!info->up && !info->right && !info->left &&
                            !info->down && info->up_right)
        return INSIDE_UP_RIGHT_CORNER;
    if (!info->up && !info->left && !info->down && !info->right)
        return INSIDE_BLOCK;
    return FULL_BLOCK;
}

int get_tile_type(corner_info_t *info)
{
    if (info->up && info->left && !info->down && !info->right)
        return UPPER_LEFT_CORNER;
    if (info->up && !info->left && !info->down && info->right)
        return UPPER_RIGHT_CORNER;
    if (!info->up && info->left && info->down && !info->right)
        return DOWN_LEFT_CORNER;
    if (!info->up && !info->left && info->down && info->right)
        return DOWN_RIGHT_CORNER;
    if (info->up && !info->left && !info->down && !info->right)
        return LATERAL_UPPER_BAR;
    if (!info->up && !info->left && info->down && !info->right)
        return LATERAL_DOWN_BAR;
    if (!info->up && info->left && !info->down && !info->right)
        return VERTICAL_LEFT_BAR;
    if (!info->up && !info->left && !info->down && info->right)
        return VERTICAL_RIGHT_BAR;
    if (!info->up && !info->right && !info->left &&
                            !info->down && info->down_left)
        return INSIDE_BOTTOM_LEFT_CORNER;
    return get_tile_type_next(info);
}

void place_corners(int **map, int **original_map,
                    sfVector2i tile, sfVector2i size)
{

    corner_info_t info;
    init_corner_info(&info, original_map, tile, size);

    map[tile.y][tile.x] = get_tile_type(&info);
}
