/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iterative_factorial.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 16:05:08 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/20 20:01:46 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	ans;
	int	neg;

	i = 1;
	ans = 1;
	neg = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		ans = ans * i;
		i++;
	}
	return (ans * neg);
}

// int main()
// {
// 	int ans;

// 	ans = ft_iterative_factorial(0);
// 	printf("%d\n", ans);
// }