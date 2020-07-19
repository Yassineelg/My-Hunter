/*
** EPITECH PROJECT, 2019
** openned_window2.c
** File description:
** second part
*/

#include "my.h"

void setup2(my_t *hunt)
{
    sfText_setFont(hunt->txt_highest_score, hunt->font);
    sfText_setFont(hunt->txt_score, hunt->font);
    sfText_setCharacterSize(hunt->txt_highest_score, 100);
    sfText_setCharacterSize(hunt->txt_score, 100);
    sfText_setColor(hunt->txt_score, sfYellow);
    sfText_setColor(hunt->txt_highest_score, sfYellow);
    sfText_setPosition(hunt->txt_score, hunt->position_score);
    sfText_setPosition(hunt->txt_highest_score, hunt->position_highest_score);
}

void setup(my_t *hunt)
{
    setup2(hunt);
    sfSprite_setTexture(hunt->background_sprite, hunt->background, sfTrue);
    sfSprite_setTexture(hunt->rules_sprite, hunt->rules, sfTrue);
    sfSprite_setTexture(hunt->cartman_sprite, hunt->cartman, sfTrue);
    sfSprite_setPosition(hunt->cartman_sprite, hunt->position_cartman);
    sfSprite_setTexture(hunt->kayle_sprite, hunt->kayle, sfTrue);
    sfSprite_setTexture(hunt->map_sprite, hunt->map, sfTrue);
    sfSprite_setTexture(hunt->end_sprite, hunt->end, sfTrue);
    sfSprite_setTexture(hunt->mouse_sprite, hunt->mouse, sfTrue);
    sfSprite_setTexture(hunt->bad_kayle_sprite, hunt->bad_kayle,
    sfTrue);
    sfRenderWindow_setMouseCursorVisible(hunt->window, sfFalse);
    sfRenderWindow_setFramerateLimit(hunt->window, 144);
    sfMusic_setVolume(hunt->game, 25);
    sfMusic_play(hunt->generic);
    sfMusic_setLoop(hunt->generic, sfTrue);
}

void bad_kayle_anime(my_t *hunt)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(hunt->clock_bad_kayle)) >
    99) {
        hunt->rect_bad_kayle.left += 181;
        if (hunt->rect_bad_kayle.left >= 724)
            hunt->rect_bad_kayle.left = 0;
        sfSprite_setTextureRect(hunt->bad_kayle_sprite, hunt->rect_bad_kayle);
        sfClock_restart(hunt->clock_bad_kayle);
    }
}

void lose_screen(my_t *hunt)
{
    if (hunt->highest_score < hunt->score)
        hunt->highest_score = hunt->score;
    hunt->fp = fopen("highest_score", "w");
    fwrite(my_rev_putnbr(hunt->highest_score), 1,
        my_strlen(my_rev_putnbr(hunt->highest_score)), hunt->fp);
    fclose(hunt->fp);
    hunt->fp = fopen("highest_score", "r");
    fread(hunt->highest_score_str, 1,
        my_strlen(my_rev_putnbr(hunt->highest_score)), hunt->fp);
    fclose(hunt->fp);
    bad_kayle_anime(hunt);
    sfText_setString(hunt->txt_highest_score, hunt->highest_score_str);
    sfText_setString(hunt->txt_score, my_rev_putnbr(hunt->score));
    sfRenderWindow_drawText(hunt->window, hunt->txt_score, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->end_sprite, NULL);
    sfSprite_setPosition(hunt->bad_kayle_sprite, hunt->position_bad_kayle);
    sfRenderWindow_drawSprite(hunt->window, hunt->bad_kayle_sprite, NULL);
    sfRenderWindow_drawText(hunt->window, hunt->txt_score, NULL);
    sfRenderWindow_drawText(hunt->window, hunt->txt_highest_score, NULL);
    cursor(hunt);
}

void rules_screen(my_t *hunt)
{
    if (hunt->events.type == sfEvtMouseButtonPressed &&
    hunt->events.mouseButton.button == sfMouseLeft &&
    hunt->mouse_position.x >= 1130 && hunt->mouse_position.x <= 1300 &&
    hunt->mouse_position.y >= 470 && hunt->mouse_position.y <= 520 &&
    hunt->mode == 5) {
        hunt->mode = 0;
        hunt->status = 0;
    }
    sfRenderWindow_drawSprite(hunt->window, hunt->rules_sprite, NULL);
    cursor(hunt);
}