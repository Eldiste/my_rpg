/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** skills_main
*/

#include "rpg.h"

void algo_tp(rpg_t *rpg)
{
    if (rpg->game->inv->tp_left > 0) {
        rpg->game->player->position = (sfVector2f){GRID_WIDTH * TILE_SIZE / 2,
        GRID_HEIGHT * TILE_SIZE / 2};
        rpg->game->inv->tp_left--;
    }
}

void algo_pot(rpg_t *rpg)
{
    if (rpg->game->inv->potion_left > 0) {
        if (rpg->game->skills->hp->hp + 25 > rpg->game->skills->hp->hp_max) {
            rpg->game->skills->hp->hp = rpg->game->skills->hp->hp_max;
            rpg->game->inv->potion_left--;
        } else {
            rpg->game->skills->hp->hp += 25;
            rpg->game->inv->potion_left--;
        }
    }
}

void tp_dr(rpg_t *rpg)
{
    sfVector2f healthBarPos = {rpg->head->view_pos.x -
    rpg->head->view_size.x / 2, rpg->head->view_pos.y -
    rpg->head->view_size.y / 2};
    rpg->game->inv->tp_txt->str =
    my_strcat("x ", my_int_to_strnum(rpg->game->inv->tp_left));
    get_text(rpg, rpg->game->inv->tp_txt);
    set_text_position(rpg->game->inv->tp_txt,
    (sfVector2f){healthBarPos.x + 880, healthBarPos.y + 440});
    sfSprite_setScale(rpg->game->inv->tp->texture_init,
    (sfVector2f){0.07, 0.07});
    sfSprite_setPosition(rpg->game->inv->tp->texture_init,
    (sfVector2f){healthBarPos.x + 855, healthBarPos.y + 440});
    rpg->game->inv->tp->rect =
    sfSprite_getGlobalBounds(rpg->game->inv->tp->texture_init);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->inv->tp->texture_init, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->inv->tp_txt->text, NULL);
}

void potion_dr(rpg_t *rpg)
{
    sfVector2f healthBarPos = {rpg->head->view_pos.x -
    rpg->head->view_size.x / 2, rpg->head->view_pos.y -
    rpg->head->view_size.y / 2};
    rpg->game->inv->poition_txt->str =
    my_strcat("x ", my_int_to_strnum(rpg->game->inv->potion_left));
    get_text(rpg, rpg->game->inv->poition_txt);
    set_text_position(rpg->game->inv->poition_txt,
    (sfVector2f){healthBarPos.x + 880, healthBarPos.y + 485});
    sfSprite_setPosition(rpg->game->inv->potion->texture_init,
    (sfVector2f){healthBarPos.x + 850, healthBarPos.y + 485});
    rpg->game->inv->potion->rect =
    sfSprite_getGlobalBounds(rpg->game->inv->potion->texture_init);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->inv->potion->texture_init, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->inv->poition_txt->text, NULL);
}

void skills_main(rpg_t *rpg)
{
    rpg->head->view_pos = sfView_getCenter(rpg->head->new_view);
    rpg->head->view_size = sfView_getSize(rpg->head->new_view);
    xp_manage(rpg);
    hp_manage(rpg);
    coin_manage(rpg);
    algo_quest(rpg);
    potion_dr(rpg);
    tp_dr(rpg);
    get_text(rpg, rpg->game->pnj->crampteur->is_txt);
    get_text(rpg, rpg->game->pnj->quest->is_txt);
}
