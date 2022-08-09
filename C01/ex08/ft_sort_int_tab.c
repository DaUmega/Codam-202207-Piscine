/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_int_tab.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/09 19:53:03 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/09 20:26:49 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	c;
	int	a;

	i = 0;
	while (i < size)
	{
		a = 0;
		while (a < size)
		{
			if (tab[i] < tab [a])
			{
				c = tab[i];
				tab[i] = tab[a];
				tab[a] = c;
				a++;
			}
			else
			{
				a++;
			}
		}
		i++;
	}
}
