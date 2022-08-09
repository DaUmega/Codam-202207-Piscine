/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 12:02:04 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/14 16:26:32 by pdong         ########   odam.nl         */
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

int	stringconvert(char *str)
{
	int	i;
	int	negcount;
	int	ans;

	i = 0;
	ans = 0;
	negcount = 0;
	while (str[i])
	{
		if (str[i] == '-')
			negcount++;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			ans = ans * 10 + str[i] - '0';
			if ((str[i + 1] < '0' || str[i + 1] > '9') && negcount % 2 == 1)
				return (ans * -1);
			if ((str[i + 1] < '0' || str[i + 1] > '9') && negcount % 2 == 0)
				return (ans);
		}
		i++;
	}
	return (0);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	c;
	int	half;

	i = 0;
	half = size / 2;
	while (size > half)
	{
		c = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = c;
		size--;
		i++;
	}
}

int	converter(int nbr, int divnumber, char *input)
{
	int	a;
	int	*ans;

	a = 0;
	while (nbr != 0)
	{
		ans[a] = input[nbr % divnumber];
		nbr = nbr / divnumber;
		a++;
	}
	ft_rev_int_tab(ans, a);
	return (*ans);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	divnumber;

	nbr = stringconvert(str);
	divnumber = basecheck(base);
	if (divnumber != 0)
		return (converter(nbr, divnumber, base));
	return (0);
}

// int main(void)
// {
// 	int *test;
// 	test = ft_atoi_base(" ---+--+1234ab567", "0123456789");
// 	printf("%d", test);
// }