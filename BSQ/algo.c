/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/27 12:08:49 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/27 18:17:19 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mapdata.h"

void	free_mem(int **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

int	**arr_maker(int **arr, t_mapdata info)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < info.rows)
	{
		while (x < ft_strlen(info.map[0]))
		{
			if (info.map[y][x] == info.empty)
				arr[y][x] = 0;
			if (info.map[y][x] == info.obsta || info.map[y][x] == '\n')
				arr[y][x] = 1;
			x++;
		}
		x = 0;
		y++;
	}
	while (x < ft_strlen(info.map[0]))
	{
		arr[y][x] = 1;
		x++;
	}
	return (arr);
}

t_solver	apply_algo(t_mapdata info)
{
	int			**arr;
	int			i;
	t_solver	ans;

	arr = malloc(sizeof(int *) * (info.rows + 1));
	if (!arr)
		return (empty_solution());
	i = 0;
	while (i <= info.rows)
	{
		arr[i] = malloc(sizeof(int) * ft_strlen(info.map[0]));
		if (!arr[i])
		{
			free_mem(arr, i);
			return (empty_solution());
		}
		i++;
	}
	arr = arr_maker(arr, info);
	ans = solver(arr, info);
	free_mem(arr, i - 1);
	return (ans);
}
