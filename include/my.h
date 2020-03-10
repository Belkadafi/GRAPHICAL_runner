/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

void game_init(char *);
void game_loop(game_obj_t *map, video_mode_t *video,
game_obj_t *game_obj, game_obj_t *obstacles);
void anim_background(game_obj_t *parallax, game_obj_t *, game_obj_t *);
void move_it(game_obj_t *back);
void analyse_event(video_mode_t *video, game_obj_t *player);
float get_speed(game_obj_t *obj);
void get_y_position(float t, float alpha, game_obj_t *obj);
void move_player(game_obj_t *player, sfIntRect rect, int limit);
void sprite_draw(game_obj_t *map, game_obj_t *player,
video_mode_t *video, game_obj_t *obstacles);
int my_clock(sfClock *clock, float max);
game_obj_t create_obj(char *filepath,
sfVector2f scale, sfVector2f position, sfIntRect rect);
game_obj_t *get_obstacles(char *filepath, video_mode_t *);
int get_nb(char *buffer);
void anim_obstacles(game_obj_t *obstacles);
void manage_colision(game_obj_t *obstacles, game_obj_t *player,
video_mode_t *);
void losing_loop(game_obj_t *map,
video_mode_t *video, game_obj_t *player, game_obj_t *obstacles);
void create_map(game_obj_t *parallax);
void my_crossroad(game_obj_t *map,
video_mode_t *video, game_obj_t *player, game_obj_t *obstacles);
void winning_loop(game_obj_t *map,
video_mode_t *video, game_obj_t *player, game_obj_t *obstacles);
void main_loop(game_obj_t *map,
video_mode_t *video, game_obj_t *player, game_obj_t *obstacles);
void destroy_obj(game_obj_t *obj);
void get_obs(game_obj_t *obstacles, char *buffer, int j);
void create_button(button_t *obj, char *filpath, char *string, sfVector2f pos);
void init_main(game_obj_t *main, button_t *button);
int my_strlen(char const *s);
void manage_button(button_t *obj, sfVector2i mouse_temp, video_mode_t *video);
void pause_loop(game_obj_t *map,
video_mode_t *video, game_obj_t *player, game_obj_t *obstacles);
void init_pause(game_obj_t *pause, button_t *button);
void init_loose(sfText **text, sfText **text2, sfFont **font);
void manage_win(video_mode_t *video);
void init_win(sfText **text, sfFont **font, game_obj_t *game_over);

#endif /* !MY_H_ */