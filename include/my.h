/*
** EPITECH PROJECT, 2023
** my
** File description:
** h
*/
#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

typedef struct player{
    int pos_x;
    int pos_y;
    int ox;
    int oy;
}pos_p_t;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void help(void);
char **my_popup(char *buff, char **str, struct player *p);
int valid_map(char *str);
int move_p(char **map, struct player *p);
char **player_up(char **b, char **mp, struct player *p);
char **player_d(char **b, char **mp, struct player *p);
char **player_r(char **b, char **mp, struct player *p);
char **player_l(char **b, char **mp, struct player *p);
int cnt_rows(char *av);
int cnt_line(char *av);
char **soko_load(char *buff, struct player *p);
char *fs_open_print_file(char const *filepath, struct player *p);
void key_mv(char *buff, char **str, int c, struct player *p);
char **soko_load2(char *buff, struct player *p);
int cnt_x(char *map);
int cnt_o(char *map);

#endif /* MY_H_ */
