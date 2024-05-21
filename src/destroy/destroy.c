/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** destroy
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void clean_head(head_t *head)
{
    sfRenderWindow_destroy(head->window);
    sfView_destroy(head->new_view);
    sfImage_destroy(head->logo);
}

void clean_utils(utils_t *utils)
{
    sfFont_destroy(utils->font);
    sfRectangleShape_destroy(utils->overlay);
    sfClock_destroy(utils->clokck_f);
    sfClock_destroy(utils->clock_sp);
    sfClock_destroy(utils->clock_coins);
    sfClock_destroy(utils->clock_spawn);
    sfClock_destroy(utils->clock_pnj);
    sfClock_destroy(utils->clock_attack);
    sfClock_destroy(utils->clock_anim_attack);
    sfClock_destroy(utils->clock_anim_attack2);
    free(utils->hero);
    free(utils->monster);
}

void clean_bg(bg_t *bg)
{
    free(bg->opt);
    free(bg->play);
    free(bg->settings);
    free(bg->quit);
    free(bg->son);
    free(bg->effect);
    free(bg->info);
    sfSprite_destroy(bg->bg);
    sfSprite_destroy(bg->logo);
    free(bg->play_m);
    free(bg->champ);
}

void clean_rpg(rpg_t *rpg)
{
    free(rpg->music);
    free(rpg->head);
    free(rpg->bg);
    free(rpg->utils);
    free(rpg->game);
    free(rpg->hero);
}

void clean_all(rpg_t *rpg)
{
    clean_head(rpg->head);
    clean_utils(rpg->utils);
    clean_bg(rpg->bg);
    clean_rpg(rpg);
}
