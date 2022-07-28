/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rev_int_tab.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/09 18:26:27 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/09 20:27:06 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	c;
	int	half;

	i = 0;
	half = size / 2;
	while (size > half)
	{
		c = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = c;
		size--;
		i++;
	}
}
