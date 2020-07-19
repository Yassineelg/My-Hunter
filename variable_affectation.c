/*
** EPITECH PROJECT, 2019
** variable_affectation.c
** File description:
** partition my.h
*/

#include "my.h"

void variable_affectation3(my_t *hunt)
{
    hunt->position_score.x = 610;
    hunt->position_score.y = 600;
    hunt->position_highest_score.x = 1210;
    hunt->position_highest_score.y = 600;
    hunt->font = sfFont_createFromFile("south park.ttf");
    hunt->txt_highest_score = sfText_create();
    hunt->txt_score = sfText_create();
    hunt->clock_kayle = sfClock_create();
    hunt->clock_bad_kayle = sfClock_create();
    hunt->hit = sfMusic_createFromFile("hit.ogg");
}

void variable_affectation2(my_t *hunt)
{
    hunt->background = sfTexture_createFromFile("background.jpg", NULL);
    hunt->background_sprite = sfSprite_create();
    hunt->rules = sfTexture_createFromFile("rules.jpg", NULL);
    hunt->rules_sprite = sfSprite_create();
    hunt->cartman = sfTexture_createFromFile("cartman.png", NULL);
    hunt->cartman_sprite = sfSprite_create();
    hunt->kayle = sfTexture_createFromFile("Kaylequimarche.png", NULL);
    hunt->kayle_sprite = sfSprite_create();
    hunt->bad_kayle = sfTexture_createFromFile("bad_kayle.png", NULL);
    hunt->bad_kayle_sprite = sfSprite_create();
    hunt->map = sfTexture_createFromFile("map.jpg", NULL);
    hunt->map_sprite = sfSprite_create();
    hunt->end = sfTexture_createFromFile("end.jpg", NULL);
    hunt->end_sprite = sfSprite_create();
    hunt->mouse = sfTexture_createFromFile("mouse.png", NULL);
    hunt->mouse_sprite = sfSprite_create();
    hunt->generic = sfMusic_createFromFile("generic.ogg");
    hunt->game = sfMusic_createFromFile("music.ogg");
    hunt->emmerde = sfMusic_createFromFile("emmerde.ogg");
    variable_affectation3(hunt);
}

void reset_variables(my_t *hunt)
{
    hunt->status = 0;
    hunt->speed_x = 5;
    hunt->speed_y = 2;
    hunt->deaths = 0;
    hunt->score = 0;
    hunt->position_kayle.x = -200;
    hunt->position_kayle.y = (rand() % 430) + 495;
    hunt->rect_cartman.left = 0;
}

void variable_affectation(my_t *hunt)
{
    sfVideoMode resolution = {1920, 1080, 32};

    reset_variables(hunt);
    hunt->rect_cartman.height = 245;
    hunt->rect_cartman.width = 267;
    hunt->rect_kayle.left = 116;
    hunt->rect_kayle.height = 150;
    hunt->rect_kayle.width = 116;
    hunt->rect_bad_kayle.height = 300;
    hunt->rect_bad_kayle.width = 181;
    hunt->position_cartman.x = 840;
    hunt->position_cartman.y = 400;
    hunt->position_bad_kayle.x = 10;
    hunt->position_bad_kayle.y = 700;
    variable_affectation2(hunt);
    hunt->window = sfRenderWindow_create(resolution, "My Hunter",
                                        sfFullscreen, NULL);
}