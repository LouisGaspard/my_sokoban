/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** sokoban
*/

#ifndef __MY_SOKOBAN_H_
#define __MY_SOKOBAN_H_

#include <ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>

typedef struct
{
	char   *buffer;
	char	**tab;
	char	**tab_base;
	int	x;
	int	y;
	int	boxes;
	int	b_boxes;
} t_soko;

int	my_sokoban(char *path_file, t_soko *soko);
void	my_usage(char *exec_name);
int	game_loop(t_soko *soko);
void	free_tab(char **tab);
int	check_size_tab_x(char **tab);
int	check_size_tab_y(char **tab);
void	my_aff_map(char **tab);
char	**move_up(t_soko *soko);
char	**move_down(t_soko *soko);
char	**move_left(t_soko *soko);
char	**move_right(t_soko *soko);
int	pos_player(char **tab, char x_y);
int	check_game_win(char **tab, char **tab_base);
char	**check_input(t_soko *soko, int alpha);
int	check_mvt(t_soko *soko);
void	game_win(t_soko *soko);
void	game_lose(t_soko *soko);
void	remove_player(t_soko *soko);
int	nboxes(char **tab);
int	bblocked(t_soko *soko);

#endif
