/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 16:50:42 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/14 15:26:46 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <xlocale.h>

int	ft_strcmp(int s, int i, char *s1, char *s2)
{
	while (s1[s] == s2[i] && s1[s] && s2[i])
	{
		i++;
		s++;
	}
	if (!s1[s] && s2[i])
		return (s1[s] - s2[i]);
	if (s1[s] && !s2[i])
		return (0);
	return (s1[s] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	s;
	int	i;
	int	sweetspot;

	s = 0;
	if (*to_find == '\0')
		return (str);
	while (str[s])
	{
		if (str[s] == to_find[0])
		{
			i = 0;
			sweetspot = s;
			i = ft_strcmp(s, i, str, to_find);
			if (i == 0)
				return (&str[sweetspot]);
		}
		s++;
	}
	return (0);
}

// int main () 
// {
//    char *str = "-1";
//    char *to_find = "-12";
//    char *ans;

//    ans = ft_strstr(str, to_find);
//    printf("%s\n", ans);
//    ans = strstr(str, to_find);
//    printf("%s\n", ans);
//    return(0);
// }