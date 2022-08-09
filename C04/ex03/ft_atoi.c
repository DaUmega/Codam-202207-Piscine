/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 17:44:27 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/23 20:19:39 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	ans;

	i = 0;
	ans = 0;
	neg = 1;
	while (str[i] && str[i] >= 32)
	{
		if (str[i] == '-')
			neg *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			ans = ans * 10 + str[i] - '0';
			if ((str[i + 1] < '0' || str[i + 1] > '9'))
				return (ans * neg);
		}
		i++;
	}
	return (0);
}

// int main(void)
// { MIGHT NEED TO ADD CHECKS TO ENSURE IT"S EITHER SPACE + or - IN THE BEGINNING!!
// 	int test;
// 	test = ft_atoi(" ---+--+1234ab567");
// 	printf("%d\n", test);
// }