/*
** EPITECH PROJECT, 2023
** move_monster
** File description:
** move_monster
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void dealt_damage(rpg_t *rpg)
{
    if (rand() % 3000 >= rpg->game->skills->def->def)
        rpg->game->skills->hp->hp--;
}

void take_damage(rpg_t *rpg, monster_sp_t *monster, int i)
{
    if (rpg->game->player->position.x < monster[i].pos.x
    && rpg->game->player->position.y < monster[i].pos.y) {
        if ((monster[i].pos.x - rpg->game->player->position.x < 40)
        && (monster[i].pos.y - rpg->game->player->position.y < 40)) {
            dealt_damage(rpg);
        }
    }
    if (monster[i].pos.x < rpg->game->player->position.x
    && monster[i].pos.y < rpg->game->player->position.y) {
        if ((rpg->game->player->position.x - monster[i].pos.x < 40)
        && (rpg->game->player->position.y - monster[i].pos.y < 40)) {
            dealt_damage(rpg);
        }
    }
    end_take_damage(rpg, monster, i);
}

void set_move(rpg_t *rpg, monster_sp_t *monster, int i)
{
    if (monster[i].pos.x - rpg->game->player->position.x >= 1) {
        sfSprite_setPosition(monster[i].walk,
        get_vector(monster[i].pos.x + monster->back, monster[i].pos.y));
        sfSprite_setScale(monster[i].walk, get_vector(-1, 1));
    } else {
        sfSprite_setPosition(monster[i].walk,
        get_vector(monster[i].pos.x, monster[i].pos.y));
        sfSprite_setScale(monster[i].walk, get_vector(1, 1));
    } if (monster[i].boss == 1 && (monster[i].pos.x
    - rpg->game->player->position.x >= 1)) {
        sfSprite_setPosition(monster[i].walk,
        get_vector(monster[i].pos.x + 100, monster[i].pos.y));
        sfSprite_setScale(monster[i].walk, get_vector(-1.25, 1.25));
    } if (monster[i].boss == 1 && (monster[i].pos.x
    - rpg->game->player->position.x < 1)) {
        sfSprite_setPosition(monster[i].walk,
        get_vector(monster[i].pos.x, monster[i].pos.y));
        sfSprite_setScale(monster[i].walk, get_vector(1.25, 1.25));
    } if (monster[i].pos.x - rpg->game->player->position.x > 600)
        monster[i].dead = 1;
}

void set_move_inverse(rpg_t *rpg, monster_sp_t *monster, int i)
{
    if (monster[i].boss == 1) {
        sfSprite_setPosition(monster[i].walk,
        get_vector(monster[i].pos.x, monster[i].pos.y));
        sfSprite_setScale(monster[i].walk, get_vector(1.25, 1.25));
    }
    if (rpg->game->player->position.x - monster[i].pos.x > 600) {
        monster[i].dead = 1;
    }
}

void move_monster(rpg_t *rpg, monster_sp_t *monster)
{
    for (int i = 0; i < monster->nb_monster; i++) {
        float speed = 0.5;
        sfSprite_setPosition(monster[i].walk, monster[i].pos);
        if (monster[i].dead == 0) {
            take_damage(rpg, monster, i);
        }
        if (rpg->game->player->position.x < monster[i].pos.x) {
            monster[i].pos.x -= speed;
            set_move(rpg, monster, i);
        } else {
            monster[i].pos.x += speed;
            sfSprite_setScale(monster[i].walk, get_vector(1, 1));
            set_move_inverse(rpg, monster, i);
        } end_move(rpg, speed, i, monster);
    }
}
