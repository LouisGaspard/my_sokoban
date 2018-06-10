/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "my_sokoban.h"

int	main(int ac, char **av)
{
	t_soko	soko;

	if (ac == 2) {
		if (my_strcmp(av[1], "-h") == 0) {
			my_usage(av[0]);
			return (0);
		}
		if ((my_sokoban(av[1], &soko)) == 84)
			return (84);
		else
			return (0);
	} else {
		my_usage("./my_sokoban");
		return (84);
	}
	return (0);
}
