/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_slider
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void event_slider(rpg_t *rpg, slider_t *slider, float min, int *c)
{
    sfVector2f mousePosition;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        mousePosition = sfRenderWindow_mapPixelToCoords(
        rpg->head->window, rpg->head->mouse_pos, rpg->head->new_view);
        if ((mousePosition.x > slider->trackPosition.x
            && mousePosition.x < slider->trackPosition.x + slider->tracksize.x)
            && (mousePosition.y + 10 > slider->trackPosition.y
            && mousePosition.y - 10 <
            slider->trackPosition.y + slider->tracksize.y)) {
            slider->thumbPosition.x = mousePosition.x - 15;
            sfCircleShape_setPosition(slider->thumb, slider->thumbPosition);
            (*c) = ((slider->thumbPosition.x - slider->trackPosition.x)
            / slider->tracksize.x) * slider->range + min;
        }
    } else {
        slider->thumbPosition.x = slider->trackPosition.x +
        (((*c) - min) / slider->range) * slider->tracksize.x;
        sfCircleShape_setPosition(slider->thumb, slider->thumbPosition);
    }
}

void event_slider_frame(rpg_t *rpg, slider_t *slider, float min, int *c)
{
    sfVector2f mousePosition; static int wasPressed = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        mousePosition = sfRenderWindow_mapPixelToCoords(
        rpg->head->window, rpg->head->mouse_pos, rpg->head->new_view);
        if ((mousePosition.x > slider->trackPosition.x
        && mousePosition.x < slider->trackPosition.x + slider->tracksize.x)
        && (mousePosition.y + 10 > slider->trackPosition.y && mousePosition.y
        - 10 < slider->trackPosition.y + slider->tracksize.y)) {
            slider->thumbPosition.x = mousePosition.x - 15;
            sfCircleShape_setPosition(slider->thumb, slider->thumbPosition);
            (*c) = ((slider->thumbPosition.x - slider->trackPosition.x) /
            slider->tracksize.x) * slider->range + min; wasPressed = 1;
        } } else {
        slider->thumbPosition.x = slider->trackPosition.x + (((*c) - min) /
        slider->range) * slider->tracksize.x;
        sfCircleShape_setPosition(slider->thumb, slider->thumbPosition);
        if (wasPressed) { wasPressed = 0;
            sfRenderWindow_setFramerateLimit(rpg->head->window,
            rpg->head->frame);
        } }
}
