/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 14:27:53 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/23 20:19:35 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

// int main() 
// {
//   char str1[] = "abcD", str2[] = "abcd";
//   int result;
//   result = ft_strncmp(str1, str2, 5);
//   printf("%d\n", result);
//   result = strncmp(str1, str2, 5);
//   printf("%d\n", result);
//   return 0;
// }