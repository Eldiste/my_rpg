/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** event_main
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void event_resize(rpg_t *rpg)
{
    if (rpg->head->event.type == sfEvtResized) {
        float newWidth = rpg->head->event.size.width;
        float newHeight = rpg->head->event.size.height;
        float aspectRatio = newWidth / newHeight;
        float viewRatio = rpg->head->video_mode.width
        / rpg->head->video_mode.height;
        sfFloatRect viewport = {0, 0, 1, 1};
        if (aspectRatio > viewRatio) {
            float scale = newHeight / rpg->head->video_mode.height;
            viewport.width = rpg->head->video_mode.width * scale / newWidth;
            viewport.left = (1 - viewport.width) / 2;
        } else {
            float scale = newWidth / rpg->head->video_mode.width;
            viewport.height = rpg->head->video_mode.height * scale / newHeight;
            viewport.top = (1 - viewport.height) / 2;
        }
        sfView_setViewport(rpg->head->new_view, viewport);
    }
}

void event_manage(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->head->window,
    &rpg->head->event)) {
        event_fullscreen(rpg);
        event_close(rpg);
        event_resize(rpg);
    }
}
