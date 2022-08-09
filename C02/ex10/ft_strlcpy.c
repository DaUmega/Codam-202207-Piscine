/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/11 14:20:38 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/11 23:46:34 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				counter;

	i = 0;
	counter = 0;
	while (src[i])
	{
		counter++;
		i++;
	}
	i = 0;
	while (i <= size)
	{
		dest[i] = src[i];
		i++;
		if (src[i] == '\0' || i == size)
		{
			dest[i] = '\0';
			i++;
			return (counter);
		}
	}
	return (counter);
}

/*int main()
{
	char a[] = "abcdef";
	char b[] = "1234567";
	int counter = ft_strlcpy(b, a, 4);
	printf("%s\n", b);
	printf("%d", counter);
}*/