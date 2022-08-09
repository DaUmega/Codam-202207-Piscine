/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 19:05:53 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/20 13:29:15 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	long long	i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i < nb && i * i < (long long)2147483647)
	{
		i++;
	}
	if (i * i == nb)
		return (i);
	return (0);
}

// int main()
// {
// 	int i = ft_sqrt(2147483647);
// 	printf("%d", i);
// }