/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** init_crampteur
*/

#include "rpg.h"

void crampteur_scale(pnjst_t *pnjst)
{
    sfSprite_setPosition(pnjst->tools,
    (sfVector2f){pnjst->position.x - 180, pnjst->position.y - 200});
    sfSprite_setPosition(pnjst->is,
    (sfVector2f){pnjst->position.x + 25, pnjst->position.y - 60});
    sfSprite_setPosition(pnjst->sprite, pnjst->position);
    sfSprite_setTextureRect(pnjst->sprite, pnjst->rect);
    sfSprite_setScale(pnjst->sprite, get_vector(1.5, 1.5));
    sfSprite_setScale(pnjst->tools, get_vector(1, 0.6));
    sfSprite_setScale(pnjst->is, get_vector(0.4, 0.4));
}

void crampteur_sprite(pnjst_t *pnjst)
{
    pnjst->atck =
    init_button_rec(sfTexture_createFromFile("sprite/atck.png", NULL));
    sfSprite_setPosition(pnjst->atck->texture_init,
    (sfVector2f){pnjst->position.x - 130, pnjst->position.y - 125});
    pnjst->def =
    init_button_rec(sfTexture_createFromFile("sprite/def.png", NULL));
    sfSprite_setPosition(pnjst->def->texture_init,
    (sfVector2f){pnjst->position.x - 130, pnjst->position.y - 50});
    pnjst->hp =
    init_button_rec(sfTexture_createFromFile("sprite/hp.png", NULL));
    sfSprite_setPosition(pnjst->hp->texture_init,
    (sfVector2f){pnjst->position.x - 128, pnjst->position.y + 100});
    pnjst->speed =
    init_button_rec(sfTexture_createFromFile("sprite/speed.png", NULL));
    sfSprite_setPosition(pnjst->speed->texture_init,
    (sfVector2f){pnjst->position.x - 130, pnjst->position.y + 20});
    sfSprite_setScale(pnjst->hp->texture_init, get_vector(0.12, 0.12));
}

void crampteur_pos(pnjst_t *pnjst)
{
    pnjst->atck_txt = init_text((sfVector2f){pnjst->position.x - 50,
    pnjst->position.y - 125},
    sfWhite, 35, "xp");
    pnjst->def_txt = init_text((sfVector2f){pnjst->position.x - 50,
    pnjst->position.y - 50},
    sfWhite, 35, "xp");
    pnjst->speed_txt = init_text((sfVector2f){pnjst->position.x - 50,
    pnjst->position.y + 20},
    sfWhite, 35, "xp");
    pnjst->hp_txt = init_text((sfVector2f){pnjst->position.x - 50,
    pnjst->position.y + 100},
    sfWhite, 35, "xp");
    pnjst->is_txt = init_text((sfVector2f){pnjst->position.x + 50,
    pnjst->position.y - 50},
    sfWhite, 15, "Here the crampteur\npress 'F'\nto open your skills tree");
}

pnjst_t *init_crampteur(char *path, sfVector2f pos)
{
    pnjst_t *pnjst = malloc(sizeof(pnjst_t));
    pnjst->sprite = get_sprite(sfTexture_createFromFile(path, NULL));
    pnjst->font = sfTexture_createFromFile
    ("sprite/cadre.png", NULL);
    pnjst->tools = get_sprite(pnjst->font);
    pnjst->is = get_sprite(pnjst->font);
    sfSprite_setTextureRect(pnjst->tools, get_rect(0, 0, 375, 720));
    sfSprite_setTextureRect(pnjst->is, get_rect(485, 610, 540, 205));
    pnjst->rect = (sfIntRect){0, 0, 30, 45};
    pnjst->position = pos;
    crampteur_scale(pnjst);
    crampteur_sprite(pnjst);
    crampteur_pos(pnjst);
    return pnjst;
}
