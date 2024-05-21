/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_
    #include "monster.h"
    #include "skills.h"
    #include "game.h"
    #include "champ.h"
    #include "inventory.h"
    #include "my.h"
    #include "pnj.h"

typedef struct hero_s{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfIntRect rect_attack;
    sfClock *clock;
}hero_t;

typedef struct monster_s{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
}monster_t;

typedef struct music {
    sfMusic* music_menu;
    sfMusic* music_crampteur;
    sfMusic* music_cri_blessure;
    sfMusic* music_loose;
    sfMusic* music_game;
    sfMusic* music_click_button;
    sfMusic* music_transition;
    sfMusic* music_fight;
    sfMusic* music_monster;
    sfMusic *music_next_level;
} music_t;

typedef struct utils {
    sfFont *font;
    sfRectangleShape *overlay;
    sfClock *clokck_f;
    sfTime time_f;
    float second;
    int st_f;
    int light;
    sfClock *clock_sp;
    sfClock *clock_spawn;
    sfClock *clock_coins;
    sfClock *clock_pnj;
    sfClock *clock_attack;
    sfClock *clock_anim_attack;
    sfClock *clock_anim_attack2;
    int loop_sp;
    monster_t *monster;
    hero_t *hero;
} utils_t;

typedef struct opt {
    sfSprite *bg;
    sfTexture *but;
    sfTexture *of;
    button_t *back;
    button_t *on;
    button_t *off;
    text_t *fullscreen;
    text_t *general;
    text_t *light;
    text_t *audio;
    text_t *music;
    text_t *effect;
    text_t *framerate;
    text_t *music_tex;
    text_t *effect_tex;
    text_t *frame_tex;
    text_t *light_text;
    slider_t *frame_s;
    slider_t *music_s;
    slider_t *effect_s;
    slider_t *light_s;
} opt_t;

    typedef enum {
    BIKER,
    PUNK,
    CYBORG
    } hero_select;

typedef struct champ {
    sfTexture *bg;
    sfSprite *c1_s;
    sfSprite *c2_s;
    sfSprite *c3_s;
    sfIntRect rect;
    button_t *c1;
    button_t *c2;
    button_t *c3;
    text_t *c1t;
    text_t *c2t;
    text_t *c3t;
} champ_t;

typedef struct play {
    sfTexture *bg;
    button_t *s1;
    button_t *s2;
    button_t *s3;
    text_t *s1t;
    text_t *s2t;
    text_t *s3t;
    button_t *quit;
    text_t *t1;
    text_t *t2;
    text_t *t3;
} play_t;

typedef struct bg {
    sfSprite *bg;
    sfSprite *logo;
    sfTexture *but;
    button_t *play;
    button_t *settings;
    button_t *quit;
    button_t *son;
    button_t *effect;
    button_t *info;
    opt_t *opt;
    play_t *play_m;
    champ_t *champ;
    sfMusic *song;
    text_t *text_anim;
    sfClock *clock;
    int wich;
    int st;
} bg_t;

typedef struct head {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode video_mode;
    sfFloatRect view_rect;
    sfView *new_view;
    sfVector2i mouse_pos;
    sfVector2f mous_resize;
    sfVector2f view_size;
    sfVector2f view_pos;
    sfImage *logo;
    int frame;
    int screen_st;
    int music;
    int effect;
} head_t;

typedef struct rpg {
    music_t *music;
    head_t *head;
    bg_t *bg;
    utils_t *utils;
    game_t *game;
    hero_in_t *hero;
    monster_in_t *monster;
    char *help;
} rpg_t;

    void set_music_end(rpg_t *rpg);
    void clean_all(rpg_t *rpg);
    void set_music(rpg_t *rpg);
    void text_file(rpg_t *rpg);
    int helperprint(rpg_t *rpg);
    rpg_t *init_manage(rpg_t *rpg);
    void event_save(rpg_t *rpg);
    void save_3(rpg_t *rpg);
    void save_2(rpg_t *rpg);
    int main_manage(rpg_t *rpg);
    char *infile2(rpg_t *rpg, char *tmp);
    void event_manage(rpg_t *rpg);
    void event_fullscreen(rpg_t *rpg);
    void event_close(rpg_t *rpg);
    void window_manage(rpg_t *rpg);
    sfSprite *get_sprite(sfTexture *image);
    sfVector2f get_vector(float x, float y);
    sfIntRect get_rect(int top, int left, int width, int height);
    int is_clicked(rpg_t *rpg, button_t *button);
    void is_on_manage(rpg_t *rpg);
    void init_pos_button(bg_t *bg);
    void event_fullscreen_click(rpg_t *rpg);
    void get_text(rpg_t *rpg, text_t *text);
    void event_slider_frame(rpg_t *rpg, slider_t *slider, float min, int *c);
    void event_slider(rpg_t *rpg, slider_t *slider, float min, int *c);
    void window_settings(rpg_t *rpg);
    slider_t *init_slider(sfVector2f tracksize, sfVector2f trackPosition,
    float range, float thumbRadius);
    button_t *init_button(sfTexture *init, sfIntRect rect);
    text_t *init_text(sfVector2f vect, sfColor color,
    int size, char *str);
    opt_t *init_opt(void);
    void event_click_effect(rpg_t *rpg);
    void event_click_music(rpg_t *rpg);
    void event_click_menu(rpg_t *rpg);
    void event_click_settings(rpg_t *rpg);
    void window_play(rpg_t *rpg);
    play_t *init_playm(bg_t *bg);
    void init_pos_playm(play_t *playm);
    void event_play_save(rpg_t *rpg);
    void window_game(rpg_t *rpg);
    void event_fade(rpg_t *rpg);
    void init_pos_champ(champ_t *champ);
    champ_t *init_champ(void);
    void event_champ(rpg_t *rpg);
    void anim_attack3(rpg_t *rpg, sfSprite *champ);
    void show_map(rpg_t *rpg);
    monster_t *init_monster(void);
    void is_on_manage_game(rpg_t *rpg);
    void hp_manage(rpg_t *rpg);
    void xp_manage(rpg_t *rpg);
    void skills_main(rpg_t *rpg);
    void hp_algo(rpg_t *rpg);
    void esc_main(rpg_t *rpg);
    void set_text_position(text_t *text, sfVector2f position);
    void event_click_esc(rpg_t *rpg);
    void window_inv(rpg_t *rpg);
    void atck_algo(rpg_t *rpg);
    void def_algo(rpg_t *rpg);
    void window_crampteur(rpg_t *rpg);
    void coin_manage(rpg_t *rpg);
    void coins_anim(rpg_t *rpg, sfSprite *coins, coins_t *co);
    void event_crampteur(rpg_t *rpg);
    void window_home(rpg_t *rpg);
    void speed_algo(rpg_t *rpg);
    void def_algo(rpg_t *rpg);
    void atck_algo(rpg_t *rpg);
    void window_quest(rpg_t *rpg);
    void getinfo(rpg_t *rpg);
    void get_text_all(rpg_t *rpg);
    char *wichsave(char *file);
    void window_esc_settext(rpg_t *rpg, sfVector2f healthBarPos);
    void window_esc_addon(rpg_t *rpg, sfVector2f healthBarPos);
    void window_esc_addon2(rpg_t *rpg);
    void window_esc_slide(rpg_t *rpg);
    void window_esc_slide_pos(slider_t *slider, sfVector2f pos);
    void window_esc_textdr(rpg_t *rpg);
    void window_esc_start(rpg_t *rpg, sfVector2f healthBarPos);
    button_t *init_button_rec(sfTexture *init);
    void event_esc_press(rpg_t *rpg);
    void event_inv_press(rpg_t *rpg);
    void monster_animation(rpg_t *rpg, monster_sp_t *monster, int spawn2);
    void show_particles(rpg_t *rpg);
    int hp_decreased(rpg_t *rpg);
    void algo_quest(rpg_t *rpg);
    void event_pot(rpg_t *rpg);
    void algo_pot(rpg_t *rpg);
    void algo_tp(rpg_t *rpg);
    void event_tp(rpg_t *rpg);
    bg_t *init_bg(void);
    xp_t *init_xp(void);
    void window_inv_dr_2(rpg_t *rpg);
    void window_esc_dr_2(rpg_t *rpg, sfVector2f healthBarPos);
    void loot(rpg_t *rpg);
    void test_all_monster(rpg_t *rpg, monster_sp_t *monster, int dist);
    void algo_loot(rpg_t *rpg, monster_sp_t *monster, int i);
    void monster_rest(rpg_t *rpg);
    void kill_monster(rpg_t *rpg);
    void pnj_browse_sprite(int left, int lenx, sfVector2i addon, pnjst_t *pnj);
    void browse_sprite(int left, int lenx, sfVector2i addon, hero_t *hero);
    void pnj_animation(rpg_t *rpg);
    void window_game_map(rpg_t *rpg);
    void character_animation(rpg_t *rpg, sfSprite *champ, hero_t *hero);
    void window_vague2(rpg_t *rpg);
    void move_monster(rpg_t *rpg, monster_sp_t *monster);
    void end_take_damage(rpg_t *rpg, monster_sp_t *monster, int i);
    void end_move(rpg_t *rpg, float speed, int i, monster_sp_t *monster);
    void dealt_damage(rpg_t *rpg);
    void save_1(rpg_t *rpg);

#endif /* !RPG_H_ */
