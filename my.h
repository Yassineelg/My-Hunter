/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes.
*/
#ifndef MY_H
#define MY_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


char *my_rev_putnbr(int nb);
int my_strlen(char *str);
int my_getnbr(char const *str);

typedef struct my_struct_s {
    sfTexture *background;
    sfSprite *background_sprite;
    sfTexture *rules;
    sfSprite *rules_sprite;
    sfTexture *cartman;
    sfSprite *cartman_sprite;
    sfTexture *end;
    sfSprite *end_sprite;
    sfTexture *map;
    sfSprite *map_sprite;
    sfTexture *kayle;
    sfSprite *kayle_sprite;
    sfTexture *bad_kayle;
    sfSprite *bad_kayle_sprite;
    sfTexture *mouse;
    sfSprite *mouse_sprite;
    sfVector2f mouse_position;
    sfVector2i mouse_positiion;
    sfEvent events;
    sfRenderWindow *window;
    sfClock *clock_kayle;
    sfClock *clock_bad_kayle;
    sfIntRect rect_cartman;
    sfIntRect rect_kayle;
    sfIntRect rect_bad_kayle;
    sfVector2f position_cartman;
    sfVector2f position_kayle;
    sfVector2f position_bad_kayle;
    sfVector2f position_score;
    sfVector2f position_highest_score;
    sfMusic *generic;
    sfMusic *game;
    sfMusic *emmerde;
    sfMusic *hit;
    sfFont *font;
    sfText *txt_highest_score;
    sfText *txt_score;
    FILE *fp;
    char *highest_score_str;
    int score;
    int highest_score;
    int mode;
    int status;
    int deaths;
    float speed_x;
    float speed_y;
} my_t;

void openned_window(my_t *hunt);
void menu(my_t *hunt);
void game_easy(my_t *hunt);
void game_normal(my_t *hunt);
void game_hard(my_t *hunt);
void lose_screen(my_t *hunt);
void rules_screen(my_t *hunt);
void kayle_anime_and_move_e(my_t *hunt);
void kayle_anime_and_move_n2(my_t *hunt);
void kayle_anime_and_move_n(my_t *hunt);
void kayle_anime_and_move_h2(my_t *hunt, int a);
void kayle_anime_and_move_h(my_t *hunt);
void bad_kayle_anime(my_t *hunt);
void cursor(my_t *hunt);
void menu_event2(my_t *hunt);
void menu_events(my_t *hunt);
void hitting_kyle_event2(my_t *hunt, int a);
void hitting_kyle_event(my_t *hunt);
void events(my_t *hunt);
void variable_affectation3(my_t *hunt);
void variable_affectation2(my_t *hunt);
void reset_variables(my_t *hunt);
void variable_affectation(my_t *hunt);
void setup2(my_t *hunt);
void setup(my_t *hunt);

#endif