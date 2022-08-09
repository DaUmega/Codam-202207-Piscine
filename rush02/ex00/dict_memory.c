/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dict_memory.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/23 19:49:38 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/23 20:05:48 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	fill_zeroes(char **a, int len)
{
	int	pos;

	pos = 0;
	while (pos < len)
	{
		a[pos] = 0;
		++pos;
	}
}

void	free_dict(char ***dict, int n_filled_arrs)
{
	const int	sizes[3] = {20, 9, 12};
	int			pos;
	int			i;

	pos = 0;
	while (pos < n_filled_arrs)
	{
		i = 0;
		while (i < sizes[pos])
		{
			free(dict[pos][i]);
			++i;
		}
		free(dict[pos]);
		++pos;
	}
	free(dict);
}

char	***allocate_dict(void)
{
	const int	sizes[3] = {20, 9, 12};
	char		***dict;
	int			pos;

	dict = malloc(sizeof(char **) * 3);
	if (dict == 0)
		return (0);
	pos = 0;
	while (pos < 3)
	{
		dict[pos] = malloc(sizeof(char *) * sizes[pos]);
		if (dict[pos] == 0)
		{	
			free_dict(dict, pos);
			return (0);
		}
		fill_zeroes(dict[pos], sizes[pos]);
		++pos;
	}
	return (dict);
}
