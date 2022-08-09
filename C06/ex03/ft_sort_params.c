/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_params.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 13:20:05 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/18 15:54:37 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sorter(char **a, int n)
{
	int	j;
	int	k;

	j = 1;
	while (j < n)
	{
		k = j + 1;
		while (k < n)
		{
			if (ft_strcmp(a[j], a[k]) > 0)
				ft_swap(&a[j], &a[k]);
			k++;
		}
		j++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int n, char **a)
{
	int	i;

	i = 1;
	sorter(a, n);
	while (i < n)
	{
		ft_putstr(a[i]);
		write(1, "\n", 1);
		i++;
	}
	return (n);
}
