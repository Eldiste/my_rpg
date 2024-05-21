/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** random_map.c
*/

#include "rpg.h"

void place_texture(int** map, sfVector2i size)
{
    int **original_map = copy_map(map, size);

    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            map[y][x] == 1 ? place_corners(map, original_map,
                        (sfVector2i){x, y}, size) : 0;
            map[y][x] == 0 ? map[y][x] = 2 : 0;
        }
    }
    free_map(original_map, size.y);
}

int get_neighbor_count(int** map, int x, int y, sfVector2i size)
{
    int count = 0;
    int offsets[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                        {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (int i = 0; i < 8; i++) {
        int newX = x + offsets[i][0];
        int newY = y + offsets[i][1];
        if (newX < 0 || newY < 0 || newX >= size.x ||
                newY >= size.y || map[newY][newX] == 1) {
            count++;
        }
    }
    return count;
}

void cellular_automata(int** map, sfVector2i size)
{
    int** newMap = (int**)malloc(size.y * sizeof(int*));

    for (int y = 0; y < size.y; y++) {
        newMap[y] = (int*)malloc(size.x * sizeof(int));
        for (int x = 0; x < size.x; x++) {
            int neighbors = get_neighbor_count(map, x, y,
                                (sfVector2i){size.x, size.y});
            map[y][x] == 1 ? (newMap[y][x] = (neighbors >= 4) ? 1 : 0) : 0;
            map[y][x] != 1 ? (newMap[y][x] = (neighbors >= 5) ? 1 : 0) : 0;
        }
    }
    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            map[y][x] = newMap[y][x];
        }
    }
    free_map(newMap, size.y);
}

int **place_tile(int **map, sfVector2i size, sfVector2i pos, int wallPercentage)
{
    if (pos.x == 0 || pos.x == size.x - 1 ||
            pos.y == 0 || pos.y == size.y - 1) {
        map[pos.y][pos.x] = 1;
    } else if (random_int(0, 100) < wallPercentage) {
        map[pos.y][pos.x] = 1;
    } else {
        map[pos.y][pos.x] = 0;
    }
    return map;
}

int** procedural_map(sfVector2i size, int wallPercentage, int iterations)
{
    srand(time(NULL));
    int** map = (int**)malloc(size.y * sizeof(int*));
    for (int y = 0; y < size.y; y++) {
        map[y] = (int*)malloc(size.x * sizeof(int));
        for (int x = 0; x < size.x; x++) {
            map = place_tile(map, size, (sfVector2i){x, y}, wallPercentage);
        }
    }
    for (int i = 0; i < iterations; i++) {
        cellular_automata(map, (sfVector2i){size.x, size.y});
    }
    create_lobby(map, (sfVector2i){size.x, size.y}, (sfVector2i){15, 10});
    place_texture(map, (sfVector2i){size.x, size.y});
    return map;
}
