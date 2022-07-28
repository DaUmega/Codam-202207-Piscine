/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultimate_range.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/21 13:13:20 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/21 16:43:57 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*ans;

	if (min >= max)
	{
		ans = 0;
		return (0);
	}
	ans = malloc(sizeof(ans) * (max - min));
	if (ans == '\0')
		return (-1);
	i = 0;
	while (min < max)
	{
		ans[i] = min;
		min++;
		i++;
	}
	*range = ans;
	return (i);
}

// int		main(void)
// {
// 	int i;
// 	int *test;
// 	int size;

// 	size = ft_ultimate_range(&test, 0, 5);
// 	if (test)
// 	{
// 		i = 0;
// 		while (i < 5)
// 		{
// 			printf("%d\n", test[i]);
// 			i++;
// 		}
// 	}
// 	printf("size: %d", size);
// }
