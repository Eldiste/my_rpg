/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_main
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

hero_t *init_hero(void)
{
    hero_t *hero = malloc(sizeof(hero_t));
    hero->rect = get_rect(0, 0, 45, 45);
    hero->rect_attack = get_rect(0, 0, 48, 48);
    return hero;
}

head_t *init_head(void)
{
    head_t *head = malloc(sizeof(head_t));
    head->screen_st = 0;
    head->frame = 60;
    head->music = 50;
    head->effect = 50;
    head->video_mode = *sfVideoMode_getFullscreenModes(NULL);
    head->window = sfRenderWindow_create(head->video_mode, "RPG",
    sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(head->window, head->frame);
    head->view_rect = (sfFloatRect){0, 0, 0, 0};
    head->new_view = sfView_create();
    sfView_setCenter(head->new_view, get_vector(960, 540));
    sfView_setSize(head->new_view, get_vector(1920, 1080));
    head->logo = sfImage_createFromFile("sprite/icon.png");
    return head;
}

utils_t *init_utils(void)
{
    utils_t *utils = malloc(sizeof(utils_t));
    utils->font = sfFont_createFromFile("font/bold.ttf");
    utils->overlay = sfRectangleShape_create();
    sfRectangleShape_setSize(utils->overlay, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(utils->overlay, sfTransparent);
    utils->clokck_f = sfClock_create();
    utils->clock_sp = sfClock_create();
    utils->clock_coins = sfClock_create();
    utils->clock_spawn = sfClock_create();
    utils->clock_pnj = sfClock_create();
    utils->clock_attack = sfClock_create();
    utils->clock_anim_attack = sfClock_create();
    utils->clock_anim_attack2 = sfClock_create();
    utils->st_f = 0;
    utils->light = 0;
    utils->loop_sp = 0;
    utils->hero = init_hero();
    utils->monster = init_monster();
    return utils;
}

music_t *init_music(rpg_t *rpg)
{
    music_t *music = malloc(sizeof(music_t));
    char *buffer;
    struct stat s;
    stat("./src/utils/help.txt", &s);
    buffer = malloc(sizeof(char) * s.st_size + 1);
    read(open("./src/utils/help.txt", O_RDONLY),
    buffer, s.st_size);
    rpg->help = buffer;
    return music;
}

rpg_t *init_manage(rpg_t *rpg)
{
    rpg->music = init_music(rpg);
    rpg->head = init_head();
    rpg->bg = init_bg();
    rpg->utils = init_utils();
    rpg->game = init_game();
    rpg->hero = init_hero_manage();
    rpg->monster = init_monster_manage();
    rpg->bg->text_anim = init_text((sfVector2f){0, 800},
    sfWhite, 32, rpg->help);
    get_text_all(rpg);
    sfRenderWindow_setIcon(rpg->head->window, 256, 256,
    sfImage_getPixelsPtr(rpg->head->logo));
    return rpg;
}
