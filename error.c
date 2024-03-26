/*
** EPITECH PROJECT, 2023
** sokoerr
** File description:
** lib
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "./include/my.h"
#include <ncurses.h>

int cnt_o(char *map)
{
    int i = 0;
    int cnt = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'O')
            cnt++;
    }
    return cnt;
}

int cnt_x(char *map)
{
    int i = 0;
    int cnt = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'X')
            cnt++;
    }
    return cnt;
}

int valid_map(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'X' || str[i] == 'P' || str[i] == 'O' || str[i] == ' ' ||
        str[i] == '#' || str[i] == '\n') {
            continue;
        } else {
            my_putstr("invalid map !!\n");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
