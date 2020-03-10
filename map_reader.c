/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** map_reader
*/

#include "runner.h"

void get_ennemy(game_obj_t *obstacles, char *buffer, int i, int *j)
{
    if (buffer[i] == '3') {
        obstacles[*j] = create_obj("Textures/ennemy.png", (sfVector2f){2, 2},
        (sfVector2f){i * 300 + 1000, 620}, (sfIntRect){0, 322, 50, 58});
        obstacles[*j].speed = 68;
        obstacles[*j].limit = 141;
        obstacles[*j].type = HIT;
        *j += 1;
    }
    if (buffer[i] == '4') {
        obstacles[*j] = create_obj("Textures/flag.png", (sfVector2f){1, 1},
        (sfVector2f){i * 200 + 1000, 420}, (sfIntRect){0, 0, 160, 320});
        obstacles[*j].type = WIN;
        obstacles[*j].speed = 160;
        obstacles[*j].limit = 980;
        *j += 1;
    }
    obstacles[*j].is_dead = sfFalse;
}

void get_obs(game_obj_t *obstacles, char *buffer, int j)
{
    for (int i = 0; buffer[i] != '\0'; i += 1) {
        if (buffer[i] == '1') {
            obstacles[j] = create_obj("Textures/pyke.png", (sfVector2f){3, 2},
            (sfVector2f){i * 200 + 1000, 720}, (sfIntRect){0, 0, 32, 32});
            obstacles[j].speed = 0;
            obstacles[j].type = JUMPING;
            obstacles[j].limit = 5;
            j += 1;
        }
        if (buffer[i] == '2') {
            obstacles[j] = create_obj("Textures/slide.png", (sfVector2f){1, 1},
            (sfVector2f){i * 200 + 1000, 520}, (sfIntRect){0, 0, 165, 165});
            obstacles[j].speed = 0;
            obstacles[j].type = SLIDING;
            obstacles[j].limit = 5;
            j += 1;
        }
        get_ennemy(obstacles, buffer, i, &j);
    }
}

int get_nb(char *buffer)
{
    int nb = 0;
    static int test = 0;
    static int result = 0;

    if (test == 0) {
        for (int i = 0; buffer[i]; i += 1) {
            if (buffer[i] == '1' || buffer[i] == '2' || buffer[i] == '3'
            || buffer[i] == '4')
                nb += 1;
        }
        test = 1;
        result = nb;
        return (nb);
    }
    else
        return result;
}

game_obj_t *get_obstacles(char *filepath, video_mode_t *mode)
{
    FILE *stream = fopen(filepath, "r");
    struct stat st;
    size_t len = 0;
    char *buffer;
    game_obj_t *obstacles;
    int j = 1;

    j -= 1;
    stat(filepath, &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    getline(&buffer, &len, stream);
    mode->map = buffer;
    buffer[st.st_size] = 0;
    obstacles = malloc(sizeof(game_obj_t) * (get_nb(buffer) + 1));
    get_obs(obstacles, buffer, j);
    return (obstacles);
}