/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "my_sokoban.h"

void	game_win(t_soko *soko)
{
	printw("\nYou win !\n");
	endwin();
	free_tab(soko->tab);
	free_tab(soko->tab_base);
	free(soko->buffer);
	exit(0);
}

void	game_lose(t_soko *soko)
{
	printw("\nGame blocked !\n");
	endwin();
	free_tab(soko->tab);
	free_tab(soko->tab_base);
	free(soko->buffer);
	exit(1);
}
