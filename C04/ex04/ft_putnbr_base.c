/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 21:00:57 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/15 14:57:50 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	basecheck(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[1])
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '+'
				|| base[i] == '-' || base[i] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	printer(int nbr, int divnumber, char *input)
{
	int	a;

	if (nbr != 0)
	{
		a = nbr % divnumber;
		printer(nbr / divnumber, divnumber, input);
		write(1, &input[a], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	divnumber;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	divnumber = basecheck(base);
	if (divnumber != 0)
		printer(nbr, divnumber, base);
	if (nbr == 0)
		write(1, "0", 1);
}

// int	main(void)
// {
// 	ft_putnbr_base(0, "0123456789ABCDEF");
// }