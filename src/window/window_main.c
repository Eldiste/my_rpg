/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** window_main
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void window_select(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->champ->c1->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->champ->c1_s, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->champ->c2->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->champ->c2_s, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->champ->c3->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->champ->c3_s, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->champ->c1t->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->champ->c2t->text, NULL);
    sfRenderWindow_drawText(rpg->head->window,
    rpg->bg->champ->c3t->text, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->play_m->quit->texture_init, NULL);
}

void window_info(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->head->window, rpg->bg->logo, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->info->texture_init, NULL);
    text_file(rpg);
}

void window_home(rpg_t *rpg)
{
    event_click_effect(rpg);
    event_click_music(rpg);
    sfRenderWindow_drawSprite(rpg->head->window, rpg->bg->logo, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->play->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->settings->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->quit->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->son->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->effect->texture_init, NULL);
    sfRenderWindow_drawSprite(rpg->head->window,
    rpg->bg->info->texture_init, NULL);
}

void window_manage_addon(rpg_t *rpg)
{
    sfRectangleShape_setFillColor(rpg->utils->overlay,
    (sfColor){0, 0, 0, rpg->utils->light});
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->utils->overlay, NULL);
    event_fade(rpg);
    sfRenderWindow_setView(rpg->head->window, rpg->head->new_view);
    sfRenderWindow_display(rpg->head->window);
}

void window_manage(rpg_t *rpg)
{
    is_on_manage(rpg);
    sfRenderWindow_clear(rpg->head->window, sfBlack);
    if (rpg->bg->st <= 4)
        sfRenderWindow_drawSprite(rpg->head->window, rpg->bg->bg, NULL);
    if (rpg->bg->st == 0)
        window_home(rpg);
    if (rpg->bg->st == 1 && rpg->utils->st_f > 49)
        window_settings(rpg);
    if (rpg->bg->st == 2)
        window_info(rpg);
    if (rpg->bg->st == 3 && rpg->utils->st_f > 49)
        window_play(rpg);
    if (rpg->bg->st == 4 && rpg->utils->st_f > 49)
        window_select(rpg);
    window_manage_addon(rpg);
}
