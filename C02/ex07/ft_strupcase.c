/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strupcase.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/10 14:33:16 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/11 16:44:04 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
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
    char a[] = "asdfasdf";
    char *b;
    b = ft_strupcase(a);
    printf("%s", b);
}*/