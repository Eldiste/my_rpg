/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** pnj
*/

#ifndef PNJ_H_
    #define PNJ_H_
    #include "rpg.h"

    typedef struct quest_s {
        int kill;
        int kill_obj;
        int earn;
        int earn_obj;
        int final;
    } quest_t;

    typedef struct pnjst_s {
        sfTexture *font;
        sfVector2f position;
        sfIntRect rect;
        sfTexture *texture;
        sfSprite *sprite;
        sfSprite *tools;
        sfSprite *is;
        button_t *atck;
        button_t *def;
        button_t *hp;
        button_t *speed;
        text_t *atck_txt;
        text_t *def_txt;
        text_t *speed_txt;
        text_t *hp_txt;
        text_t *is_txt;
        text_t *final;
    } pnjst_t;

    typedef struct pnj_s {
        pnjst_t *crampteur;
        pnjst_t *quest;
        quest_t *obj;
        sfSprite *intertaction;
        sfIntRect intertaction_rect;
        text_t *price_txt;
        text_t *skills_tree;
        text_t *current;
        int price;
        sfBool isKeyPressed;
    } pnj_t;

    pnj_t *init_pnj(void);
    pnjst_t *init_pnjst_quest(char *path, sfVector2f pos);
    pnjst_t *init_crampteur(char *path, sfVector2f pos);

#endif /* !PNJ_H_ */
