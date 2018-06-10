/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "my_sokoban.h"

void	my_usage(char *exec_name)
{
	my_printf("USAGE\n\t%s map\n\n", exec_name);
	my_printf("DESCRIPTION\n\tmap\tfile representing the warehouse ");
	my_printf("map, containing '#' for walls,\n");
	my_printf("\t\t'P' for the player, 'X' for boxes and 'O' for ");
	my_printf("storage locations.\n");
}
