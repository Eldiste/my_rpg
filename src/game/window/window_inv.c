/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** window_inv
*/

#include "rpg.h"

void window_inv_hero(rpg_t *rpg, sfVector2f healthBarPos)
{
    if (rpg->hero->selected == BIKER)
        rpg->game->inv->hero = sfSprite_copy(rpg->hero->biker->walk);
    if (rpg->hero->selected == PUNK)
        rpg->game->inv->hero = sfSprite_copy(rpg->hero->punk->walk);
    if (rpg->hero->selected == CYBORG)
        rpg->game->inv->hero = sfSprite_copy(rpg->hero->cyborg->walk);
    sfSprite_setPosition(rpg->game->inv->hero,
    (sfVector2f){healthBarPos.x + 320, healthBarPos.y + 35});
    sfSprite_setScale(rpg->game->inv->hero, (sfVector2f){5, 5});
    sfRenderWindow_drawSprite(rpg->head->window, rpg->game->inv->hero, NULL);
}

void window_inv_setstr_addon(rpg_t *rpg, sfVector2f healthBarPos)
{
    rpg->game->inv->def->str = my_strcat("DEF : ",
    my_int_to_strnum(rpg->game->skills->def->def));
    get_text(rpg, rpg->game->inv->def);
    set_text_position(rpg->game->inv->def,
    (sfVector2f){healthBarPos.x + 535, healthBarPos.y + 120});
    rpg->game->inv->speed->str = my_strcat("SPEED : ",
    my_int_to_strnum(rpg->game->player->speed));
    get_text(rpg, rpg->game->inv->speed);
    set_text_position(rpg->game->inv->speed,
    (sfVector2f){healthBarPos.x + 535, healthBarPos.y + 160});
}

void window_inv_setstr(rpg_t *rpg, sfVector2f healthBarPos)
{
    rpg->game->inv->hp->str = my_strcat("HP : ",
    my_strcat(my_strcat(my_int_to_strnum(rpg->game->skills->hp->hp), "/"),
    my_int_to_strnum(rpg->game->skills->hp->hp_max)));
    get_text(rpg, rpg->game->inv->hp);
    set_text_position(rpg->game->inv->hp,
    (sfVector2f){healthBarPos.x + 535, healthBarPos.y + 40});
    rpg->game->inv->xp->str = my_strcat("XP : ",
    my_strcat(my_strcat(my_int_to_strnum(rpg->game->skills->xp->xp), "/"),
    my_int_to_strnum(rpg->game->skills->xp->xp_max)));
    get_text(rpg, rpg->game->inv->xp);
    set_text_position(rpg->game->inv->xp,
    (sfVector2f){healthBarPos.x + 535, healthBarPos.y + 200});
    rpg->game->inv->atck->str = my_strcat("ATCK : ",
    my_int_to_strnum(rpg->game->skills->atck->atck));
    get_text(rpg, rpg->game->inv->atck);
    set_text_position(rpg->game->inv->atck,
    (sfVector2f){healthBarPos.x + 535, healthBarPos.y + 80});
    window_inv_setstr_addon(rpg, healthBarPos);
}

void window_inv(rpg_t *rpg)
{
    rpg->head->view_pos = sfView_getCenter(rpg->head->new_view);
    rpg->head->view_size = sfView_getSize(rpg->head->new_view);
    sfVector2f healthBarPos = {rpg->head->view_pos.x -
    rpg->head->view_size.x / 2, rpg->head->view_pos.y -
    rpg->head->view_size.y / 2};
    sfSprite_setPosition(rpg->game->inv->main,
    (sfVector2f){healthBarPos.x + 250, healthBarPos.y + 25});
    sfSprite_setScale(rpg->game->inv->main, (sfVector2f){2.7, 2.7});
    sfRenderWindow_drawSprite(rpg->head->window, rpg->game->inv->main, NULL);
    window_inv_hero(rpg, healthBarPos); window_inv_setstr(rpg, healthBarPos);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->inv->hp->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->inv->xp->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->inv->atck->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->inv->def->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->inv->speed->text, NULL);
}
