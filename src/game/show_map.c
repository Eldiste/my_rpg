/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** show_map.c
*/

#include "rpg.h"

void update_map_view(rpg_t *rpg)
{
    sfVector2f viewSize = sfView_getSize(rpg->head->new_view);
    sfVector2f viewCenter = sfView_getCenter(rpg->head->new_view);
    sfVector2f topLeft = {viewCenter.x - viewSize.x / 2,
                                viewCenter.y - viewSize.y / 2};
    sfVector2f bottomRight = {viewCenter.x + viewSize.x / 2,
                                viewCenter.y + viewSize.y / 2};
    int startCol = fmax(0, topLeft.x / MAP->tileSize);
    int endCol = fmin(MAP->gridWidth, ceil(bottomRight.x / MAP->tileSize));
    int startRow = fmax(0, topLeft.y / MAP->tileSize);
    int endRow = fmin(MAP->gridHeight, ceil(bottomRight.y / MAP->tileSize));
    sfVertexArray_clear(MAP->vertexArray);
    for (int x = startCol; x < endCol; x++) {
        for (int y = startRow; y < endRow; y++) {
            int tileIndex = MAP->map[y][x];
            int tileX = tileIndex % 32;
            int tileY = tileIndex / 32;
            create_quad(MAP->vertexArray, (sfVector2f){x * MAP->tileSize, y *
                    MAP->tileSize}, MAP->tileSize, (sfVector2f){tileX, tileY});
        }
    }
}

void show_map(rpg_t *rpg)
{
    sfTime deltaTime = sfClock_restart(rpg->game->clock);
    float deltaSeconds = sfTime_asSeconds(deltaTime);
    if (rpg->hero->selected == BIKER) {
        update_player_position(rpg->game->player, deltaSeconds,
                                        MAP->map, MAP->tileSize);
    } if (rpg->hero->selected == PUNK) {
        update_player_position(rpg->game->player, deltaSeconds,
                                        MAP->map, MAP->tileSize);
    } if (rpg->hero->selected == CYBORG) {
        update_player_position(rpg->game->player, deltaSeconds,
                                        MAP->map, MAP->tileSize);
    }
    sfView_setCenter(rpg->head->new_view, rpg->game->player->position);
    update_map_view(rpg);
    sfRenderWindow_setView(rpg->head->window, rpg->head->new_view);
    sfRenderWindow_drawVertexArray(rpg->head->window, MAP->vertexArray,
                                                    &MAP->renderStates);
}
