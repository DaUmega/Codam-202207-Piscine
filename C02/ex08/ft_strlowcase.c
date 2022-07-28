/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlowcase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/10 15:05:45 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/11 20:56:34 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			i++;
		}
		else
		{
			i++;
		}
	}
	return (str);
}

/*int main()
{
    char a[] = "asdfasABC123^&*(/df";
    char *b;
    b = ft_strlowcase(a);
    printf("%s", b);
}*/