/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** init_struct_var
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

text_t *init_text(sfVector2f vect, sfColor color,
int size, char *str)
{
    text_t *text = malloc(sizeof(text_t));
    text->text = sfText_create();
    text->vect = vect;
    text->color = color;
    text->size = size;
    text->str = str;
    return text;
}

slider_t *init_slider(sfVector2f tracksize, sfVector2f trackPosition,
float range, float thumbRadius)
{
    slider_t *slider = malloc(sizeof(slider_t));
    slider->track = sfRectangleShape_create();
    slider->thumb = sfCircleShape_create();
    slider->range = range;
    slider->tracksize = tracksize;
    slider->thumbRadius = thumbRadius;
    slider->trackPosition = trackPosition;
    sfRectangleShape_setSize(slider->track, slider->tracksize);
    sfRectangleShape_setPosition(slider->track, slider->trackPosition);
    sfCircleShape_setRadius(slider->thumb, slider->thumbRadius);
    slider->thumbPosition =
    (sfVector2f){slider->trackPosition.x + slider->thumbRadius,
    slider->trackPosition.y + slider->tracksize.y - 25};
    sfCircleShape_setPosition(slider->thumb, slider->thumbPosition);
    return slider;
}

button_t *init_button(sfTexture *init, sfIntRect rect)
{
    button_t *button = malloc(sizeof(button_t));
    button->texture_init = get_sprite(init);
    sfSprite_setTextureRect(button->texture_init, rect);
    button->st = 0;
    return button;
}
