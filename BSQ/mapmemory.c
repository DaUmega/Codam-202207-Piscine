/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapmemory.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/27 11:58:48 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/27 16:59:51 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mapdata.h"

void	free_map(t_mapdata info)
{
	int	pos;

	pos = 0;
	while (pos < info.rows)
	{
		free(info.map[pos]);
		++pos;
	}
	free(info.map);
}
