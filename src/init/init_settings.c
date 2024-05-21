/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** init_settings
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

void init_opt_t_slider(opt_t *opt)
{
    opt->frame_tex = init_text((sfVector2f){1920 / 2 + 242, 380},
    sfWhite, 50, my_strcat(my_int_to_strnum(144), "FPS"));
    opt->music_tex = init_text((sfVector2f){1920 / 2 - 395, 370},
    sfWhite, 50, my_strcat(my_int_to_strnum(50), " %"));
    opt->effect_tex = init_text((sfVector2f){1920 / 2 - 395, 620},
    sfWhite, 50, my_strcat(my_int_to_strnum(50), " %"));
    opt->light_text = init_text((sfVector2f){1920 / 2 + 285, 585},
    sfWhite, 50, my_strcat(my_int_to_strnum(0), " %"));
}

void init_opt_text(opt_t *opt)
{
    opt->fullscreen = init_text((sfVector2f){1920 / 2 + 125, 175},
    sfWhite, 50, "Fullscreen");
    opt->framerate = init_text((sfVector2f){1920 / 2 + 200, 280},
    sfWhite, 50, "Framerate");
    opt->general = init_text((sfVector2f){1920 / 2 + 200, 75},
    sfWhite, 70, "General");
    opt->audio = init_text((sfVector2f){1920 / 2 - 425, 75},
    sfWhite, 70, "Audio");
    opt->music = init_text((sfVector2f){1920 / 2 - 400, 250},
    sfWhite, 50, "Music");
    opt->effect = init_text((sfVector2f){1920 / 2 - 400, 500},
    sfWhite, 50, "Effect");
    opt->light = init_text((sfVector2f){1920 / 2 + 220, 480},
    sfWhite, 50, "Darkness");
    init_opt_t_slider(opt);
}

void init_opt_slider(opt_t *opt)
{
    opt->frame_s = init_slider(get_vector(200.f, 10.f),
    get_vector(1920 / 2 + 210, 360), 242.f - 30.f, 20.f);
    opt->music_s = init_slider(get_vector(200.f, 10.f),
    get_vector(1920 / 2 - 440, 350), 102.f - 0.f, 20.f);
    opt->effect_s = init_slider(get_vector(200.f, 10.f),
    get_vector(1920 / 2 - 440, 600), 102.f - 0.f, 20.f);
    opt->light_s = init_slider(get_vector(200.f, 10.f),
    get_vector(1920 / 2 + 210, 565), 102.f - 0.f, 20.f);
}

opt_t *init_opt(void)
{
    opt_t *opt = malloc(sizeof(opt_t));
    opt->but = sfTexture_createFromFile
    ("sprite/cadre.png", NULL);
    opt->of = sfTexture_createFromFile
    ("sprite/onoff.png", NULL);
    opt->bg = get_sprite(opt->but);
    sfSprite_setTextureRect(opt->bg, get_rect(0, 389, 766, 465));
    sfSprite_setScale(opt->bg, get_vector(1.6, 1.6));
    init_opt_text(opt);
    opt->back = init_button(opt->but, get_rect(720, 835, 150, 134));
    opt->on = init_button(opt->of, get_rect(60, 0, 500, 190));
    opt->off = init_button(opt->of, get_rect(250, 0, 500, 300));
    sfSprite_setScale(opt->on->texture_init, get_vector(0.4, 0.4));
    sfSprite_setScale(opt->off->texture_init, get_vector(0.4, 0.4));
    init_opt_slider(opt);
    return opt;
}
