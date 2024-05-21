/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** map_utils.c
*/

#include "rpg.h"

void free_map(int** map, int size)
{
    for (int i = 0; i < size; i++) {
        free(map[i]);
    }
    free(map);
}

int random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int **copy_map(int **map, sfVector2i size)
{
    int **new_map = (int **)malloc(size.y * sizeof(int *));
    for (int i = 0; i < size.y; i++) {
        new_map[i] = (int *)malloc(size.x * sizeof(int));
        for (int j = 0; j < size.x; j++) {
            new_map[i][j] = map[i][j];
        }
    }
    return new_map;
}
