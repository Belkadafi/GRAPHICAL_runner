/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** mouvement
*/

#include "runner.h"

game_obj_t create_obj(char *filepath,
sfVector2f scale, sfVector2f position, sfIntRect rect)
{
    game_obj_t game_obj;

    game_obj.sprite = sfSprite_create();
    game_obj.texture = sfTexture_createFromFile(filepath, NULL);
    game_obj.clock = sfClock_create();
    game_obj.scale = scale;
    game_obj.pos = position;
    game_obj.rect = rect;
    game_obj.gravity = sfClock_create();
    sfSprite_setTexture(game_obj.sprite, game_obj.texture, sfTrue);
    sfSprite_setTextureRect(game_obj.sprite, game_obj.rect);
    sfSprite_setScale(game_obj.sprite, game_obj.scale);
    sfSprite_setPosition(game_obj.sprite, game_obj.pos);
    return (game_obj);
}

float get_speed(game_obj_t *obj)
{
    sfTime time;
    float seconds;

    if (obj->type != JUMPING) {
        sfClock_restart(obj->gravity);
        return (0);
    }
    time = sfClock_getElapsedTime(obj->gravity);
    seconds = time.microseconds / 1000000.0;
    return (seconds);
}

void move_player(game_obj_t *player, sfIntRect rect, int limit)
{
    static TYPE type = RUNNER;

    if (player->type != type) {
        player->rect = rect;
        player->speed = 50;
        player->limit = limit;
        type = player->type;
    }
    if (player->type != RUNNER && player->type != JUMPING
    && player->rect.left == limit)
        player->type = RUNNER;
    move_it(player);
}

void create_map(game_obj_t *parallax)
{
    char *filepaths[] = {"Textures/rafik.png"\
    , "Textures/rafik1.png", "Textures/rafik2.png"\
    , "Textures/rafik3.png", "Textures/rafik4.png"};
    int speed[] = {0, 1, 6, 6, 12};

    for (int i = 0; i < 5; i += 1) {
        parallax[i].sprite = sfSprite_create();
        parallax[i].clock = sfClock_create();
        parallax[i].texture = sfTexture_createFromFile(filepaths[i], NULL);
        sfSprite_setTexture(parallax[i].sprite, parallax[i].texture, sfTrue);
        sfSprite_setScale(parallax[i].sprite, (sfVector2f){0.75, 0.75});
        if (i == 3 || i == 2) {
            sfSprite_setScale(parallax[i].sprite, (sfVector2f){0.75, 0.5});
            sfSprite_setPosition(parallax[i].sprite, (sfVector2f){0, 200});
        }
        parallax[i].speed = speed[i];
        parallax[i].limit = 1920;
        parallax[i].rect = (sfIntRect){0, 0, 1920, 1080};
        parallax[i].anim = 0.01;
    }
}

void get_y_position(float t, float alpha, game_obj_t *player)
{
    float y = 0;
    static float h = -0.75;

    t += 0.3f;
    y = h * (9.8f * t * t);
    y += t * sin(alpha);
    y *= 2;
    if (y < -8) {
        sfClock_restart(player->gravity);
        h *= -1;
    }
    player->pos.y += y;
    if (player->pos.y > 590) {
        player->pos.y = 590;
        h *= -1;
        player->type = RUNNER;
    }
}