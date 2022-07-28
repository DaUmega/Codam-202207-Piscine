/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_non_printable.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/11 15:06:33 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/26 21:31:32 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	hex(int i)
{
	char	*letters;
	int		temp;

	letters = "0123456789abcdef";
	if (i >= 16)
	{
		temp = i % 16;
		write(1, "\\", 1);
		write(1, "1", 1);
		write(1, &letters[temp], 1);
	}
	else
	{
		write(1, "\\", 1);
		write(1, "0", 1);
		write(1, &letters[i], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			write(1, &str[i], 1);
			i++;
		}
		else
		{
			hex(str[i]);
			i++;
		}
	}
}

/*int main()
{
    ft_putstr_non_printable("Coucou\ntu vas bien ?");
}*/