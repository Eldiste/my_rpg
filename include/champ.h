/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** champ
*/

#ifndef CHAMP_H_
    #define CHAMP_H_
    #include "my.h"

    typedef struct hero_sp_s {
        sfTexture *main;
        sfTexture *main_extra;
        sfSprite *walk;
    } hero_sp_t;

    typedef struct hero_in_s {
        hero_sp_t *punk;
        hero_sp_t *biker;
        hero_sp_t *cyborg;
        int selected;
    } hero_in_t;

    hero_in_t *init_hero_manage(void);

#endif /* !CHAMP_H_ */
