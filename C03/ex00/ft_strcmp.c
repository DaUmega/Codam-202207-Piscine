/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/11 17:51:14 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/18 15:40:06 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

// int main() 
// {
//   char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
//   int result;

//   result = ft_strcmp(str1, str2);
//   printf("%d\n", result);
//   result = ft_strcmp(str1, str3);
//   printf("%d\n", result);
//   return 0;
// }