/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** skills
*/

#ifndef SKILLS_H_
    #define SKILLS_H_
    #include "rpg.h"
    #include "my.h"

    typedef struct slider {
        sfRectangleShape *track;
        sfVector2f tracksize;
        sfVector2f trackPosition;
        sfCircleShape *thumb;
        sfVector2f thumbPosition;
        float thumbRadius;
        float range;
    } slider_t;

    typedef struct button {
        sfSprite *texture_init;
        sfFloatRect rect;
        int st;
    } button_t;

    typedef struct text {
        sfText *text;
        sfVector2f vect;
        sfColor color;
        int size;
        char *str;
    } text_t;

    typedef struct atck_s {
        text_t *atck_txt;
        text_t *atck_st;
        int atck;
        int status;
    } atck_t;

    typedef struct def_s {
        text_t *def_txt;
        text_t *def_st;
        int def;
        int status;
    } def_t;

    typedef struct hp_s {
        sfRectangleShape *hp_rect;
        sfRectangleShape *hp_rect_base;
        text_t *hp_txt;
        text_t *hp_st;
        int hp_max;
        int hp;
        int previous_hp;
        int status;
    } hp_t;

    typedef struct coins_s {
        sfSprite *sprite;
        text_t *coins_txt;
        sfIntRect rect;
        int coins;
    } coins_t;

    typedef struct xp_s {
        sfRectangleShape *xp_rect;
        sfRectangleShape *xp_rect_base;
        text_t *xp_txt;
        text_t *xp_st;
        int lvl;
        int xp_max;
        int xp;
    } xp_t;

    typedef struct skills_s {
        hp_t *hp;
        xp_t *xp;
        atck_t *atck;
        def_t *def;
        coins_t *coins;
    } skills_t;

    skills_t *init_skills(void);
    void set_text_position(text_t *text, sfVector2f position);

#endif /* !SKILLS_H_ */
