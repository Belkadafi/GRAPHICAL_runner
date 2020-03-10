/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** win_and_loose
*/

#include "runner.h"

void manage_win(video_mode_t *video)
{
    if (video->event.key.code == sfKeySpace &&
        video->event.type == sfEvtKeyPressed)
        video->status = RESTART;
    if (video->event.key.code == sfKeyEscape &&
        video->event.type == sfEvtKeyPressed)
        sfRenderWindow_close(video->window);
}

void winning_loop(game_obj_t *map,
video_mode_t *video, game_obj_t *player, game_obj_t *obstacles)
{
    static game_obj_t game_over;
    static sfText *text;
    static sfFont *font;
    static int test = 0;

    if (test == 0) {
        init_win(&text, &font, &game_over);
        test = 1;
    }
    for (int i = 0; i < 5; i += 1)
        sfRenderWindow_drawSprite(video->window, map[i].sprite, NULL);
    sfRenderWindow_drawSprite(video->window, game_over.sprite, NULL);
    sfRenderWindow_drawText(video->window, text, NULL);
}

void losing_loop(game_obj_t *map,
video_mode_t *video, game_obj_t *player, game_obj_t *obstacles)
{
    static sfText *text;
    static sfFont *font;
    static sfText *text2;
    static int test = 0;

    if (test == 0) {
        init_loose(&text, &text2, &font);
        test = 1;
    }
    for (int i = 0; i < 5; i += 1)
        sfRenderWindow_drawSprite(video->window, map[i].sprite, NULL);
    sfRenderWindow_drawText(video->window, text2, NULL);
    sfRenderWindow_drawText(video->window, text, NULL);
}