/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** my_hunter main's
*/

#include "my.h"

void destroy_function2(my_t *hunt)
{
    sfClock_destroy(hunt->clock_bad_kayle);
    sfClock_destroy(hunt->clock_kayle);
    sfFont_destroy(hunt->font);
    sfText_destroy(hunt->txt_highest_score);
    sfText_destroy(hunt->txt_score);
    sfMusic_destroy(hunt->hit);
    sfRenderWindow_destroy(hunt->window);
}

void destroy_function(my_t *hunt)
{
    sfMusic_destroy(hunt->generic);
    sfMusic_destroy(hunt->game);
    sfMusic_destroy(hunt->emmerde);
    sfSprite_destroy(hunt->background_sprite);
    sfTexture_destroy(hunt->background);
    sfSprite_destroy(hunt->rules_sprite);
    sfTexture_destroy(hunt->rules);
    sfSprite_destroy(hunt->cartman_sprite);
    sfTexture_destroy(hunt->cartman);
    sfSprite_destroy(hunt->kayle_sprite);
    sfTexture_destroy(hunt->kayle);
    sfSprite_destroy(hunt->bad_kayle_sprite);
    sfTexture_destroy(hunt->bad_kayle);
    sfSprite_destroy(hunt->end_sprite);
    sfTexture_destroy(hunt->end);
    sfSprite_destroy(hunt->mouse_sprite);
    sfTexture_destroy(hunt->mouse);
    sfSprite_destroy(hunt->map_sprite);
    sfTexture_destroy(hunt->map);
    destroy_function2(hunt);
}

void high_score_setup(my_t *hunt)
{
    FILE *fp;

    hunt->highest_score_str = malloc(sizeof(char) * 4);
    fp = fopen("highest_score", "r");
    fread(hunt->highest_score_str, 1,
          3, fp);
    hunt->highest_score = my_getnbr(hunt->highest_score_str);
}

int main(int ac, char **av)
{
    my_t *hunt = malloc(sizeof(my_t));
    char buffer[971];
    int fd;

    high_score_setup(hunt);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        fd = open("rules", O_RDONLY);
        read(fd, buffer, 971);
        write(1, buffer, 971);
        close(fd);
    }
    if (ac == 1) {
        variable_affectation(hunt);
        setup(hunt);
        while (sfRenderWindow_isOpen(hunt->window))
            openned_window(hunt);
        destroy_function(hunt);
    }
    free(hunt);
    free(hunt->highest_score_str);
}