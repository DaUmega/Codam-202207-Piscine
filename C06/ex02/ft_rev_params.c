/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rev_params.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 13:18:09 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/18 13:18:35 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int n, char **a)
{
	int	i;

	i = n - 1;
	while (i > 0)
	{
		ft_putstr(a[i]);
		write(1, "\n", 1);
		i--;
	}
	return (n);
}
