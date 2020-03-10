/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** init_loops
*/

#include "runner.h"

int my_strlen(char const *s)
{
    int i = 0;

    for (; s[i]; i += 1);
    return i;
}

void init_win(sfText **text, sfFont **font, game_obj_t *game_over)
{
    *text = sfText_create();
    *font = sfFont_createFromFile("Textures/Subspace-Bold-Italic.ttf");
    *game_over = create_obj("Textures/winner.jpg", (sfVector2f){2, 2},
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 834, 500});
    sfText_setFont(*text, *font);
    sfText_setString(*text, "          Press Space to go to replay"
    " Press escape to quit");
    sfText_setColor(*text, sfRed);
    sfText_setCharacterSize(*text, 50);
    sfText_setPosition(*text, (sfVector2f){0, 700});
}

void init_pause(game_obj_t *pause, button_t *button)
{
    char *text[] = {"CONTINUE", "RESTART", "MAIN MENU", "QUIT"};

    *pause = create_obj("Textures/background.png", (sfVector2f){0.75, 0.75},
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    for (int i = 0; i < 4; i += 1) {
        create_button(&button[i], "Textures/Subspace.ttf",
        text[i], (sfVector2f){0, i * 200});
        button[i].effect = GAME + i;
    }
}

void init_loose(sfText **text, sfText **text2, sfFont **font)
{
    *text = sfText_create();
    *text2 = sfText_create();
    *font = sfFont_createFromFile("Textures/Subspace.ttf");
    sfText_setFont(*text, *font);
    sfText_setFont(*text2, *font);
    sfText_setCharacterSize(*text, 150);
    sfText_setCharacterSize(*text2, 50);
    sfText_setColor(*text, sfRed);
    sfText_setColor(*text2, sfBlack);
    sfText_setString(*text, "GAME\n  OVER");
    sfText_setString(*text2, "PRESS SPACE TO RESTART OR"
    " PRESS ESCAPE TO RAGE QUIT");
    sfText_setPosition(*text, (sfVector2f){500, 220});
    sfText_setPosition(*text2, (sfVector2f){200, 600});
}

void init_main(game_obj_t *main, button_t *button)
{
    char *text[] = {"PLAY", "  ", "QUIT"};

    *main = create_obj("Textures/background.png", (sfVector2f){0.75, 0.75},
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    for (int i = 0; i < 3; i += 1) {
        create_button(&button[i], "Textures/Subspace-Bold-Italic.ttf",
        text[i], (sfVector2f){i * 550, 630});
        button[i].effect = GAME + i;
    }
}