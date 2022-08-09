/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/21 17:12:50 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/22 11:30:56 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strcat(int d, char *dest, char *src)
{
	int	s;

	s = 0;
	while (src[s])
	{
		dest[d] = src[s];
		s++;
		d++;
	}
	return (d);
}

int	counter(char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

void	joiner(char *ans, char **strs, char *sep, int size)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (i < size)
	{
		d = ft_strcat(d, ans, strs[i]);
		if (i < size - 1)
			d = ft_strcat(d, ans, sep);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		seplen;
	int		totlen;
	int		i;
	char	*ans;

	if (size == 0)
	{
		ans = malloc(1);
		ans[0] = '\0';
		return (ans);
	}
	seplen = counter(sep);
	i = 0;
	totlen = 0;
	while (i < size)
	{
		totlen = totlen + counter(strs[i]);
		i++;
	}
	totlen += seplen * (size - 1) + 1;
	ans = malloc(sizeof(ans) * totlen);
	joiner(ans, strs, sep, size);
	ans[totlen - 1] = '\0';
	return (ans);
}

// int main()
// {
// 	char	*result;
// 	char	*sep = ", ";
// 	char	*strs[] = {"abc", "bcd", "ef"};
// 	result = ft_strjoin(0, strs, sep);
// 	printf("%s\n", result);
// 	free(result);
// 	return 0;
// }