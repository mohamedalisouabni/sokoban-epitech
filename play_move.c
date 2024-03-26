/*
** EPITECH PROJECT, 2023
** play_move
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

char **player_up(char **b, char **mp, struct player *p)
{
    int x = p->pos_x;
    int y = p->pos_y;

    if (mp[x][y] == 'P' && (mp[x - 1][y] == ' ' || mp[x - 1][y] == 'O')) {
        mp[x - 1][y] = 'P';
        mp[x][y] = ' ';
    }
    if (mp[x][y] == 'P' && mp[x - 1][y] == 'X' && mp[x - 2][y] == ' ') {
        mp[x - 1][y] = 'P';
        mp[x - 2][y] = 'X';
        mp[x][y] = ' ';
    }
    if (mp[x][y] == 'P' && mp[x - 1][y] == 'X' &&
    (mp[x - 2][y] == 'O' || mp[x - 2][y] == ' ')) {
        mp[x - 1][y] = 'P';
        mp[x - 2][y] = 'X';
        mp[x][y] = ' ';
    } else if (b[x][y] == 'O' && mp[x - 1][y] != '#' && mp[x - 1][y] != 'X')
        mp[x][y] = 'O';
    return mp;
}

char **player_r(char **b, char **mp, struct player *p)
{
    int x = p->pos_x;
    int y = p->pos_y;

    if (mp[x][y] == 'P' && (mp[x][y + 1] == ' ' || mp[x][y + 1] == 'O')) {
        mp[x][y + 1] = 'P';
        mp[x][y] = ' ';
    }
    if (mp[x][y] == 'P' && mp[x][y + 1] == 'X' && mp[x][y + 2] == ' ') {
        mp[x][y + 1] = 'P';
        mp[x][y + 2] = 'X';
        mp[x][y] = ' ';
    }
    if (mp[x][y] == 'P' && mp[x][y + 1] == 'X' &&
    (mp[x][y + 2] == 'O' || mp[x][y + 2] == ' ')) {
        mp[x][y + 1] = 'P';
        mp[x][y + 2] = 'X';
        mp[x][y] = ' ';
    } else if (b[x][y] == 'O' && mp[x][y + 1] != '#' && mp[x][y + 1] != 'X')
        mp[x][y] = 'O';
    return mp;
}

char **player_l(char **b, char **mp, struct player *p)
{
    int x = p->pos_x;
    int y = p->pos_y;

    if (mp[x][y] == 'P' && (mp[x][y - 1] == ' ' || mp[x][y - 1] == 'O')) {
        mp[x][y - 1] = 'P';
        mp[x][y] = ' ';
    }
    if (mp[x][y] == 'P' && mp[x][y - 1] == 'X' && mp[x][y - 2] == ' ') {
        mp[x][y - 1] = 'P';
        mp[x][y - 2] = 'X';
        mp[x][y] = ' ';
    }
    if (mp[x][y] == 'P' && mp[x][y - 1] == 'X' &&
    (mp[x][y - 2] == 'O' || mp[x][y - 2] == ' ')) {
        mp[x][y - 1] = 'P';
        mp[x][y - 2] = 'X';
        mp[x][y] = ' ';
    } else if (b[x][y] == 'O' && mp[x][y - 1] != '#' && mp[x][y - 1] != 'X')
        mp[x][y] = 'O';
    return mp;
}

char **player_d(char **b, char **mp, struct player *p)
{
    int x = p->pos_x;
    int y = p->pos_y;

    if (mp[x][y] == 'P' && (mp[x + 1][y] == ' ' || mp[x + 1][y] == 'O')) {
        mp[x + 1][y] = 'P';
        mp[x][y] = ' ';
    }
    if (mp[x][y] == 'P' && mp[x + 1][y] == 'X' && mp[x + 2][y] == ' ') {
        mp[x + 1][y] = 'P';
        mp[x + 2][y] = 'X';
        mp[x][y] = ' ';
    }
    if (mp[x][y] == 'P' && mp[x + 1][y] == 'X' &&
    (mp[x + 2][y] == 'O' || mp[x + 2][y] == ' ')) {
        mp[x + 1][y] = 'P';
        mp[x + 2][y] = 'X';
        mp[x][y] = ' ';
    } else if (b[x][y] == 'O' && mp[x + 1][y] != '#' && mp[x + 1][y] != 'X')
        mp[x][y] = 'O';
    return mp;
}
