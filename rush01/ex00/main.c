/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 17:44:27 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/17 22:06:08 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	bruteforce(int **uinput);
void	print_error(void);

int	**mem(int **ans, int i)
{
	ans = malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		ans[i] = malloc(sizeof(int *) * 4);
		i++;
	}
	return (ans);
}

int	error(char *str)
{
	int	i;
	int	strlen;

	i = 1;
	strlen = 0;
	while (str[i] == ' ' && i < 31)
		i += 2;
	while (str[strlen])
		strlen++;
	if (i == 31 && strlen == 31)
		return (1);
	return (0);
}

int	**ft_atoi(char *str)
{
	int	i;
	int	**ans;
	int	a;
	int	b;

	ans = 0;
	i = 0;
	ans = mem(ans, i);
	a = 0;
	b = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4' && a < 4)
		{
			ans[a][b] = str[i] - '0';
			b++;
			if (b > 3)
			{
				b = 0;
				a++;
			}
		}
		i++;
	}
	return (ans);
}

int	main(int argc, char **argv)
{
	int	**uinput;

	if (argc != 2)
	{
		print_error();
		return (0);
	}
	else if (error(argv[1]) == 1)
	{
		uinput = ft_atoi(argv[1]);
		bruteforce(uinput);
	}
	else
	{
		print_error();
		return (0);
	}
}
