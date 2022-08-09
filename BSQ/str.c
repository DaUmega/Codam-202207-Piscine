/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 19:11:02 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/27 15:21:22 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mapdata.h"

int	ft_strlen(const char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

void	print_map(t_mapdata info)
{
	int	pos;

	pos = 0;
	while (pos < info.rows)
	{
		write(1, info.map[pos], ft_strlen(info.map[pos]));
		++pos;
	}
}
