/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/23 19:42:10 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/23 20:56:59 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strlen(const char *a);

int	hundwriter(char **singles, char **tens, int a)
{
	int	temp;

	temp = a / 100;
	write(1, singles[temp], ft_strlen(singles[temp]));
	write(1, " ", 1);
	write(1, tens[8], ft_strlen(tens[8]));
	a = a - (temp * 100);
	if (a != 0)
		write(1, " ", 1);
	return (a);
}

int	tenswriter(char **tens, int a)
{
	int	temp;

	temp = a / 10;
	write(1, tens[temp - 2], ft_strlen(tens[temp - 2]));
	a = a - (temp * 10);
	if (a != 0)
		write(1, " ", 1);
	return (a);
}

int	blankchk(int arr[], int j)
{
	j += 1;
	while (j < 15)
	{
		if (arr[j] != 0)
			return (0);
		j++;
	}
	return (1);
}

void	writer(int a, char ***dict)
{
	char	**singles;
	char	**tens;

	singles = dict[0];
	tens = dict[1];
	if (a != 0)
	{
		if (a / 100 != 0)
		{
			a = hundwriter(singles, tens, a);
		}
		if (a >= 20)
		{
			a = tenswriter(tens, a);
		}
		if (a < 20 && a > 0)
		{
			write(1, singles[a], ft_strlen(singles[a]));
		}
	}
}

void	combwriter(int arr[], char *str, char ***dict)
{
	char	**powers;
	int		i;
	int		j;

	powers = dict[2];
	i = (ft_strlen(str) - 1) / 3;
	j = 0;
	while (i >= 0)
	{
		if (arr[j] != 0)
		{
			writer(arr[j], dict);
			if (i != 0)
			{
				write(1, " ", 1);
				write(1, powers[i - 1], ft_strlen(powers[i - 1]));
				if (blankchk(arr, j) == 0)
					write(1, " ", 1);
			}
		}
		i--;
		j++;
	}
}
