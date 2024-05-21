/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include "my.h"

    typedef struct inv_s {
        sfSprite *main;
        sfSprite *hero;
        text_t *hp;
        text_t *xp;
        text_t *atck;
        text_t *def;
        text_t *speed;
        button_t *potion;
        text_t *poition_txt;
        int potion_left;
        button_t *tp;
        text_t *tp_txt;
        int tp_left;
    } inv_t;

    inv_t *init_inv(void);

#endif /* !INVENTORY_H_ */
