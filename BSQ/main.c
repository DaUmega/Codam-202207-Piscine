/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 18:57:36 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/27 16:58:13 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mapdata.h"

void	solve_map(int fd)
{
	t_mapdata	info;
	t_solver	ans;

	info = read_map(fd);
	if (is_empty (info))
	{
		write(2, "map error\n", 10);
		return ;
	}
	ans = apply_algo(info);
	mapwriter(ans, info);
	print_map(info);
	free_map(info);
}

void	solve_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "map error\n", 10);
		return ;
	}
	solve_map(fd);
	close(fd);
}

int	main(int argc, char **argv)
{
	int	pos;

	if (argc == 1)
	{
		solve_map(0);
		return (0);
	}
	pos = 1;
	while (pos < argc)
	{
		solve_file(argv[pos]);
		pos++;
	}
	return (0);
}
