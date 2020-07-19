/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** partitions my.h
*/

#include "my.h"

void cursor(my_t *hunt)
{
    hunt->mouse_positiion = sfMouse_getPositionRenderWindow(hunt->window);
    hunt->mouse_position.x = hunt->mouse_positiion.x  - 31;
    hunt->mouse_position.y = hunt->mouse_positiion.y - 31;
    sfSprite_setPosition(hunt->mouse_sprite, hunt->mouse_position);
    sfRenderWindow_drawSprite(hunt->window, hunt->mouse_sprite, NULL);
}

void menu_events2(my_t *hunt)
{
    if (hunt->events.type == sfEvtMouseButtonPressed &&
    hunt->events.mouseButton.button == sfMouseLeft &&
    hunt->mouse_position.x >= 1130 && hunt->mouse_position.x <= 1310 &&
    hunt->mouse_position.y >= 690 && hunt->mouse_position.y <= 760) {
        sfMusic_play(hunt->game);
        hunt->mode = 3;
        hunt->status = 3;
    }
    if (hunt->events.type == sfEvtMouseButtonPressed &&
    hunt->events.mouseButton.button == sfMouseLeft &&
    hunt->mouse_position.x >= 850 && hunt->mouse_position.x <= 1025 &&
    hunt->mouse_position.y >= 815 && hunt->mouse_position.y <= 885) {
        hunt->mode = 5;
        hunt->status = 5;
    }
}

void menu_events(my_t *hunt)
{
    if (hunt->events.type == sfEvtMouseButtonPressed &&
    hunt->events.mouseButton.button == sfMouseLeft &&
    hunt->mouse_position.x >= 590 && hunt->mouse_position.x <= 780 &&
    hunt->mouse_position.y >= 690 && hunt->mouse_position.y <= 760) {
        sfMusic_play(hunt->game);
        hunt->mode = 1;
        hunt->status = 1;
    }
    if (hunt->events.type == sfEvtMouseButtonPressed &&
    hunt->events.mouseButton.button == sfMouseLeft &&
    hunt->mouse_position.x >= 800 && hunt->mouse_position.x <= 1100 &&
    hunt->mouse_position.y >= 690 && hunt->mouse_position.y <= 760) {
        sfMusic_play(hunt->game);
        hunt->mode = 2;
        hunt->status = 2;
    }
    menu_events2(hunt);
}

void hitting_kyle_event2(my_t *hunt, int a)
{
    sfMusic_stop(hunt->hit);
    sfMusic_play(hunt->hit);
    hunt->position_kayle.x = -200;
    if (hunt->speed_x < 0)
        hunt->speed_x *= -1;
    hunt->speed_x += 0.5;
    hunt->speed_y += 0.5;
    if (a == 0 && hunt->mode == 3) {
        hunt->position_kayle.x = 1920;
        hunt->speed_x *= -1;
    }
    hunt->position_kayle.y = (rand() % 430) + 495;
    hunt->score += 1;
}

void hitting_kyle_event(my_t *hunt)
{
    int a = rand() % 2;

    if (hunt->events.type == sfEvtMouseButtonPressed &&
    hunt->events.mouseButton.button == sfMouseLeft &&
    hunt->mouse_position.x >= hunt->position_kayle.x - 15 &&
    hunt->mouse_position.x <= hunt->position_kayle.x + 116 &&
    hunt->mouse_position.y >= hunt->position_kayle.y - 15 &&
    hunt->mouse_position.y <= hunt->position_kayle.y + 150)
        hitting_kyle_event2(hunt, a);
}