/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "my_sokoban.h"

void	free_tab(char **tab)
{
	int	a = 0;

	while (tab[a]) {
		free(tab[a]);
		a++;
	}
	free(tab);
}
