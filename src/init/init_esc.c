/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** init_esc
*/

#include "rpg.h"

void init_esc_t_slider(esc_t *esc)
{
    esc->frame_tex = init_text((sfVector2f){1920 / 2 + 242, 380},
    sfWhite, 20, my_strcat(my_int_to_strnum(144), "FPS"));
    esc->music_tex = init_text((sfVector2f){1920 / 2 - 395, 370},
    sfWhite, 20, my_strcat(my_int_to_strnum(50), " %"));
    esc->effect_tex = init_text((sfVector2f){1920 / 2 - 395, 620},
    sfWhite, 20, my_strcat(my_int_to_strnum(50), " %"));
    esc->light_text = init_text((sfVector2f){1920 / 2 + 285, 585},
    sfWhite, 20, my_strcat(my_int_to_strnum(0), " %"));
}

void init_esc_text(esc_t *esc)
{
    esc->fullscreen = init_text((sfVector2f){1920 / 2 + 125, 175},
    sfWhite, 20, "Fullscreen");
    esc->framerate = init_text((sfVector2f){1920 / 2 + 200, 280},
    sfWhite, 20, "Framerate");
    esc->general = init_text((sfVector2f){1920 / 2 + 200, 75},
    sfWhite, 30, "General");
    esc->audio = init_text((sfVector2f){1920 / 2 - 425, 75},
    sfWhite, 30, "Audio");
    esc->music = init_text((sfVector2f){1920 / 2 - 400, 250},
    sfWhite, 20, "Music");
    esc->effect = init_text((sfVector2f){1920 / 2 - 400, 500},
    sfWhite, 20, "Effect");
    esc->light = init_text((sfVector2f){1920 / 2 + 220, 480},
    sfWhite, 20, "Darkness");
    init_esc_t_slider(esc);
}

void init_esc_slider(esc_t *esc)
{
    esc->frame_s = init_slider(get_vector(100.f, 5.f),
    get_vector(1920 / 2 + 210, 360), 242.f - 30.f, 10.f);
    esc->music_s = init_slider(get_vector(100.f, 5.f),
    get_vector(1920 / 2 - 440, 350), 101.f - 0.f, 10.f);
    esc->effect_s = init_slider(get_vector(100.f, 5.f),
    get_vector(1920 / 2 - 440, 600), 101.f - 0.f, 10.f);
    esc->light_s = init_slider(get_vector(100.f, 5.f),
    get_vector(1920 / 2 + 210, 565), 101.f - 0.f, 10.f);
}

esc_t *init_esc(void)
{
    esc_t *esc = malloc(sizeof(esc_t));
    esc->but = sfTexture_createFromFile
    ("sprite/cadre.png", NULL);
    esc->of = sfTexture_createFromFile
    ("sprite/onoff.png", NULL);
    esc->bg = get_sprite(esc->but);
    sfSprite_setTextureRect(esc->bg, get_rect(0, 389, 766, 465));
    sfSprite_setScale(esc->bg, get_vector(1.6, 1.6));
    init_esc_text(esc);
    esc->back = init_button(esc->but, get_rect(720, 835, 150, 134));
    esc->on = init_button(esc->of, get_rect(60, 0, 500, 190));
    esc->off = init_button(esc->of, get_rect(250, 0, 500, 300));
    sfSprite_setScale(esc->on->texture_init, get_vector(0.4, 0.4));
    sfSprite_setScale(esc->off->texture_init, get_vector(0.4, 0.4));
    init_esc_slider(esc);
    return esc;
}
