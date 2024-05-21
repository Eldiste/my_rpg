/*
** EPITECH PROJECT, 2023
** monster.h
** File description:
** monster
*/

#ifndef MONSTER_H_
    #define MONSTER_H_
    #include "my.h"

    typedef struct monster_sp_s {
        sfTexture *main;
        sfSprite *walk;
        sfClock *clock;
        sfClock *clock_1;
        sfClock *clock_2;
        sfIntRect rect;
        sfVector2f pos;
        int top_less;
        int back;
        int lenx;
        int left;
        int leny;
        int boss;
        int life;
        float spawn_time;
        int nb_monster;
        int dead;
    } monster_sp_t;

    typedef struct monster_in_s {
        monster_sp_t *monster1;
        monster_sp_t *monster2;
        monster_sp_t *monster3;
        monster_sp_t *monster4;
        int nb_monster;
        int spawn1;
        int spawn2;
        int spawn3;
        int spawn4;
        int selected;
    } monster_in_t;

    monster_in_t *init_monster_manage(void);

#endif /* !MONSTER_H_ */
