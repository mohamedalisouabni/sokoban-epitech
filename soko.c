/*
** EPITECH PROJECT, 2023
** bs_soko
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

char **soko_load(char *buff, struct player *p)
{
    int k = 0;
    int j;
    int len = my_strlen(buff);
    char **map = malloc(sizeof(char *) * len + 1);
    int rows = cnt_rows(buff);
    int cols = cnt_line(buff);

    for (int i = 0; i < len; i++) {
        map[i] = malloc(sizeof(char) * rows + 1);
    }
    for (int i = 0; i < cols; i++) {
        for (j = 0; j < rows + 1; j++) {
            map[i][j] = buff[k];
            k++;
        }
        map[i][j + 1] = '\0';
    }
    valid_map(buff);
    return map;
}

char *fs_open_print_file(char const *filepath, struct player *p)
{
    struct stat sb;
    int i = stat(filepath, &sb);
    int op = open(filepath, O_RDONLY);
    char *buff = malloc(sb.st_size + 1);
    int rd = read(op, buff, sb.st_size + 1);
    int a = cnt_o(buff);
    int b = cnt_x(buff);

    if (op == -1 || op == NULL)
        return 84;
    if (a != b) {
        my_putstr("invalid map !!\n");
        exit(84);
    }
    buff[sb.st_size] = '\0';
    close(op);
    return buff;
}

void key_mv(char *buff, char **str, int c, struct player *p)
{
    char **buff2 = soko_load2(buff, p);

    move_p(str, p);
    switch (c) {
    case KEY_UP:
        player_up(buff2, str, p);
        break;
    case KEY_RIGHT:
        player_r(buff2, str, p);
        break;
    case KEY_LEFT:
        player_l(buff2, str, p);
        break;
    case KEY_DOWN:
        player_d(buff2, str, p);
        break;
    }
}

int main(int ac, char **av)
{
    struct player *p = malloc(sizeof(pos_p_t) + 1);
    char *map = fs_open_print_file(av[1], p);
    char **map2 = soko_load(map, p);

    if (ac == 1 || ac >= 3)
        return 84;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help();
    if (ac == 2)
        my_popup(map, map2, p);
    free(p);
    return 0;
}
