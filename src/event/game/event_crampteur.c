/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_crampteur
*/

#include "my.h"
#include "rpg.h"

void attack_clicked(rpg_t *rpg, sfBool *button_pressed)
{
    if (is_clicked(rpg, rpg->game->pnj->crampteur->atck) && rpg->bg->st == 5) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed
            && !(*button_pressed)) {
            atck_algo(rpg);
            *button_pressed = sfTrue;
        }
        rpg->game->pnj->crampteur->atck_txt->color = sfMagenta;
        sfSprite_setColor(rpg->game->pnj->crampteur->atck->texture_init,
        sfMagenta);
    } else {
        rpg->game->pnj->crampteur->atck_txt->color = sfWhite;
        sfSprite_setColor(rpg->game->pnj->crampteur->atck->texture_init,
        sfWhite);
    }
}

void defense_clicked(rpg_t *rpg, sfBool *button_pressed)
{
    if (is_clicked(rpg, rpg->game->pnj->crampteur->def) && rpg->bg->st == 5) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed
            && !(*button_pressed)) {
            def_algo(rpg);
            *button_pressed = sfTrue;
        }
        rpg->game->pnj->crampteur->def_txt->color = sfMagenta;
        sfSprite_setColor(rpg->game->pnj->crampteur->def->texture_init,
        sfMagenta);
    } else {
        rpg->game->pnj->crampteur->def_txt->color = sfWhite;
        sfSprite_setColor(rpg->game->pnj->crampteur->def->texture_init,
        sfWhite);
    }
}

void speed_clicked(rpg_t *rpg, sfBool *button_pressed)
{
    if (is_clicked(rpg, rpg->game->pnj->crampteur->speed)
        && rpg->bg->st == 5) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed
            && !(*button_pressed)) {
            speed_algo(rpg);
            *button_pressed = sfTrue;
        }
        rpg->game->pnj->crampteur->speed_txt->color = sfMagenta;
        sfSprite_setColor(rpg->game->pnj->crampteur->speed->texture_init,
        sfMagenta);
    } else {
        rpg->game->pnj->crampteur->speed_txt->color = sfWhite;
        sfSprite_setColor(rpg->game->pnj->crampteur->speed->texture_init,
        sfWhite);
    }
}

void hp_clicked(rpg_t *rpg, sfBool *button_pressed)
{
    if (is_clicked(rpg, rpg->game->pnj->crampteur->hp)
        && rpg->bg->st == 5) {
        if (rpg->head->event.type == sfEvtMouseButtonPressed
            && !(*button_pressed)) {
            hp_algo(rpg);
            *button_pressed = sfTrue;
        }
        rpg->game->pnj->crampteur->hp_txt->color = sfMagenta;
        sfSprite_setColor(rpg->game->pnj->crampteur->hp->texture_init,
        sfMagenta);
    } else {
        rpg->game->pnj->crampteur->hp_txt->color = sfWhite;
        sfSprite_setColor(rpg->game->pnj->crampteur->hp->texture_init,
        sfWhite);
    }
}

void event_crampteur(rpg_t *rpg)
{
    static sfBool button_pressed = sfFalse;

    attack_clicked(rpg, &button_pressed);
    defense_clicked(rpg, &button_pressed);
    speed_clicked(rpg, &button_pressed);
    hp_clicked(rpg, &button_pressed);

    if (rpg->head->event.type == sfEvtMouseButtonReleased) {
        button_pressed = sfFalse;
    }
}
