/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_program_name.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 13:12:46 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/18 17:38:26 by pdong         ########   odam.nl         */
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
	ft_putstr(a[0]);
	write(1, "\n", 1);
	return (n);
}
