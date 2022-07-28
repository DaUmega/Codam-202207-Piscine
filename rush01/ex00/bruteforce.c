/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bruteforce.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/16 16:15:54 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/17 22:04:28 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		errorc(int arr[4][4], int **InputArray);
int		dupe1(int arr[4][4]);
int		dupe2(int arr[4][4]);
void	print_error(void);

void	lineswapper(int *input, int n)
{
	const int	arr[24][4] = {
	{1, 2, 3, 4}, {1, 2, 4, 3}, {1, 3, 2, 4}, {1, 3, 4, 2},
	{1, 4, 2, 3}, {1, 4, 3, 2}, {2, 1, 3, 4}, {2, 1, 4, 3},
	{2, 3, 1, 4}, {2, 3, 4, 1}, {2, 4, 1, 3}, {2, 4, 3, 1},
	{3, 1, 2, 4}, {3, 1, 4, 2}, {3, 2, 1, 4}, {3, 2, 4, 1},
	{3, 4, 1, 2}, {3, 4, 2, 1}, {4, 1, 2, 3}, {4, 1, 3, 2},
	{4, 2, 1, 3}, {4, 2, 3, 1}, {4, 3, 1, 2}, {4, 3, 2, 1}};
	int			i;

	i = 0;
	while (i < 4)
	{
		input[i] = arr[n][i];
		i++;
	}
}

void	print_array(int arr[4][4])
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = arr[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	looppart2(int count3, int count4, int arr[4][4], int **uinput)
{
	while (count3 < 24)
	{
		count4 = 0;
		lineswapper(arr[2], count3);
		while (count4 < 24)
		{
			lineswapper(arr[3], count4);
			if (dupe1(arr) == 1 && dupe2(arr) == 1 && errorc(arr, uinput) == 1)
			{
				print_array(arr);
				return (1);
			}
			count4++;
		}
		count3++;
	}
	return (0);
}

int	looppart1(int count1, int count2, int arr[4][4], int **uinput)
{
	int	count3;
	int	count4;
	int	check;

	count3 = 0;
	count4 = 0;
	check = 0;
	while (count1 < 24)
	{
		count2 = 0;
		lineswapper(arr[0], count1);
		while (count2 < 24)
		{
			count3 = 0;
			lineswapper(arr[1], count2);
			if (looppart2(count3, count4, arr, uinput) == 1)
				return (1);
			count2++;
		}
		count1++;
	}
	return (0);
}

void	bruteforce(int **uinput)
{
	int	count1;
	int	count2;
	int	start[4][4];

	count1 = 0;
	count2 = 0;
	if (looppart1(count1, count2, start, uinput) == 0)
		print_error();
}
