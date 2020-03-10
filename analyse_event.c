/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** analyse_event
*/

#include "runner.h"

void manage_main(video_mode_t *video, sfVector2i mouse)
{
    if (mouse.x > 0 && mouse.x < (3 * 130) &&
    mouse.y > 630 && mouse.y < 630 + 130 &&
    video->event.type == sfEvtMouseButtonPressed)
        video->status = GAME;
    if (mouse.x > 2 * 550 && mouse.x < 2 * 550 + (2 * 130) &&
    mouse.y > 630 && mouse.y < 630 + 130 &&
    video->event.type == sfEvtMouseButtonPressed)
        sfRenderWindow_close(video->window);
    if (mouse.x > 2 * 550 && mouse.x < 2 * 550 + (2 * 130) &&
    mouse.y > 630 && mouse.y < 630 + 130 &&
    video->event.type == sfEvtMouseButtonPressed)
        video->status = TUTO;
}

void manage_pause(video_mode_t *video, sfVector2i mouse)
{
    if (mouse.x > 0 && mouse.x < (7 * 130) &&
    mouse.y > 0 && mouse.y < 130 &&
    video->event.type == sfEvtMouseButtonPressed)
        video->status = GAME;
    if (mouse.x > 0 && mouse.x < (8 * 130) &&
    mouse.y > 400 && mouse.y < 400 + 130 &&
    video->event.type == sfEvtMouseButtonPressed)
        video->status = MAIN;
    if (mouse.x > 0 && mouse.x < (3 * 130) &&
    mouse.y > 600 && mouse.y < 600 + 130 &&
    video->event.type == sfEvtMouseButtonPressed)
        sfRenderWindow_close(video->window);
    if (mouse.x > 0 && mouse.x < (6 * 130) &&
    mouse.y > 200 && mouse.y < 200 + 130 &&
    video->event.type == sfEvtMouseButtonPressed)
        video->status = RESTART;
}

void manage_game(video_mode_t *video, game_obj_t *player, int *test)
{
    if (video->event.key.code == sfKeyEscape &&
    video->event.type == sfEvtKeyPressed)
        video->status = PAUSE;
    if ((video->event.key.code == sfKeySpace || video->event.key.code == sfKeyZ) &&
    video->event.type == sfEvtKeyPressed && player->type != JUMPING) {
        player->type = JUMPING;
        *test = 1;
    }
    if (video->event.key.code == sfKeyD &&
    video->event.type == sfEvtKeyPressed && player->type != JUMPING)
        player->type = HIT;
    if (video->event.key.code == sfKeyS &&
    video->event.type == sfEvtKeyPressed && player->type != JUMPING)
        player->type = SLIDING;
}

void manage_lose(video_mode_t *video)
{
    if (video->event.key.code == sfKeySpace &&
    video->event.type == sfEvtKeyPressed)
        video->status = RESTART;
    if (video->event.key.code == sfKeyEscape &&
    video->event.type == sfEvtKeyPressed)
        sfRenderWindow_close(video->window);
}

void analyse_event(video_mode_t *video, game_obj_t *player)
{
    int test = 0;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(video->window);

    while (sfRenderWindow_pollEvent(video->window, &video->event)) {
        if (video->event.type == sfEvtClosed)
            sfRenderWindow_close(video->window);
        if (video->status == MAIN)
            manage_main(video, mouse);
        if (video->status == GAME)
            manage_game(video, player, &test);
        if (video->status == PAUSE)
            manage_pause(video, mouse);
        if (video->status == LOSE)
            manage_lose(video);
        if (video->status == WON)
            manage_win(video);
    }
    if (test == 1)
        sfSound_play(video->jump);
}