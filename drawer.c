/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** drawer
*/

#include "runner.h"

void manage_button(button_t *obj, sfVector2i mouse_temp, video_mode_t *video)
{
    sfVector2f mouse = {mouse_temp.x, mouse_temp.y};
    char const *string = sfText_getString(obj->text);

    if (mouse.x > obj->pos.x &&
    mouse.x < (obj->pos.x + (my_strlen(string) - 1) * 130) &&
    mouse.y > obj->pos.y && mouse.y < obj->pos.y + 130) {
        sfText_setCharacterSize(obj->text, 170);
        sfText_setColor(obj->text, sfRed);
    }
    else {
        sfText_setCharacterSize(obj->text, 130);
        sfText_setColor(obj->text, sfBlack);
    }
}

void create_button(button_t *obj, char *filpath, char *string, sfVector2f pos)
{
    obj->text = sfText_create();
    obj->font = sfFont_createFromFile(filpath);
    obj->pos = pos;
    sfText_setFont(obj->text, obj->font);
    sfText_setPosition(obj->text, pos);
    sfText_setCharacterSize(obj->text, 130);
    sfText_setString(obj->text, string);
    sfText_setColor(obj->text, sfBlack);
}

char *my_revgetnbr(int nb)
{
    int len = 0;
    char *dest;
    int i = 0;

    if (nb == 0)
        return ("0\0");
    for (int tempo = nb; tempo > 0; tempo = tempo/10)
        len += 1;
    dest = malloc(sizeof(char) * (len + 2));
    for (int tempo = pow(10, len - 1); tempo > 0;) {
        dest[i] = (nb / tempo) % 10 + '0';
        i += 1;
        tempo = tempo / 10;
    }
    dest[i] = 0;
    return (dest);
}

void update_score(game_obj_t *obstacles, video_mode_t *mode)
{
    static int test = 0;
    int i = get_nb("lit");
    float len = (i * 200 + 1000) - obstacles[i - 1].pos.x;
    float percent = (len / (i * 200 + 1000)) * 100;

    if (test == 0)
        test = obstacles[i - 1].pos.x + 9;
    len = test - obstacles[i - 1].pos.x;
    percent = (len / test) * 100;
    sfText_setString(mode->text, my_revgetnbr((int)percent));
    sfRenderWindow_drawText(mode->window, mode->text, NULL);
}

void sprite_draw(game_obj_t *map, game_obj_t *player,
video_mode_t *video, game_obj_t *obstacles)
{
    int nb = get_nb("ojd");

    sfSprite_setPosition(player->sprite, player->pos);
    for (int i = 0; i < 5; i += 1)
        sfRenderWindow_drawSprite(video->window, map[i].sprite, NULL);
    sfRenderWindow_drawSprite(video->window, player->sprite, NULL);
    for (int i = 0; i < nb; i += 1)
        sfRenderWindow_drawSprite(video->window, obstacles[i].sprite, NULL);
    update_score(obstacles, video);
}