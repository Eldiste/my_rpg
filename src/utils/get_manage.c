/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-dorian.senecot
** File description:
** get_manage
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void get_text(rpg_t *rpg, text_t *text)
{
    sfText_setFont(text->text, rpg->utils->font);
    sfText_setPosition(text->text, text->vect);
    sfText_setColor(text->text, text->color);
    sfText_setCharacterSize(text->text, text->size);
    sfText_setString(text->text, text->str);
}

sfSprite *get_sprite(sfTexture *image)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, image, sfTrue);
    return sprite;
}

sfVector2f get_vector(float x, float y)
{
    sfVector2f vector = {x, y};
    return vector;
}

sfIntRect get_rect(int top, int left, int width, int height)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}
