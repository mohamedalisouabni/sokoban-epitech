/*
** EPITECH PROJECT, 2023
** help
** File description:
** lib
*/
#include "./include/my.h"

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n\tmap file representing ");
    my_putstr("the warehouse map, containing '#' for walls,\n\t    ");
    my_putstr("'P' for the player, 'X' ");
    my_putstr("for boxes and 'O' for storage locations.\n");
}
