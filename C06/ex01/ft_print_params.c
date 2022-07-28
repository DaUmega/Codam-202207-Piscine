/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_params.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 13:15:50 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/18 13:16:45 by pdong         ########   odam.nl         */
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

	i = 1;
	while (i < n)
	{
		ft_putstr(a[i]);
		write(1, "\n", 1);
		i++;
	}
	return (n);
}
