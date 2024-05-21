/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** window_npc
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void window_quest_dr(rpg_t *rpg)
{
    get_text(rpg, rpg->game->pnj->current);
    get_text(rpg, rpg->game->pnj->quest->atck_txt);
    get_text(rpg, rpg->game->pnj->quest->def_txt);
    get_text(rpg, rpg->game->pnj->quest->speed_txt);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->pnj->quest->atck_txt->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->pnj->quest->def_txt->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->pnj->quest->speed_txt->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->pnj->current->text, NULL);
}

void window_crampteur_dr(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->pnj->crampteur->atck->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->pnj->crampteur->def->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->pnj->crampteur->hp->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->pnj->crampteur->speed->texture_init, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->pnj->crampteur->atck_txt->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->pnj->crampteur->def_txt->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->pnj->crampteur->speed_txt->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->pnj->crampteur->hp_txt->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->pnj->price_txt->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->pnj->skills_tree->text, NULL);
}

void window_crampteur_settxt(rpg_t *rpg)
{
    rpg->game->pnj->crampteur->atck_txt->str =
    my_strcat("ATCK : ", my_int_to_strnum(rpg->game->skills->atck->atck));
    rpg->game->pnj->crampteur->def_txt->str =
    my_strcat("DEF : ", my_int_to_strnum(rpg->game->skills->def->def));
    rpg->game->pnj->crampteur->speed_txt->str =
    my_strcat("SPEED : ", my_int_to_strnum(rpg->game->player->speed));
    rpg->game->pnj->crampteur->hp_txt->str =
    my_strcat("MAX HP : ", my_int_to_strnum(rpg->game->skills->hp->hp_max));
    rpg->game->pnj->price_txt->str =
    my_strcat("PRICE : ", my_int_to_strnum(rpg->game->pnj->price));
    get_text(rpg, rpg->game->pnj->crampteur->atck_txt);
    get_text(rpg, rpg->game->pnj->crampteur->def_txt);
    get_text(rpg, rpg->game->pnj->crampteur->speed_txt);
    get_text(rpg, rpg->game->pnj->crampteur->hp_txt);
    get_text(rpg, rpg->game->pnj->price_txt);
    get_text(rpg, rpg->game->pnj->skills_tree);
}

void window_crampteur(rpg_t *rpg)
{
    rpg->game->pnj->crampteur->atck->rect =
    sfSprite_getGlobalBounds(rpg->game->pnj->crampteur->atck->texture_init);
    rpg->game->pnj->crampteur->def->rect =
    sfSprite_getGlobalBounds(rpg->game->pnj->crampteur->def->texture_init);
    rpg->game->pnj->crampteur->speed->rect =
    sfSprite_getGlobalBounds(rpg->game->pnj->crampteur->speed->texture_init);
    rpg->game->pnj->crampteur->hp->rect =
    sfSprite_getGlobalBounds(rpg->game->pnj->crampteur->hp->texture_init);
    event_crampteur(rpg);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->pnj->crampteur->tools, NULL);
    window_crampteur_settxt(rpg);
    window_crampteur_dr(rpg);

}

void window_quest(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->game->pnj->quest->tools, NULL);
    if (rpg->game->pnj->obj->final == 1) {
        rpg->game->pnj->quest->speed_txt->color = sfGreen;
    } rpg->game->pnj->quest->atck_txt->str =
    my_strcat(my_strcat(my_strcat("Kill ",
    my_int_to_strnum(rpg->game->pnj->obj->kill)),
    my_strcat("/", my_int_to_strnum(rpg->game->pnj->obj->kill_obj))),
    " enemies");
    rpg->game->pnj->quest->def_txt->str =
    my_strcat(my_strcat(my_strcat("Collects ",
    my_int_to_strnum(rpg->game->pnj->obj->earn)),
    my_strcat("/", my_int_to_strnum(rpg->game->pnj->obj->earn_obj))),
    " coins");
    window_quest_dr(rpg);
}
