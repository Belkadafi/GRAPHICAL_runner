/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** game_loop
*/

#include "runner.h"

void manage_colision(game_obj_t *obstacles,
game_obj_t *player, video_mode_t *video)
{
    int nb = get_nb(".");

    for (int i = 0; i < nb; i += 1) {
        if (obstacles[i].pos.x <= 50 && obstacles[i].type != player->type
        && obstacles[i].pos.x >= 0 && obstacles[i].type != WIN)
            video->status = LOSE;
        if (obstacles[i].pos.x <= 50 && obstacles[i].type == player->type
        && obstacles[i].pos.x >= 0 && player->type == HIT)
            obstacles[i].is_dead = sfTrue;
    }
}

void manage_player(game_obj_t *player)
{
    if (player->type == RUNNER)
        move_player(player, (sfIntRect){0, 37, 50, 37}, 200);
    if (player->type == HIT)
        move_player(player, (sfIntRect){0, 222, 50, 37}, 300);
    if (player->type == SLIDING)
        move_player(player, (sfIntRect){0, 111, 50, 37}, 300);
}

void game_loop(game_obj_t *map, video_mode_t *video,
game_obj_t *player, game_obj_t *obstacles)
{
    static float t = 0;

        anim_background(map, obstacles, player);
        manage_colision(obstacles, player, video);
        manage_player(player);
        if (player->type == JUMPING) {
            move_player(player, (sfIntRect){0, 74, 50, 37}, 300);
            get_y_position(t, M_PI, player);
        }
        for (int i = 0; i < get_nb("zzek");i += 1)
            if (obstacles[i].is_dead == sfTrue) {
                obstacles[i].limit += 7 * obstacles[i].rect.width;
                obstacles[i].rect.left = obstacles[i].limit;
                obstacles[i].limit += 3 * obstacles[i].rect.width;
                obstacles[i].is_dead = sfFalse;
            }
        t = get_speed(player);
        sprite_draw(map, player, video, obstacles);
}