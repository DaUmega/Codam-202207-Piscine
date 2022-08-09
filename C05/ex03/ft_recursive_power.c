/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recursive_power.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 17:09:17 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/19 14:08:30 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power != 0)
		return (nb * ft_recursive_power(nb, power - 1));
	return (1);
}

// int main()
// {
// 	int ans = ft_recursive_power(-5, 3);
// 	printf("%d", ans);
// }