/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-dorian.senecot
** File description:
** init_playm
*/

#include "../../include/my.h"
#include "../../include/rpg.h"

char *wichsave(char *file)
{
    char *buffer;
    struct stat s;
    stat(file, &s);
    buffer = malloc(sizeof(char) * s.st_size + 1);
    read(open(file, O_RDONLY),
    buffer, s.st_size);
    buffer[s.st_size] = '\0';
    return buffer;
}

void init_champ_addon(champ_t *champ)
{
    champ->c1_s = get_sprite(
    sfTexture_createFromFile("sprite/champ/Biker/Biker_attack3.png", NULL));
    sfSprite_setScale(champ->c1_s, get_vector(4, 4));
    champ->c2_s = get_sprite(
    sfTexture_createFromFile("sprite/champ/Cyborg/Cyborg_attack3.png", NULL));
    sfSprite_setScale(champ->c2_s, get_vector(4, 4));
    champ->c3_s = get_sprite(
    sfTexture_createFromFile("sprite/champ/Punk/Punk_attack3.png", NULL));
    sfSprite_setScale(champ->c3_s, get_vector(4, 4));
    champ->c1 = init_button(champ->bg, get_rect(485, 385, 220, 205));
    sfSprite_setScale(champ->c1->texture_init, get_vector(1.3, 1.3));
    champ->c2 = init_button(champ->bg, get_rect(485, 385, 220, 205));
    sfSprite_setScale(champ->c2->texture_init, get_vector(1.3, 1.3));
    champ->c3 = init_button(champ->bg, get_rect(485, 385, 220, 205));
    sfSprite_setScale(champ->c3->texture_init, get_vector(1.3, 1.3));
}

champ_t *init_champ(void)
{
    champ_t *champ = malloc(sizeof(champ_t));
    champ->bg = sfTexture_createFromFile
    ("sprite/cadre.png", NULL);
    init_champ_addon(champ);
    champ->c1t = init_text((sfVector2f){1920 / 2 - 510, 435},
    sfWhite, 50, "Biker");
    champ->c2t = init_text((sfVector2f){1920 / 2 + 370, 435},
    sfWhite, 50, "Cyborg");
    champ->c3t = init_text((sfVector2f){1920 / 2 - 65, 880},
    sfWhite, 50, "Punk");
    champ->rect = get_rect(0, 0, 48, 48);
    init_pos_champ(champ);
    return champ;
}

play_t *init_playm(bg_t *bg)
{
    play_t *playm = malloc(sizeof(play_t));
    playm->bg = sfTexture_createFromFile
    ("sprite/cadre.png", NULL);
    playm->s1 = init_button(playm->bg, get_rect(485, 610, 540, 205));
    sfSprite_setScale(playm->s1->texture_init, get_vector(1.5, 1.5));
    playm->s2 = init_button(playm->bg, get_rect(485, 610, 540, 205));
    sfSprite_setScale(playm->s2->texture_init, get_vector(1.5, 1.5));
    playm->s3 = init_button(playm->bg, get_rect(485, 610, 540, 205));
    sfSprite_setScale(playm->s3->texture_init, get_vector(1.5, 1.5));
    playm->s1t = init_text((sfVector2f){1920 / 2 + 425, 150},
    sfWhite, 50, "Save #1");
    playm->s2t = init_text((sfVector2f){1920 / 2 + 425, 475},
    sfWhite, 50, "Save #2");
    playm->s3t = init_text((sfVector2f){1920 / 2 + 425, 800},
    sfWhite, 50, "Save #3");
    playm->t1 = init_text((sfVector2f){1920 / 2 - 550, 30},
    sfWhite, 25, wichsave("saves/s1.txt"));
    playm->quit = init_button(bg->but, get_rect(367, 210, 208, 66));
    init_pos_playm(playm);
    return playm;
}

monster_t *init_monster(void)
{
    monster_t *monster = malloc(sizeof(monster_t) * 100);
    for (int i = 0; i < 100; i++)
        monster->rect = get_rect(0, 0, 70, 70);
    return monster;
}
