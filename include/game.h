/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** game.h
*/

#ifndef GAME_H
    #define GAME_H
    #define MAP rpg->game->map
    #include "my.h"
    #include "skills.h"
    #include "inventory.h"
    #include "pnj.h"
    #include "rpg.h"
    #define WALL_PERCENTAGE 45
    #define ITERATIONS 6
    #define CHEST_PERCENTAGE 1
    #define TILE_SIZE 32.0f
    #define GRID_WIDTH 1000
    #define GRID_HEIGHT 1000
    #define UPPER_LEFT_CORNER 3 + 0 * 32
    #define LATERAL_UPPER_BAR 4 + 0 * 32
    #define UPPER_RIGHT_CORNER 5 + 0 * 32
    #define INSIDE_BOTTOM_RIGHT_CORNER 6 + 0 * 32
    #define INSIDE_BOTTOM_LEFT_CORNER 7 + 0 * 32
    #define VERTICAL_LEFT_BAR 3 + 1 * 32
    #define INSIDE_BLOCK 7 + 2 * 32
    #define VERTICAL_RIGHT_BAR 5 + 1 * 32
    #define INSIDE_UP_RIGHT_CORNER 6 + 1 * 32
    #define INSIDE_UP_LEFT_CORNER 7 + 1 * 32
    #define DOWN_LEFT_CORNER 3 + 2 * 32
    #define LATERAL_DOWN_BAR 4 + 2 * 32
    #define DOWN_RIGHT_CORNER 5 + 2 * 32
    #define FULL_BLOCK 6 + 2 * 32
    #define MAX_PARTICLES 50

typedef struct map_s {
    sfTexture *texture;
    sfVertexArray *vertexArray;
    sfRenderStates renderStates;
    sfVector2f worldPos;
    float tileSize;
    int gridWidth;
    int gridHeight;
    int wallPercentage;
    int iterations;
    int **map;
    sfBool is_generated;
} map_t;

typedef struct esc_s {
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
} esc_t;

typedef struct corner_info {
    int up, down, left, right, up_left, up_right, down_left, down_right;
} corner_info_t;

typedef struct player_s {
    sfSprite *sprite;
    sfVector2f position;
    float speed;
    int status;
} player_t;

typedef struct particles_s {
    sfVector2f position;
    sfVector2f velocity;
    float gravity;
    float size;
    sfColor color;
    float life;
    sfClock *clock;
} particles_t;

typedef struct game_s {
    skills_t *skills;
    pnj_t *pnj;
    esc_t *esc;
    inv_t *inv;
    map_t *map;
    particles_t *particles;
    sfClock *clock;
    sfView *view;
    float speed;
    int settings;
    int inv_st;
    int end;
    int anim_ack;
    player_t *player;
    text_t *death;
} game_t;

    int is_collidable(int tile);
    int is_colliding(int** map, sfFloatRect player_rect, float tileSize);
    void check_collision(player_t *player,
    float deltaSeconds, int** map, float tileSize);
    void move_player(player_t *player, float deltaSeconds);
    game_t* init_game(void);
    void generate_map(game_t *game);
    void createQuad(sfVertexArray* vertexArray,
    sfVector2f coord, float tileSize, sfVector2f tile);
    int** generateProceduralMap(int width,
    int height, int wallPercentage, int iterations);
    void create_quad(sfVertexArray* vertexArray, sfVector2f coord,
                                    float tileSize, sfVector2f tile);
    int** procedural_map(sfVector2i,
    int wallPercentage, int iterations);
    void update_player_position(player_t *player,
    float deltaSeconds, int** map, float tileSize);
    esc_t *init_esc(void);
    void place_corners(int **map, int **original_map,
    sfVector2i tile, sfVector2i size);
    void create_lobby(int** map, sfVector2i size, sfVector2i lobbySize);
    int random_int(int min, int max);
    void free_map(int** map, int size);
    int **copy_map(int **map, sfVector2i size);
    void place_corners(int **map, int **original_map,
    sfVector2i tile, sfVector2i size);
    void initialize_all_particles(particles_t *particles);
#endif
