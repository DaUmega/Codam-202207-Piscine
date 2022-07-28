/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/17 16:20:53 by bfranco       #+#    #+#                 */
/*   Updated: 2022/07/17 16:21:53 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	error1(int arr[4][4], int **InputArray)
{
	int	y;
	int	x;
	int	counter;
	int	max;

	x = 0;
	while (x <= 3)
	{
		counter = 1;
		y = 0;
		max = arr[0][x];
		while (y <= 3)
		{
			if (arr[y][x] > max)
			{
				max = arr[y][x];
				counter++;
			}
			y++;
		}
		if (counter != InputArray[0][x])
			return (0);
		x++;
	}
	return (1);
}

int	error2(int arr[4][4], int **InputArray)
{
	int	y;
	int	x;
	int	counter;
	int	max;

	x = 0;
	while (x <= 3)
	{
		counter = 1;
		y = 3;
		max = arr[3][x];
		while (y >= 0)
		{
			if (arr[y][x] > max)
			{
				max = arr[y][x];
				counter++;
			}
			y--;
		}
		if (counter != InputArray[1][x])
			return (0);
		x++;
	}
	return (1);
}

int	error3(int arr[4][4], int **InputArray)
{
	int	y;
	int	x;
	int	counter;
	int	max;

	y = 0;
	while (y <= 3)
	{
		counter = 1;
		x = 0;
		max = arr[y][0];
		while (x <= 3)
		{
			if (arr[y][x] > max)
			{
				max = arr[y][x];
				counter++;
			}
			x++;
		}
		if (counter != InputArray[2][y])
			return (0);
		y++;
	}
	return (1);
}

int	error4(int arr[4][4], int **InputArray)
{
	int	y;
	int	x;
	int	counter;
	int	max;

	y = 0;
	while (y <= 3)
	{
		counter = 1;
		x = 3;
		max = arr[y][3];
		while (x >= 0)
		{
			if (arr[y][x] > max)
			{
				max = arr[y][x];
				counter++;
			}
			x--;
		}
		if (counter != InputArray[3][y])
			return (0);
		y++;
	}
	return (1);
}

int	errorc(int arr[4][4], int **InputArray)
{
	if (error1(arr, InputArray) == 0 || error2(arr, InputArray) == 0
		|| error3(arr, InputArray) == 0 || error4(arr, InputArray) == 0)
		return (0);
	return (1);
}
