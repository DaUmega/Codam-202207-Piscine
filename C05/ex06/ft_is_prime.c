/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_prime.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 21:19:11 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/20 16:57:33 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_prime(int nb)
{
	long long	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i * i <= nb && i * i < (long long)2147483647)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// int main()
// {
// 	int test = ft_is_prime(2147483647);
// 	printf("%d", test);
// }