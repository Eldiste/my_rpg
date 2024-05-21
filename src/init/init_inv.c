/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** init_inv
*/

#include "rpg.h"

void init_inv2(inv_t *inv)
{
    inv->speed = init_text((sfVector2f){1920 / 2 + 125, 175},
    sfWhite, 35, "xp");
    inv->poition_txt = init_text((sfVector2f){1920 / 2 + 125, 175},
    sfWhite, 25, "xp");
    inv->potion_left = 0;
    inv->tp_txt = init_text((sfVector2f){1920 / 2 + 125, 175},
    sfWhite, 25, "xp");
    inv->tp_left = 0;
}

inv_t *init_inv(void)
{
    inv_t *inv = malloc(sizeof(inv_t));
    inv->main =
    get_sprite(sfTexture_createFromFile("sprite/inventory.png", NULL));
    inv->potion =
    init_button_rec(sfTexture_createFromFile("sprite/potion.png", NULL));
    inv->tp =
    init_button(sfTexture_createFromFile("sprite/tp.png", NULL),
                                        get_rect(0, 0, 250, 592));
    inv->hp = init_text((sfVector2f){1920 / 2 + 125, 175},
    sfWhite, 35, "hp");
    inv->xp = init_text((sfVector2f){1920 / 2 + 125, 175},
    sfWhite, 35, "xp");
    inv->atck = init_text((sfVector2f){1920 / 2 + 125, 175},
    sfWhite, 35, "xp");
    inv->def = init_text((sfVector2f){1920 / 2 + 125, 175},
    sfWhite, 35, "xp");
    init_inv2(inv);
    return inv;
}
