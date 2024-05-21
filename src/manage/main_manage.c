/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main_manage
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void main_menu(rpg_t *rpg)
{
    event_manage(rpg);
    window_manage(rpg);
}

void main_play(rpg_t *rpg)
{
    event_manage(rpg);
    window_game(rpg);
}

void set_music_end(rpg_t *rpg)
{
    sfMusic_setVolume(rpg->music->music_click_button, rpg->head->effect);
    sfMusic_setVolume(rpg->music->music_crampteur, rpg->head->effect);
    sfMusic_setVolume(rpg->music->music_cri_blessure, rpg->head->effect);
    sfMusic_setVolume(rpg->music->music_loose, rpg->head->effect);
    sfMusic_setVolume(rpg->music->music_menu, rpg->head->music);
    sfMusic_setVolume(rpg->music->music_game, rpg->head->music);
    sfMusic_setVolume(rpg->music->music_next_level, rpg->head->effect);
    sfMusic_setVolume(rpg->music->music_fight, rpg->head->effect);
    sfMusic_setVolume(rpg->music->music_monster, rpg->head->effect);
}

void set_music(rpg_t *rpg)
{
    rpg->music->music_transition =
    sfMusic_createFromFile("music/transition.wav");
    rpg->music->music_crampteur =
    sfMusic_createFromFile("music/crampteur.wav");
    rpg->music->music_click_button =
    sfMusic_createFromFile("music/click_button.wav");
    rpg->music->music_fight = sfMusic_createFromFile("music/fight1.wav");
    rpg->music->music_monster =
    sfMusic_createFromFile("music/monster_dead.wav");
    rpg->music->music_next_level = sfMusic_createFromFile("music/bonus.wav");
    rpg->music->music_loose = sfMusic_createFromFile("music/loose.wav");
    rpg->music->music_cri_blessure =
    sfMusic_createFromFile("music/cri_blessure.wav");
}

int main_manage(rpg_t *rpg)
{
    rpg->music->music_game = sfMusic_createFromFile("music/game_music.wav");
    rpg->music->music_menu = sfMusic_createFromFile("music/menu_music.wav");
    sfMusic_setLoop(rpg->music->music_menu, sfTrue);
    sfMusic_setLoop(rpg->music->music_game, sfTrue);
    sfMusic_play(rpg->music->music_menu); set_music(rpg); set_music_end(rpg);
    while (sfRenderWindow_isOpen(rpg->head->window)) {
        set_music_end(rpg);
        rpg->head->mouse_pos =
        (sfVector2i)sfMouse_getPositionRenderWindow(rpg->head->window);
        rpg->head->mous_resize = sfRenderWindow_mapPixelToCoords(
        rpg->head->window, rpg->head->mouse_pos, rpg->head->new_view);
        if (rpg->bg->st <= 4)
            main_menu(rpg);
        if (rpg->bg->st >= 5) {
            sfMusic_stop(rpg->music->music_menu); main_play(rpg);
        }
        rpg->utils->time_f = sfClock_getElapsedTime(rpg->utils->clokck_f);
        rpg->utils->second = rpg->utils->time_f.microseconds / 1000000.0;
    }
    return 0;
}
