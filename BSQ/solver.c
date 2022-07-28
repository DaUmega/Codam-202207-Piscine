/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 19:04:45 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/27 17:03:06 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mapdata.h"

t_mapdata	mapdata(char *str);
void		print_map(t_mapdata info);
int			ft_strlen(const char *a);
t_solver	apply_algo(t_mapdata info);

int	ft_check(int x, int y, int **arr)
{
	int	sqsize;
	int	tempx;
	int	tempy;

	sqsize = 0;
	tempx = x;
	tempy = y;
	while (arr[y][x] == 0)
	{
		y = tempy;
		while (y - tempy <= sqsize)
		{
			x = tempx;
			while (x - tempx <= sqsize)
			{
				if (arr[y][x] != 0)
					return (sqsize);
				x++;
			}
			y++;
		}
		sqsize++;
	}
	return (sqsize);
}

t_solver	ans_update(t_solver ans, int sqsize, int x, int y)
{
	ans.sqsize = sqsize;
	ans.x = x;
	ans.y = y;
	return (ans);
}

t_solver	solver(int **arr, t_mapdata info)
{
	int			sqsize;
	int			x;
	int			y;
	t_solver	ans;

	sqsize = 0;
	y = 0;
	ans.sqsize = 0;
	ans.x = 0;
	ans.y = 0;
	while (y <= info.rows)
	{
		x = 0;
		while (x < ft_strlen(info.map[0]))
		{
			sqsize = ft_check(x, y, arr);
			if (sqsize > ans.sqsize)
				ans = ans_update(ans, sqsize, x, y);
			x++;
		}
		y++;
	}
	return (ans);
}

void	mapwriter(t_solver ans, t_mapdata info)
{
	int	tempx;
	int	tempy;

	tempx = ans.x;
	tempy = ans.y;
	while (tempy - ans.y < ans.sqsize)
	{
		tempx = ans.x;
		while (tempx - ans.x < ans.sqsize)
		{
			info.map[tempy][tempx] = info.full;
			tempx++;
		}
		tempy++;
	}
}

/*
int main()
{
	t_solver	ans;
	t_mapdata	info;
	char		**map;

	map = malloc(sizeof(char *) * 9);
	map[0] = strdup("...........................\n");
	map[1] = strdup("....o......................\n");
	map[2] = strdup("............o..............\n");
	map[3] = strdup("...........................\n");
	map[4] = strdup("....o......................\n");
	map[5] = strdup("...............o...........\n");
	map[6] = strdup("...........................\n");
	map[7] = strdup("......o..............o.....\n");
	map[8] = strdup("..o.......o................\n");
	info = mapdata("9.ox\n");
	info.map = map;
	print_map(info);
	ans = apply_algo(info);
	mapwriter(map, ans, info);
	int i = 0;
	printf("\n");
	while (i < info.rows)
	{
		printf("%s", map[i]);
		i++;
	}
}
*/