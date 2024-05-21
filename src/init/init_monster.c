/*
** EPITECH PROJECT, 2023
** init_monster
** File description:
** init_monster
*/

#include "rpg.h"

monster_sp_t init_monster4(monster_sp_t monster)
{
    monster.main =
    sfTexture_createFromFile("sprite/monster/monster4.png", NULL);
    monster.walk = get_sprite(monster.main);
    monster.clock = sfClock_create();
    monster.clock_1 = sfClock_create();
    monster.clock_2 = sfClock_create();
    monster.dead = 0;
    monster.rect = get_rect(0, 0, 70, 70);
    monster.top_less = 0;
    monster.back = 48;
    monster.spawn_time = 1;
    monster.lenx = 3;
    monster.leny = 50;
    monster.nb_monster = 0;
    monster.life = 5;
    monster.left = 85;
    monster.boss = 0;
    return monster;
}

monster_sp_t init_monster3(monster_sp_t monster)
{
    monster.main =
    sfTexture_createFromFile("sprite/monster/monster3.png", NULL);
    monster.walk = get_sprite(monster.main);
    monster.clock = sfClock_create();
    monster.clock_1 = sfClock_create();
    monster.dead = 0;
    monster.rect = get_rect(0, 0, 70, 70);
    monster.back = 48;
    monster.spawn_time = 1;
    monster.top_less = 0;
    monster.lenx = 2;
    monster.leny = 50;
    monster.nb_monster = 0;
    monster.left = 70;
    monster.life = 3;
    monster.boss = 0;
    return monster;
}

monster_sp_t init_monster2(monster_sp_t monster)
{
    monster.main =
    sfTexture_createFromFile("sprite/monster/monster2.png", NULL);
    monster.walk = get_sprite(monster.main);
    monster.clock = sfClock_create();
    monster.clock_1 = sfClock_create();
    monster.dead = 0;
    monster.rect = get_rect(0, 0, 70, 70);
    monster.top_less = 10;
    monster.back = 60;
    monster.spawn_time = 1;
    monster.left = 70;
    monster.life = 20;
    monster.lenx = 5;
    monster.nb_monster = 0;
    monster.leny = 40;
    monster.boss = 1;
    return monster;
}

monster_sp_t init_monster1(monster_sp_t monster)
{
    monster.main =
    sfTexture_createFromFile("sprite/monster/monster1.png", NULL);
    monster.walk = get_sprite(monster.main);
    monster.clock = sfClock_create();
    monster.clock_1 = sfClock_create();
    monster.dead = 0;
    monster.rect = get_rect(0, 0, 70, 70);
    monster.top_less = 0;
    monster.back = 48;
    monster.spawn_time = 1;
    monster.lenx = 5;
    monster.leny = 50;
    monster.left = 70;
    monster.boss = 0;
    monster.nb_monster = 0;
    monster.life = 1;
    return monster;
}

monster_in_t *init_monster_manage(void)
{
    monster_in_t *monster = malloc(sizeof(monster_in_t) * 10);
    monster->nb_monster = 0;
    monster->spawn1 = 0;
    monster->spawn2 = 0;
    monster->spawn3 = 0;
    monster->spawn4 = 0;
    for (int i = 0; i < 1; i++) {
        monster[i].monster1 = malloc(sizeof(monster_sp_t) * 100);
        monster[i].monster2 = malloc(sizeof(monster_sp_t) * 100);
        monster[i].monster3 = malloc(sizeof(monster_sp_t) * 100);
        monster[i].monster4 = malloc(sizeof(monster_sp_t) * 100);
        for (int j = 0; j < 100; j++) {
            monster[i].monster1[j] = init_monster1(monster[i].monster1[j]);
            monster[i].monster2[j] = init_monster2(monster[i].monster2[j]);
            monster[i].monster3[j] = init_monster3(monster[i].monster3[j]);
            monster[i].monster4[j] = init_monster4(monster[i].monster4[j]);
        }
    } return monster;
}
