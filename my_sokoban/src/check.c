/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "my_sokoban.h"

int check_game_win(char **tab, char **tab_base)
{
	int a = 0;
	int b = 0;

	while (tab[a]) {
		b = 0;
		while (tab[a][b]) {
			if (tab[a][b] == 'O')
				return (1);
			if ((tab[a][b] == 'P') && (tab_base[a][b] == 'O'))
				return (1);
			b++;
		}
		a++;
	}
	return (0);
}

char	**check_input(t_soko *soko, int alpha)
{
	if (alpha == KEY_UP)
		soko->tab = move_up(soko);
	if (alpha == KEY_DOWN)
		soko->tab = move_down(soko);
	if (alpha == KEY_LEFT)
		soko->tab = move_left(soko);
	if (alpha == KEY_RIGHT)
		soko->tab = move_right(soko);
	return (soko->tab);
}

int	check_mvt(t_soko *soko)
{
	int	alpha;

	keypad(stdscr, TRUE);
	alpha = getch();
	soko->x = pos_player(soko->tab, 'x');
	soko->y = pos_player(soko->tab, 'y');
	soko->tab = check_input(soko, alpha);
	if (alpha == 27) {
		endwin();
		exit(0);
	}
	if (alpha == ' ')
		game_loop(soko);
	refresh();
	my_aff_map(soko->tab);
	return (1);
}

int	check_size_tab_x(char **tab)
{
	int	a = 0;
	int	size = 0;

	while (tab[a]) {
		if (my_strlen(tab[a]) > size)
			size = my_strlen(tab[a]);
		a++;
	}
	return (size);
}

int	check_size_tab_y(char **tab)
{
	int	a = 0;

	while (tab[a])
		a++;
	return (a);
}
