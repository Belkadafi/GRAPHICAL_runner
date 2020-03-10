/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** crossroad
*/

#include "runner.h"

static const ptr_t funct[] =
{
    {GAME, game_loop},
    {LOSE, losing_loop},
    {WON, winning_loop},
    {PAUSE, pause_loop},
    {MAIN, main_loop},
    {0, NULL}
};

void restart_loop(video_mode_t *video, game_obj_t *map)
{
    int j = get_nb("ihfz");

    for (int i = 0; i < j; i += 1)
        destroy_obj(&map[i]);
    j = 0;
    get_obs(map, video->map, j);
    video->status = GAME;
}

void pause_loop(game_obj_t *map,
video_mode_t *video, game_obj_t *player, game_obj_t *obstacles)
{
    static game_obj_t main;
    static int test = 0;
    static button_t button[4];

    if (test == 0) {
        init_pause(&main, button);
        test = 1;
    }
    for (int i = 0; i < 4; i += 1) {
        manage_button(&button[i],
        sfMouse_getPositionRenderWindow(video->window),
        video);
    }
    sfRenderWindow_drawSprite(video->window, main.sprite, NULL);
    for (int i = 0; i < 4; i += 1)
        sfRenderWindow_drawText(video->window, button[i].text, NULL);
}

void main_loop(game_obj_t *map,
video_mode_t *video, game_obj_t *player, game_obj_t *obstacles)
{
    static game_obj_t main;
    static int test = 0;
    static button_t button[3];

    if (test == 0) {
        init_main(&main, button);
        test = 1;
    }
    for (int i = 0; i < 3; i += 1) {
        manage_button(&button[i],
        sfMouse_getPositionRenderWindow(video->window),
        video);
    }
    sfRenderWindow_drawSprite(video->window, main.sprite, NULL);
    for (int i = 0; i < 3; i += 1)
        sfRenderWindow_drawText(video->window, button[i].text, NULL);
}

void my_crossroad(game_obj_t *map,
video_mode_t *video, game_obj_t *player, game_obj_t *obstacles)
{
    sfMusic_play(video->music);
    int nb = get_nb("ibz");
    game_obj_t *tempo = obstacles;

    sfRenderWindow_setFramerateLimit(video->window, 60);
    while (sfRenderWindow_isOpen(video->window)) {
        if (obstacles[nb - 1].pos.x <= 50)
            video->status = WON;
        sfRenderWindow_clear(video->window, sfBlack);
        analyse_event(video, player);
        for (int i = 0; funct[i].func != NULL; i += 1) {
            if (funct[i].type == video->status)
                funct[i].func(map, video, player, obstacles);
        }
        if (video->status == RESTART)
            restart_loop(video, obstacles);
        sfRenderWindow_display(video->window);
    }
}