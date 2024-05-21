/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** init_pnj
*/

#include "rpg.h"

quest_t *init_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));
    quest->kill = 0;
    quest->kill_obj = 10;
    quest->earn = 0;
    quest->earn_obj = 5;
    quest->final = 0;
    return quest;
}

button_t *init_button_rec(sfTexture *init)
{
    button_t *button = malloc(sizeof(button_t));
    button->texture_init = get_sprite(init);
    button->st = 0;
    return button;
}

void init_pnj_txt(pnj_t *pnj)
{
    pnj->price_txt = init_text((sfVector2f){pnj->crampteur->position.x - 20,
    pnj->crampteur->position.y + 170},
    sfWhite, 35, "xp");
    pnj->skills_tree = init_text((sfVector2f){pnj->crampteur->position.x - 75,
    pnj->crampteur->position.y - 190},
    sfWhite, 45, "Skills Tree");
    pnj->current = init_text((sfVector2f){pnj->quest->position.x - 55,
    pnj->quest->position.y - 190},
    sfWhite, 45, "Quests");
}

pnj_t *init_pnj(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    pnj->crampteur =
    init_crampteur("sprite/pnj/crampteur.png",
    (sfVector2f){GRID_WIDTH * TILE_SIZE / 2 - 15,
    GRID_HEIGHT * TILE_SIZE / 2 - 22.5});
    pnj->quest =
    init_pnjst_quest("sprite/pnj/quest.png",
    (sfVector2f){GRID_WIDTH * TILE_SIZE / 2 - 200, GRID_HEIGHT *
    TILE_SIZE / 2 - 22.5});
    pnj->intertaction =
    get_sprite(sfTexture_createFromFile("sprite/interact.png", NULL));
    init_pnj_txt(pnj);
    pnj->obj = init_quest();
    pnj->intertaction_rect = get_rect(0, 0, 32, 32);
    pnj->price = 5;
    pnj->isKeyPressed = sfFalse;
    return pnj;
}
