/*
** EPITECH PROJECT, 2019
** runner
** File description:
** runner
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef enum
{
    MAIN,
    GAME,
    QUIT,
    RESTART,
    PAUSE,
    TUTO,
    LOSE,
    WON
} STATUS;

typedef enum
{
    RUNNER,
    WIN,
    JUMPING,
    HIT,
    SLIDING,
    BACK,
    MIDBACK,
    MID,
    MIDFRONT,
    FRONT
} TYPE;

typedef struct mode_s
{
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfText *text;
    sfFont *font;
    sfMusic *music;
    sfSound *jump;
    sfSoundBuffer *buffer;
    char *map;
    STATUS status;
} video_mode_t;

typedef struct game_obj_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfClock *clock;
    int speed;
    int limit;
    float anim;
    sfClock *gravity;
    sfBool is_dead;
    TYPE type;
} game_obj_t;

typedef struct button_s
{
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    STATUS effect;
} button_t;


typedef struct ptr_s
{
    STATUS type;
    void (*func)(game_obj_t *map,
    video_mode_t *video, game_obj_t *player, game_obj_t *obstacles);
} ptr_t;

#include "my.h"

#endif /* RUNNER_H_ */