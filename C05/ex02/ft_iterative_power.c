/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iterative_power.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 16:22:13 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/19 12:02:44 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	temp;

	i = 1;
	temp = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		nb *= temp;
		i++;
	}
	return (nb);
}

// int main()
// {
// 	int ans = ft_iterative_power(-5, 0);
// 	printf("%d", ans);
// }