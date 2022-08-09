/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_range.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/20 19:08:27 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/23 19:14:40 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ans;

	if (min >= max)
		return (NULL);
	ans = malloc(sizeof(ans) * (max - min));
	if (ans == '\0')
		return (0);
	i = 0;
	while (min < max)
	{
		ans[i] = min;
		min++;
		i++;
	}
	return (ans);
}

// int	main(void)
// {
// 	int	i;
// 	int	*test;

// 	i = 0;
// 	test = ft_range(0, 5);
// 	while (i < 5)
// 	{
// 		printf("%d", test[i]);
// 		i++;
// 	}
// }
