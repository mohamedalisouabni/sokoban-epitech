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
#include "./include/my.h"

int cnt_rows(char *av)
{
    int i;

    for (i = 0; av[i] != '\n'; i++);
    return i;
}

int cnt_line(char *av)
{
    int cnt = 0;

    for (int j = 0; av[j] != '\0';j++) {
        if (av[j] == '\n')
            cnt++;
    }
    return cnt + 1;
}
