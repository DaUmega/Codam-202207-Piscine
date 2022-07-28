/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_comb.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 18:18:33 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/07 15:59:00 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

int	g_1 = 48;
int	g_2 = 48;
int	g_3 = 48;

void	ft_print_comb(void)
{
	while (g_1 <= 57)
	{
		g_2 = 48;
		while (g_2 <= 57)
		{
			g_3 = 48;
			while (g_3 <= 57)
			{
				if (g_1 < g_2 && g_2 < g_3)
				{
					write(1, &g_1, 1);
					write(1, &g_2, 1);
					write(1, &g_3, 1);
					if (!(g_1 == 55 && g_2 == 56 && g_3 == 57))
					{
						write(1, ", ", 2);
					}
				}
				g_3++;
			}
			g_2++;
		}
		g_1++;
	}
}
