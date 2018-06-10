/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "my_sokoban.h"

void	launch_game_loop(t_soko *soko)
{
	while (soko->boxes - soko->b_boxes != 0) {
		while (COLS < check_size_tab_x(soko->tab)
				|| LINES < check_size_tab_y(soko->tab)) {
			clear();
			mvprintw(LINES / 2, (COLS - my_strlen("BAD SIZE"))
					/ 2, "BAD SIZE");
			refresh();
		}
		clear();
		my_aff_map(soko->tab);
		check_mvt(soko);
		if ((check_game_win(soko->tab, soko->tab_base)) == 0)
			game_win(soko);
		soko->boxes = nboxes(soko->tab);
		soko->b_boxes = bblocked(soko);
	}
}

int	game_loop(t_soko *soko)
{
	if ((soko->tab = my_str_to_word_array(soko->buffer)) == NULL)
		return (84);
	if ((soko->tab_base = my_str_to_word_array(soko->buffer)) == NULL)
		return (84);
	initscr();
	curs_set(0);
	noecho();
	remove_player(soko);
	soko->boxes = nboxes(soko->tab);
	soko->b_boxes = bblocked(soko);
	launch_game_loop(soko);
	game_lose(soko);
	return (0);
}

void	check_map(char *buffer)
{
	int	a = 0;
	int	good = 0;

	while (buffer[a]) {
		if ((buffer[a] != ' ') && (buffer[a] != 'X')
			&& (buffer[a] != 'O') && (buffer[a] != 'P')
			&& (buffer[a] != '#') && (buffer[a] != '\n'))
			exit(84);
		a++;
	}
	a = 0;
	while (buffer[a]) {
		if (buffer[a] == 'X')
			good++;
		a++;
	}
	if (good == 0)
		exit(84);
}

int	my_sokoban(char *path_file, t_soko *soko)
{
	FILE	*fd;
	char	*line = NULL;
	size_t	len = 0;
	ssize_t	read;

	soko->buffer = "";
	if ((fd = fopen(path_file, "r")) == NULL)
		return (84);
	while ((read = getline(&line, &len, fd)) != -1)
		soko->buffer = my_strcat(soko->buffer, line);
	check_map(soko->buffer);
	if ((fclose(fd)) == -1)
		return (84);
	if ((game_loop(soko)) == 84)
		return (84);
	return (0);
}
