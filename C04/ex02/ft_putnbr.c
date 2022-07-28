/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 16:26:04 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/14 20:48:37 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	recur(int nb)
{
	int	a;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb != 0)
	{
		a = nb % 10 + '0';
		recur(nb / 10);
		write(1, &a, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb != 0)
		recur(nb);
	else if (nb == 0)
		write(1, "0", 1);
}

// int main()
// {
// 	ft_putnbr(726571868);
// }