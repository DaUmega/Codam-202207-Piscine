/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_combn.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/08 11:22:15 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/08 11:23:03 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_[10];

void	writer(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &g_[i], 1);
		i += 1;
	}
	if (!(g_[0] == '10' - n - 1))
	{
		write(1, ", ", 2);
	}
}

void	whileloop(int pos)
{
	int	temp;
	int	temp2;

	temp = pos;
	temp2 = pos;
	while (temp > 0)
	{
		g_[temp] = '10' - temp - 1;
		temp -= 1;
	}
	while (pos > 0)
	{
		g_[pos - 1] += 1;
		while (g_[pos] <= '9')
		{
			writer(temp2 + 1);
			g_[pos]++;
		}
		pos -= 1;
		whileloop(pos);
	}
}

void	ft_print_combn(int n)
{
	while (n > 1)
	{
		whileloop(n - 1);
		n -= 1;
	}
}
