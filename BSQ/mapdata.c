/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapdata.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 18:23:59 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/27 16:59:45 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mapdata.h"

int	is_empty(t_mapdata info)
{
	return (info.empty == 0);
}

t_mapdata	empty_mapdata(void)
{
	t_mapdata	info;

	info.empty = 0;
	info.obsta = 0;
	info.full = 0;
	info.rows = 0;
	info.map = NULL;
	return (info);
}

t_solver	empty_solution(void)
{
	t_solver	ans;

	ans.x = 0;
	ans.y = 0;
	ans.sqsize = 0;
	return (ans);
}

t_mapdata	mapdata(char *str)
{
	t_mapdata	info;
	int			i;
	int			j;

	info = empty_mapdata();
	i = ft_strlen(str) - 1;
	if (i < 4 || str[i] != '\n' || str[0] == '0')
		return (empty_mapdata());
	j = 0;
	while (j < i - 3)
	{
		if (str[j] < '0' || str[j] > '9')
			return (empty_mapdata());
		info.rows = info.rows * 10 + str[j] - '0';
		j++;
	}
	info.full = str[--i];
	info.obsta = str[--i];
	info.empty = str[--i];
	if (info.full == info.obsta || info.empty == info.obsta
		|| info.full == info.empty)
		return (empty_mapdata());
	return (info);
}

/*
#include <stdio.h>
int main()
{
	t_mapdata info;

	info = mapdata("19012\n");
	printf("%d:%c%c%c\n", info.rows, info.empty, info.obsta, info.full);
	info = mapdata("0.ox\n");
	printf("%d:%c%c%c\n", info.rows, info.empty, info.obsta, info.full);
	info = mapdata("");
	printf("%d:%c%c%c\n", info.rows, info.empty, info.obsta, info.full);
	return (0);
}
*/
