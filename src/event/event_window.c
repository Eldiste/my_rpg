/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** event_window
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

int is_clicked(rpg_t *rpg, button_t *button)
{
    if (sfFloatRect_contains(&button->rect, rpg->head->mous_resize.x,
    rpg->head->mous_resize.y)) {
        return 1;
    } return 0;
}

void event_escpae(rpg_t *rpg)
{
    if (rpg->head->event.type == sfEvtKeyPressed
        && rpg->head->event.key.code == sfKeyEscape) {
        if (rpg->bg->st == 1) {
            rpg->bg->st = 0;
        } if (rpg->bg->st == 3) {
            rpg->bg->st = 0;
        } if (rpg->bg->st == 4) {
            rpg->bg->st = 3;
        } event_esc_press(rpg);
    }
}

void event_close(rpg_t *rpg)
{
    event_escpae(rpg);
    if (rpg->head->event.type == sfEvtKeyPressed
        && rpg->head->event.key.code == sfKeyE) {
            event_inv_press(rpg);
    }
    if ((rpg->head->event.type) == sfEvtClosed)
        sfRenderWindow_close(rpg->head->window);
}

void event_fullscreen_click(rpg_t *rpg)
{
    sfRenderWindow_destroy(rpg->head->window);
    rpg->head->video_mode = *sfVideoMode_getFullscreenModes(NULL);
    if (rpg->head->screen_st == 0) {
        rpg->head->window =
        sfRenderWindow_create(rpg->head->video_mode,
        "RPG", sfDefaultStyle | sfFullscreen, NULL);
        rpg->head->screen_st = 1;
    } else {
        rpg->head->window =
        sfRenderWindow_create(rpg->head->video_mode,
        "RPG", sfDefaultStyle, NULL);
        rpg->head->screen_st = 0;
    } sfRenderWindow_setFramerateLimit(rpg->head->window, rpg->head->frame);
}

void event_fullscreen(rpg_t *rpg)
{
    if (rpg->head->event.type == sfEvtKeyPressed &&
    rpg->head->event.key.code == sfKeyF11) {
        sfRenderWindow_destroy(rpg->head->window);
        rpg->head->video_mode = *sfVideoMode_getFullscreenModes(NULL);
        if (rpg->head->screen_st == 0) {
            rpg->head->window =
            sfRenderWindow_create(rpg->head->video_mode,
            "RPG", sfDefaultStyle | sfFullscreen, NULL);
            rpg->head->screen_st = 1;
        } else {
            rpg->head->window =
            sfRenderWindow_create(rpg->head->video_mode,
            "RPG", sfDefaultStyle, NULL);
            rpg->head->screen_st = 0;
        }
    } sfRenderWindow_setFramerateLimit(rpg->head->window, rpg->head->frame);
}
