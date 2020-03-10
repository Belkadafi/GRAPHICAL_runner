/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** animations
*/

#include "runner.h"

void move_rect(sfIntRect *rect, int offset, int max)
{
    if (rect->left <= max)
        rect->left += offset;
    else
        rect->left = 0;
}

int my_clock(sfClock *clock, float max)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > max) {
        sfClock_restart(clock);
        return (1);
    }
    return (0);
}

void move_it(game_obj_t *back)
{
    if (my_clock(back->clock, back->anim))
        move_rect(&back->rect, back->speed, back->limit);
    sfSprite_setTextureRect(back->sprite, back->rect);
}

void anim_background(game_obj_t *parallax,
game_obj_t *obstacles, game_obj_t *player)
{
    for (int i = 0; i < 5; i += 1)
        move_it(&parallax[i]);
    anim_obstacles(obstacles);
}

void  anim_obstacles(game_obj_t *obstacles)
{
    int nb = get_nb("haha");

    for (int i = 0; i < nb; i += 1) {
        if (my_clock(obstacles[i].gravity, 0.1)) {
            move_rect(&obstacles[i].rect,
            obstacles[i].speed, obstacles[i].limit);
            sfSprite_setTextureRect(obstacles[i].sprite, obstacles[i].rect);
        }
        if (my_clock(obstacles[i].clock, 0.01)) {
            if (obstacles[i].type == HIT)
                obstacles[i].pos.x -= 3;
            obstacles[i].pos.x -= 9;
            sfSprite_setPosition(obstacles[i].sprite, obstacles[i].pos);
        }
    }
}