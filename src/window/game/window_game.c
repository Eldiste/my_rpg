/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** window_game
*/

#include "my.h"
#include "rpg.h"

void player_death_addon2(rpg_t *rpg)
{
    if (rpg->hero->selected == BIKER) {
        sfSprite_setTextureRect(rpg->hero->biker->walk,
        rpg->utils->hero->rect);
        sfRenderWindow_drawSprite(rpg->head->window,
        rpg->hero->biker->walk, NULL);
    } if (rpg->hero->selected == PUNK) {
        sfSprite_setTextureRect(rpg->hero->punk->walk,
        rpg->utils->hero->rect);
        sfRenderWindow_drawSprite(rpg->head->window,
        rpg->hero->punk->walk, NULL);
    } if (rpg->hero->selected == CYBORG) {
        sfSprite_setTextureRect(rpg->hero->cyborg->walk,
        rpg->utils->hero->rect);
        sfRenderWindow_drawSprite(rpg->head->window,
        rpg->hero->cyborg->walk, NULL);
    } sfRenderWindow_display(rpg->head->window);
}

void player_death_addon(rpg_t *rpg, int *end)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (rpg->utils->clock_anim_attack2)) > 250) {
        sfClock_restart(rpg->utils->clock_anim_attack2);
        rpg->utils->hero->rect.top = 48 * 4 + 10;
        if (rpg->utils->hero->rect.left <= 48 * 6)
            rpg->utils->hero->rect.left += 48;
        else
            (*end) = 1;
    } sfRenderWindow_clear(rpg->head->window, sfBlack);
    set_text_position(rpg->game->death,
    (sfVector2f){rpg->game->player->position.x - 180,
    rpg->game->player->position.y - 200});
    sfRenderWindow_drawText(rpg->head->window,
    rpg->game->death->text, NULL);
    player_death_addon2(rpg);
}

void player_death(rpg_t *rpg)
{
    if (rpg->game->skills->hp->hp < 1) {
        sfMusic_stop(rpg->music->music_game);
        sfMusic_play(rpg->music->music_loose);
        set_music(rpg);
        int end = 0;
        rpg->utils->hero->rect.left = 0;
        while (end != 1) {
            player_death_addon(rpg, &end);
        } sfRenderWindow_display(rpg->head->window);
        monster_rest(rpg);
        rpg->game->skills->hp->hp = 100;
        rpg->game->skills->xp->lvl = 1;
        rpg->game->inv->potion_left = 0;
        rpg->game->inv->tp_left = 0; rpg->bg->st = 3;
        rpg->utils->st_f = 49;
        rpg->head->new_view = sfView_create();
        sfView_setCenter(rpg->head->new_view, get_vector(960, 540));
        sfView_setSize(rpg->head->new_view, get_vector(1920, 1080));
        sfMusic_play(rpg->music->music_menu);
    }
}

void window_game(rpg_t *rpg)
{
    is_on_manage_game(rpg);
    sfRenderWindow_clear(rpg->head->window, sfBlack);
    sfView_setSize(rpg->head->new_view, (sfVector2f){960, 540});
    if (rpg->bg->st == 5) {
        window_game_map(rpg);
    } if (rpg->bg->st == 6) {
        esc_main(rpg);
    } skills_main(rpg);
    sfRectangleShape_setFillColor(rpg->utils->overlay,
    (sfColor){0, 0, 0, rpg->utils->light});
    sfRenderWindow_drawRectangleShape(rpg->head->window,
    rpg->utils->overlay, NULL);
    kill_monster(rpg);
    player_death(rpg);
    sfRenderWindow_display(rpg->head->window);
}
