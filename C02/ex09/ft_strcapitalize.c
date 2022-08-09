/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcapitalize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/10 15:07:24 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/11 23:51:54 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ifchecks(char *str, int i)
{
	if (str[i] >= 'A' && str[i] <= 'Z'
		&& ((str[i - 1] >= '0' && str[i - 1] <= '9')
			|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			|| (str[i - 1] >= 'a' && str[i - 1] <= 'z')))
	{
		str[i] += 32;
		return (str);
	}
	else if (str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] < '0'
			|| (str[i - 1] > '9' && str[i - 1] < 'A')
			|| (str[i - 1] > 'Z' && str[i - 1] < 'a') || (str[i - 1] > 'z')))
	{
		str[i] -= 32;
		return (str);
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 32;
	}
	while (str[i] != '\0')
	{
		ifchecks(str, i);
		i++;
	}
	return (str);
}

/*int main()
{
    char a[] = "=/A{*E|+dA'>   J`?@b]q ?@FFXebK@).aU^@";
    char *b;
    b = ft_strcapitalize(a);
    printf("%s", b);
}*/