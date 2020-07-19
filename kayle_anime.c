/*
** EPITECH PROJECT, 2019
** kayle_anime
** File description:
** partitions my_hunter
*/

#include "my.h"

void kayle_anime_and_move_e(my_t *hunt)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(hunt->clock_kayle)) > 99)
    {
        hunt->rect_kayle.left += 116;
        if (hunt->rect_kayle.left >= 348)
            hunt->rect_kayle.left = 0;
        sfSprite_setTextureRect(hunt->kayle_sprite, hunt->rect_kayle);
        sfSprite_setTextureRect(hunt->cartman_sprite, hunt->rect_cartman);
        sfClock_restart(hunt->clock_kayle);
    }
    hunt->position_kayle.x += hunt->speed_x;
    if (hunt->position_kayle.x >= 1920) {
        hunt->position_kayle.x = -200;
        hunt->position_kayle.y = (rand() % 430) + 495;
        hunt->deaths += 1;
        hunt->rect_cartman.left += 270;
    }
}

void kayle_anime_and_move_n2(my_t *hunt)
{
    if (hunt->position_kayle.x >= 1920) {
        hunt->position_kayle.x = -200;
        hunt->position_kayle.y = (rand() % 430) + 495;
        hunt->deaths += 1;
        hunt->rect_cartman.left += 270;
    }
}

void kayle_anime_and_move_n(my_t *hunt)
{
    int i = rand() % 2;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(hunt->clock_kayle)) > 99)
    {
        hunt->rect_kayle.left += 116;
        if (hunt->rect_kayle.left >= 348)
            hunt->rect_kayle.left = 0;
        sfSprite_setTextureRect(hunt->kayle_sprite, hunt->rect_kayle);
        sfSprite_setTextureRect(hunt->cartman_sprite, hunt->rect_cartman);
        sfClock_restart(hunt->clock_kayle);
    }
    hunt->position_kayle.x += hunt->speed_x;
    if (i == 0)
        hunt->position_kayle.y += hunt->speed_y;
    if (hunt->position_kayle.y >= 900 || hunt->position_kayle.y <= 495)
        hunt->speed_y *= -1;
    kayle_anime_and_move_n2(hunt);
}

void kayle_anime_and_move_h2(my_t *hunt, int a)
{
    if (hunt->position_kayle.x >= 2150 || hunt->position_kayle.x <= -400) {
        hunt->position_kayle.x = 0;
        if (hunt->speed_x < 0)
                hunt->speed_x *= -1;
        if (a == 0) {
            hunt->position_kayle.x = 1920;
            hunt->speed_x *= -1;
        }
        hunt->position_kayle.y = (rand() % 430) + 495;
        hunt->deaths += 1;
        hunt->rect_cartman.left += 270;
    }
}

void kayle_anime_and_move_h(my_t *hunt)
{
    int i = rand() % 2;
    int a = rand() % 2;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(hunt->clock_kayle)) > 99)
    {
        hunt->rect_kayle.left += 116;
        if (hunt->rect_kayle.left >= 348)
            hunt->rect_kayle.left = 0;
        sfSprite_setTextureRect(hunt->kayle_sprite, hunt->rect_kayle);
        sfSprite_setTextureRect(hunt->cartman_sprite, hunt->rect_cartman);
        sfClock_restart(hunt->clock_kayle);
    }
    hunt->position_kayle.x += hunt->speed_x;
    if (i == 0)
        hunt->position_kayle.y += hunt->speed_y;
    if (hunt->position_kayle.y >= 900 || hunt->position_kayle.y <= 495)
        hunt->speed_y *= -1;
    kayle_anime_and_move_h2(hunt, a);
}