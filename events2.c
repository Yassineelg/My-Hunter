/*
** EPITECH PROJECT, 2019
** events2.c
** File description:
** event part
*/

#include "my.h"

void events(my_t *hunt)
{
    while (sfRenderWindow_pollEvent(hunt->window, &hunt->events)) {
        if (hunt->events.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(hunt->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfMusic_play(hunt->generic);
            reset_variables(hunt);
            hunt->status = 0;
            hunt->mode = 0;
        }
        if (sfKeyboard_isKeyPressed(sfKeyR)) {
            sfMusic_play(hunt->game);
            reset_variables(hunt);
            hunt->status = hunt->mode;
        }
        hitting_kyle_event(hunt);
    }
}