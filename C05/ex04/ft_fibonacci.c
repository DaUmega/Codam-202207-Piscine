/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fibonacci.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 17:54:40 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/18 19:03:24 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// int main()
// {
// 	int test;
// 	test = ft_fibonacci(4);
// 	printf("%d", test);
// }