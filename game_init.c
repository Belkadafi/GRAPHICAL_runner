/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** game_init
*/

#include "runner.h"

void create_text(video_mode_t *video)
{
    video->text = sfText_create();
    video->font = sfFont_createFromFile("Textures/AldotheApache.ttf");
    sfText_setFont(video->text, video->font);
    sfText_setColor(video->text, sfMagenta);
    sfText_setCharacterSize(video->text, 50);
}

void create_video(video_mode_t *mode)
{
    sfVideoMode video = {1440, 810, 32};

    mode->mode = video;
    mode->window =
    sfRenderWindow_create(mode->mode, "MY_RUNNER", sfClose, NULL);
    create_text(mode);
    mode->music = sfMusic_createFromFile("Textures/music_runner.ogg");
    mode->buffer = sfSoundBuffer_createFromFile("Textures/jump.ogg");
    mode->jump = sfSound_create();
    sfSound_setBuffer(mode->jump, mode->buffer);
}

void destroy_obj(game_obj_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    sfClock_destroy(obj->clock);
    sfClock_destroy(obj->gravity);
}

void clean_up(game_obj_t *map, game_obj_t *player,
game_obj_t *obstacles, video_mode_t *video)
{
    int nb = get_nb("ozjef");

    for (int i = 0; i < 5; i += 1) {
        sfSprite_destroy(map[i].sprite);
        sfTexture_destroy(map[i].texture);
        sfClock_destroy(map[i].clock);
    }
    for (int i = 0; i < nb; i += 1)
        destroy_obj(&obstacles[i]);
    destroy_obj(player);
    sfText_destroy(video->text);
    sfFont_destroy(video->font);
    sfMusic_destroy(video->music);
    sfSound_destroy(video->jump);
    sfSoundBuffer_destroy(video->buffer);
    sfRenderWindow_destroy(video->window);
}

void game_init(char *filepath)
{
    video_mode_t video;
    game_obj_t map[5];
    game_obj_t player;
    game_obj_t *obstacles = get_obstacles(filepath, &video);

    video.status = MAIN;
    player.type = RUNNER;
    for (int i = 0; i < 5; i += 1) {
        map[i].type = i + BACK;
        map[i].is_dead = sfFalse;
    }
    create_video(&video);
    create_map(map);
    player = create_obj("Textures/chara.png", (sfVector2f){4, 4},
    (sfVector2f){-50, 590}, (sfIntRect){0, 37, 50, 37});
    player.speed = 50;
    player.limit = 200;
    player.anim = 0.1;
    my_crossroad(map, &video, &player, obstacles);
    clean_up(map, &player, obstacles, &video);
}