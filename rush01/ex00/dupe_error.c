/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dupe_error.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/17 16:25:00 by bfranco       #+#    #+#                 */
/*   Updated: 2022/07/17 16:33:13 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	dupe1(int arr[4][4])
{
	int	y;
	int	x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (arr[y][0] + arr[y][1] + arr[y][2] + arr[y][3] != 10)
				return (0);
			if (arr[0][x] + arr[1][x] + arr[2][x] + arr[3][x] != 10)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	dupe2(int arr[4][4])
{
	int	y;
	int	x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (arr[y][0] == arr[y][1] || arr[y][0] == arr[y][2]
				|| arr[y][0] == arr[y][3] || arr[y][1] == arr[y][2]
				|| arr[y][1] == arr[y][3] || arr[y][2] == arr[y][3])
				return (0);
			if (arr[0][x] == arr[1][x] || arr[0][x] == arr[2][x]
				|| arr[0][x] == arr[3][x] || arr[1][x] == arr[2][x]
				|| arr[1][x] == arr[3][x] || arr[2][x] == arr[3][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}
