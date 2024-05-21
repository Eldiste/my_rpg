/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** init_hero
*/

#include "rpg.h"

hero_sp_t *init_biker(void)
{
    hero_sp_t *hero = malloc(sizeof(hero_sp_t));
    hero->main =
    sfTexture_createFromFile("sprite/champ/Biker/biker.png", NULL);
    hero->main_extra =
    sfTexture_createFromFile("sprite/champ/Biker/biker_extra.png", NULL);
    hero->walk = get_sprite(hero->main);
    return hero;
}

hero_sp_t *init_cyborg(void)
{
    hero_sp_t *hero = malloc(sizeof(hero_sp_t));
    hero->main =
    sfTexture_createFromFile("sprite/champ/Cyborg/cyborg.png", NULL);
    hero->main_extra =
    sfTexture_createFromFile("sprite/champ/Cyborg/cyborg_extra.png", NULL);
    hero->walk = get_sprite(hero->main);
    return hero;
}

hero_sp_t *init_punk(void)
{
    hero_sp_t *hero = malloc(sizeof(hero_sp_t));
    hero->main = sfTexture_createFromFile("sprite/champ/Punk/punk.png", NULL);
    hero->main_extra =
    sfTexture_createFromFile("sprite/champ/Punk/punk_extra.png", NULL);
    hero->walk = get_sprite(hero->main);
    return hero;
}

hero_in_t *init_hero_manage(void)
{
    hero_in_t *hero = malloc(sizeof(hero_in_t));
    hero->biker = init_biker();
    hero->cyborg = init_cyborg();
    hero->punk = init_punk();
    hero->selected = 0;
    return hero;
}
