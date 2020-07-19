/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** strlen function
*/

int my_strlen(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}