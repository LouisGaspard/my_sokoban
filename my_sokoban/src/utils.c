/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "my_sokoban.h"

void	my_aff_map(char **tab)
{
	int	a = 0;
	int	b = 0;
	int	i = 0;
	int	j = 0;

	while (tab[a] != NULL) {
		j = 0;
		b = 0;
		while (tab[a][b]) {
			mvaddch(i, j, tab[a][b]);
			j++;
			b++;
		}
		a++;
		i++;
	}
}

int	nboxes(char **tab)
{
	int	a = 0;
	int	b = 0;
	int	nb_boxes = 0;

	while (tab[a]) {
		b = 0;
		while (tab[a][b]) {
			if (tab[a][b] == 'X')
				nb_boxes++;
			b++;
		}
		a++;
	}
	return (nb_boxes);
}

int	check_line(t_soko *soko, int a, int b, int blocked)
{
	if (soko->tab[a][b] == 'X' && soko->tab_base[a][b] != 'O') {
		if ((soko->tab[a][b - 1] == '#')
			&& (soko->tab[a - 1][b] == '#'))
			blocked++;
		if ((soko->tab[a - 1][b] == '#')
			&& (soko->tab[a][b + 1] == '#'))
			blocked++;
		if ((soko->tab[a + 1][b] == '#')
			&& (soko->tab[a][b - 1] == '#'))
			blocked++;
		if ((soko->tab[a][b + 1] == '#')
			&& (soko->tab[a + 1][b] == '#'))
			blocked++;
	}
	return (blocked);
}

int	bblocked(t_soko *soko)
{
	int	a = 0;
	int	b = 0;
	int	blocked = 0;

	while (soko->tab[a]) {
		b = 0;
		while (soko->tab[a][b]) {
			blocked = check_line(soko, a, b, blocked);
			b++;
		}
		a++;
	}
	return (blocked);
}

void	remove_player(t_soko *soko)
{
	int	a = 0;
	int	b = 0;

	while (soko->tab_base[a]) {
		b = 0;
		while (soko->tab_base[a][b]) {
			if (soko->tab_base[a][b] == 'P')
				soko->tab_base[a][b] = ' ';
			if (soko->tab_base[a][b] == 'X')
				soko->tab_base[a][b] = ' ';
			b++;
		}
		a++;
	}
}
