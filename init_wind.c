/*
** EPITECH PROJECT, 2023
** cnt_map
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

void disp(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        printw(str[i]);
    }
    refresh();
}

char **soko_load2(char *buff, struct player *p)
{
    int k = 0;
    int j;
    int len = my_strlen(buff);
    char **map2 = malloc(sizeof(char *) * len + 1);
    int rows = cnt_rows(buff);
    int cols = cnt_line(buff);

    for (int i = 0; i < len; i++) {
        map2[i] = malloc(sizeof(char) * rows + 1);
    }
    for (int i = 0; i < cols; i++) {
        for (j = 0; j < rows + 1; j++) {
            map2[i][j] = buff[k];
            k++;
        }
        map2[i][j + 1] = '\0';
    }
    valid_map(buff);
    return map2;
}

char **my_popup(char *buff, char **str, struct player *p)
{
    int c;

    initscr();
    noecho();
    curs_set(FALSE);
    disp(str);
    keypad(stdscr, TRUE);
    while (c != 32) {
        c = getch();
        clear();
        key_mv(buff, str, c, p);
        refresh();
        disp(str);
    }
    endwin();
}
