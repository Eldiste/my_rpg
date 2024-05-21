/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** init_skills
*/

#include "rpg.h"

atck_t *init_atck(void)
{
    atck_t *atck = malloc(sizeof(atck_t));
    atck->atck_st = init_text((sfVector2f){0, 0},
    sfWhite, 22, "100/100");
    atck->atck = 5;
    atck->status = 0;
    return atck;
}

def_t *def_init(void)
{
    def_t *def = malloc(sizeof(def_t));
    def->def_st = init_text((sfVector2f){0, 0},
    sfWhite, 22, "100/100");
    def->def = 5;
    def->status = 0;
    return def;
}

hp_t *init_hp(void)
{
    hp_t *hp = malloc(sizeof(hp_t));
    hp->hp_rect = sfRectangleShape_create();
    hp->hp_rect_base = sfRectangleShape_create();
    sfRectangleShape_setFillColor(hp->hp_rect_base,
    (sfColor){35, 35, 35, 255});
    sfRectangleShape_setSize(hp->hp_rect_base, (sfVector2f){200, 15});
    hp->hp_st = init_text((sfVector2f){0, 0},
    sfWhite, 22, "100/100");
    hp->hp_max = 100;
    hp->hp = 100;
    hp->status = 0;
    return hp;
}

coins_t *init_coins(void)
{
    coins_t *coins = malloc(sizeof(coins_t));
    coins->sprite =
    get_sprite(sfTexture_createFromFile("sprite/coin.png", NULL));
    coins->coins_txt = init_text((sfVector2f){0, 0},
    sfWhite, 25, "100/100");
    coins->coins = 0;
    coins->rect = get_rect(0, 0, 147, 165);
    return coins;
}

skills_t *init_skills(void)
{
    skills_t *skills = malloc(sizeof(skills_t));
    skills->hp = init_hp();
    skills->xp = init_xp();
    skills->atck = init_atck();
    skills->def = def_init();
    skills->coins = init_coins();
    return skills;
}
