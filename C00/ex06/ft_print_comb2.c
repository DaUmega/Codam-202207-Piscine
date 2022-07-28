/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_comb2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 18:18:33 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/08 11:40:49 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(int c)
{
	write(1, &c, 1);
}

void	looper(int c, int d)
{
	if (c < d)
	{
		printer(c / 10 + '0');
		printer(c % 10 + '0');
		write(1, " ", 1);
		printer(d / 10 + '0');
		printer(d % 10 + '0');
		if (!(c == 98 && d == 99))
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 99)
	{
		b = 0;
		while (b <= 99)
		{
			looper (a, b);
			b++;
		}
		a++;
	}
}
