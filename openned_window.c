/*
** EPITECH PROJECT, 2019
** openned_window.c
** File description:
** oppenned_window function
*/
#include "my.h"

void openned_window(my_t *hunt)
{
    events(hunt);
    if (hunt->status == 0)
        menu(hunt);
    if (hunt->status == 1)
        game_easy(hunt);
    if (hunt->status == 2)
        game_normal(hunt);
    if (hunt->status == 3)
        game_hard(hunt);
    if (hunt->status == 4)
        lose_screen(hunt);
    if (hunt->status == 5)
        rules_screen(hunt);
    sfRenderWindow_display(hunt->window);
    sfRenderWindow_clear(hunt->window, sfBlack);
}

void menu(my_t *hunt)
{
    sfMusic_stop(hunt->game);
    sfMusic_stop(hunt->emmerde);
    menu_events(hunt);
    sfRenderWindow_drawSprite(hunt->window, hunt->background_sprite, NULL);
    cursor(hunt);
}

void game_easy(my_t *hunt)
{
    sfMusic_stop(hunt->generic);
    sfMusic_stop(hunt->emmerde);
    kayle_anime_and_move_e(hunt);
    sfSprite_setPosition(hunt->kayle_sprite, hunt->position_kayle);
    sfRenderWindow_drawSprite(hunt->window, hunt->map_sprite, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->cartman_sprite, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->kayle_sprite, NULL);
    cursor(hunt);
    if (hunt->deaths == 3) {
        hunt->status = 4;
        sfMusic_play(hunt->emmerde);
        sfMusic_stop(hunt->game);
    }
}

void game_normal(my_t *hunt)
{
    sfMusic_stop(hunt->generic);
    sfMusic_stop(hunt->emmerde);
    kayle_anime_and_move_n(hunt);
    sfSprite_setPosition(hunt->kayle_sprite, hunt->position_kayle);
    sfRenderWindow_drawSprite(hunt->window, hunt->map_sprite, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->cartman_sprite, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->kayle_sprite, NULL);
    cursor(hunt);
    if (hunt->deaths == 3) {
        hunt->status = 4;
        sfMusic_play(hunt->emmerde);
        sfMusic_stop(hunt->game);
    }
}

void game_hard(my_t *hunt)
{
    sfMusic_stop(hunt->generic);
    sfMusic_stop(hunt->emmerde);
    kayle_anime_and_move_h(hunt);
    sfSprite_setPosition(hunt->kayle_sprite, hunt->position_kayle);
    sfRenderWindow_drawSprite(hunt->window, hunt->map_sprite, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->cartman_sprite, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->kayle_sprite, NULL);
    cursor(hunt);
    if (hunt->deaths == 3) {
        hunt->status = 4;
        sfMusic_play(hunt->emmerde);
        sfMusic_stop(hunt->game);
    }
}