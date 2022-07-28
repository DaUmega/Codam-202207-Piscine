/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush03.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/08 21:25:16 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/12 12:28:42 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x);

void	loopmiddle(int x)
{
	int	counter;

	counter = 1;
	while (counter <= x)
	{
		if (counter == 1)
		{
			ft_putchar('B');
		}
		if (counter == x)
		{
			write (1, "B\n", 2);
		}
		if (counter > 1 && counter < x)
		{
			ft_putchar(' ');
		}
		counter++;
	}
}

void	loopfirstlast(int x)
{
	int	counter;

	counter = 1;
	while (counter <= x)
	{
		if (counter == 1)
		{
			ft_putchar('A');
		}
		if (counter == x)
		{
			write (1, "C\n", 2);
		}
		if (counter > 1 && counter < x)
		{
			ft_putchar('B');
		}
		counter++;
	}
}

void	firstlastprinter(int x)
{
	if (x == 1)
	{
		write (1, "A\n", 2);
	}
	else
	{
		loopfirstlast(x);
	}
}

void	middleprinter(int x)
{
	if (x == 1)
	{
		write (1, "B\n", 2);
	}
	else
	{
		loopmiddle(x);
	}
}

void	rush(int x, int y)
{
	int	counter;

	counter = 1;
	if (y == 1)
	{
		firstlastprinter(x);
	}
	else
	{
		counter = 1;
		while (counter <= y)
		{
			if (counter == 1 || counter == y)
			{
				firstlastprinter(x);
			}
			else
			{
				middleprinter(x);
			}
			counter++;
		}
	}
}
