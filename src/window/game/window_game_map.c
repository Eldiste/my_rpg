/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** window_game_map
*/

#include "my.h"
#include "rpg.h"

void window_vague1(rpg_t *rpg)
{
    if (rpg->game->skills->xp->lvl < 5)
        monster_animation(rpg, rpg->monster->monster1, 0);
    if (rpg->game->skills->xp->lvl >= 5 && rpg->game->skills->xp->lvl < 10)
        monster_animation(rpg, rpg->monster->monster3, 0);
    if (rpg->game->skills->xp->lvl >= 10 && rpg->game->skills->xp->lvl < 15)
        monster_animation(rpg, rpg->monster->monster4, 0);
    if (rpg->game->skills->xp->lvl >= 15 && rpg->game->skills->xp->lvl < 20) {
        monster_animation(rpg, rpg->monster->monster1, 0);
        monster_animation(rpg, rpg->monster->monster2, rpg->monster->spawn2);
        for (int i = 0; i < rpg->monster->monster2->nb_monster; i++) {
            rpg->monster->monster2[i].dead == 1 ?
            rpg->game->pnj->obj->final = 1 : 0;
        }
        rpg->monster->spawn2++;
    } window_vague2(rpg);
}

void window_game_map_rect_quest(rpg_t *rpg, sfFloatRect rect3,
sfFloatRect rect2)
{
    if (sfFloatRect_intersects(&rect3, &rect2, NULL) &&
        (rpg->game->settings == 0 && rpg->game->inv_st == 0)) {
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            rpg->game->pnj->isKeyPressed = sfTrue;
        } if (rpg->game->pnj->isKeyPressed) {
            window_quest(rpg);
        } else {
            sfSprite_setPosition(rpg->game->pnj->intertaction,
            (sfVector2f){rpg->game->player->position.x + 25,
            rpg->game->player->position.y - 18});
            sfRenderWindow_drawSprite(rpg->head->window,
            rpg->game->pnj->quest->is, NULL);
            sfRenderWindow_drawText(rpg->head->window,
            rpg->game->pnj->quest->is_txt->text, NULL);
            sfRenderWindow_drawSprite(rpg->head->window,
            rpg->game->pnj->intertaction, NULL);
        }
    } else if (!(sfFloatRect_intersects(&rect3, &rect2, NULL) &&
            (rpg->game->settings == 0 && rpg->game->inv_st == 0)))
        rpg->game->pnj->isKeyPressed = sfFalse;
}

void window_game_map_rect_crampte(rpg_t *rpg, sfFloatRect rect1,
sfFloatRect rect2)
{
    if (sfFloatRect_intersects(&rect1, &rect2, NULL) &&
        (rpg->game->settings == 0 && rpg->game->inv_st == 0)) {
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            sfMusic_play(rpg->music->music_crampteur);
            rpg->game->pnj->isKeyPressed = sfTrue;
        } if (rpg->game->pnj->isKeyPressed) { window_crampteur(rpg);
        } else {
            sfSprite_setPosition(rpg->game->pnj->intertaction,
            (sfVector2f){rpg->game->player->position.x + 25,
            rpg->game->player->position.y - 18});
            sfRenderWindow_drawSprite(rpg->head->window,
            rpg->game->pnj->crampteur->is, NULL);
            sfRenderWindow_drawText(rpg->head->window,
            rpg->game->pnj->crampteur->is_txt->text, NULL);
            sfRenderWindow_drawSprite(rpg->head->window,
            rpg->game->pnj->intertaction, NULL);
        }
    } else if (!(sfFloatRect_intersects(&rect1, &rect2, NULL) &&
            (rpg->game->settings == 0 && rpg->game->inv_st == 0)))
        rpg->game->pnj->isKeyPressed = sfFalse;
}

void window_game_map_rect(rpg_t *rpg)
{
    sfFloatRect rect1 =
    sfSprite_getGlobalBounds(rpg->game->pnj->crampteur->sprite);
    sfFloatRect rect3 = sfSprite_getGlobalBounds(rpg->game->pnj->quest->sprite);
    sfFloatRect rect2;
    if (rpg->hero->selected == BIKER) {
        character_animation(rpg, rpg->hero->biker->walk, rpg->utils->hero);
        rect2 = sfSprite_getGlobalBounds(rpg->hero->biker->walk);
    } if (rpg->hero->selected == PUNK) {
        rect2 = sfSprite_getGlobalBounds(rpg->hero->punk->walk);
        character_animation(rpg, rpg->hero->punk->walk, rpg->utils->hero);
    } if (rpg->hero->selected == CYBORG) {
        rect2 = sfSprite_getGlobalBounds(rpg->hero->cyborg->walk);
        character_animation(rpg, rpg->hero->cyborg->walk, rpg->utils->hero);
    } window_game_map_rect_crampte(rpg, rect1, rect2);
    window_game_map_rect_quest(rpg, rect3, rect2);
}

void window_game_map(rpg_t *rpg)
{
    if (MAP->is_generated == sfFalse)
        generate_map(rpg->game);
    show_map(rpg);
    window_vague1(rpg);
    pnj_animation(rpg);
    window_game_map_rect(rpg);
    if (rpg->game->inv_st == 1)
        window_inv(rpg);
    show_particles(rpg);
    event_pot(rpg);
    event_tp(rpg);
}
