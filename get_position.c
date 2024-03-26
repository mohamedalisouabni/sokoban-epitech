/*
** EPITECH PROJECT, 2023
** position
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

int cond_get_pos(char **map, struct player *p, int i, int j)
{
    if (map[i][j] == 'P') {
        p->pos_x = i;
        p->pos_y = j;
    }
    return 0;
}

int move_p(char **map, struct player *p)
{
    int i = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            cond_get_pos(map, p, i, j);
        }
    }
    return 0;
}
