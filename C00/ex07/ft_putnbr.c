/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 12:39:25 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/08 11:19:27 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(int c)
{
	write(1, &c, 1);
}

int	power(int a)
{
	if (a == 0)
	{
		return (1);
	}
	return (10 * power(a - 1));
}

int	looper(int b, int c)
{
	while (b > 1)
	{
		printer(c / power(b - 1) + '0');
		while (c >= power(b - 1))
		{
			c -= power(b - 1);
		}
		b--;
	}
	printer(c + '0');
	return (0);
}

void	ft_putnbr(int nb)
{
	int	digits;
	int	test;

	digits = 0;
	test = nb;
	while (test != 0)
	{
		test /= 10;
		digits++;
	}
	if (nb < 0)
	{
		printer('-');
		nb *= -1;
	}
	looper(digits, nb);
}
