/*
** EPITECH PROJECT, 2023
** win_fail
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

int cond1(char **map, int i, int j, int cnt)
{
    if (map[i][j] == 'O')
        cnt++;
}

int cnt_o2(char **map)
{
    int i = 0;
    int cnt = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            cond1(map, i, j, cnt);
        }
    }
    return cnt;
}
