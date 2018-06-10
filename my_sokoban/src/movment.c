/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "my_sokoban.h"

int	pos_player(char **tab, char x_y)
{
	int	a = 0;
	int	b = 0;

	while (tab[a]) {
		b = 0;
		while (tab[a][b]) {
			if ((tab[a][b] == 'P') && (x_y == 'x'))
				return (b);
			if ((tab[a][b] == 'P') && (x_y == 'y'))
				return (a);
			b++;
		}
		a++;
	}
	return (84);
}

char	**move_up(t_soko *soko)
{
	int	x = soko->x;
	int	y = soko->y;

	if (soko->tab[y - 1][x] != '#') {
		if ((soko->tab[y - 1][x] == 'X')
			&& (soko->tab[y - 2][x] != '#')
			&& (soko->tab[y - 2][x] != 'X')) {
			soko->tab[y - 1][x] = 'P';
			soko->tab[y - 2][x] = 'X';
			soko->tab[y][x] = soko->tab_base[y][x];
		} else if (soko->tab[y - 1][x] != 'X') {
			soko->tab[y - 1][x] = 'P';
			soko->tab[y][x] = soko->tab_base[y][x];
		}
	}
	return (soko->tab);
}

char	**move_down(t_soko *soko)
{
	int	x = soko->x;
	int	y = soko->y;

	if (soko->tab[y + 1][x] != '#') {
		if ((soko->tab[y + 1][x] == 'X')
			&& (soko->tab[y + 2][x] != '#')
			&& (soko->tab[y + 2][x] != 'X')) {
			soko->tab[y + 1][x] = 'P';
			soko->tab[y + 2][x] = 'X';
			soko->tab[y][x] = soko->tab_base[y][x];
		} else if (soko->tab[y + 1][x] != 'X') {
			soko->tab[y + 1][x] = 'P';
			soko->tab[y][x] = soko->tab_base[y][x];
		}
	}
	return (soko->tab);
}

char	**move_left(t_soko *soko)
{
	int	x = soko->x;
	int	y = soko->y;

	if (soko->tab[y][x - 1] != '#') {
		if ((soko->tab[y][x - 1] == 'X')
			&& (soko->tab[y][x - 2] != '#')
			&& (soko->tab[y][x - 2] != 'X')) {
			soko->tab[y][x - 1] = 'P';
			soko->tab[y][x - 2] = 'X';
			soko->tab[y][x] = soko->tab_base[y][x];
		} else if (soko->tab[y][x - 1] != 'X') {
			soko->tab[y][x - 1] = 'P';
			soko->tab[y][x] = soko->tab_base[y][x];
		}
	}
	return (soko->tab);
}

char	**move_right(t_soko *soko)
{
	int	x = soko->x;
	int	y = soko->y;

	if (soko->tab[y][x + 1] != '#') {
		if ((soko->tab[y][x + 1] == 'X')
			&& (soko->tab[y][x + 2] != '#'
			&& (soko->tab[y][x + 2] != 'X'))) {
			soko->tab[y][x + 1] = 'P';
			soko->tab[y][x + 2] = 'X';
			soko->tab[y][x] = soko->tab_base[y][x];
		} else if (soko->tab[y][x + 1] != 'X') {
			soko->tab[y][x + 1] = 'P';
			soko->tab[y][x] = soko->tab_base[y][x];
		}
	}
	return (soko->tab);
}
