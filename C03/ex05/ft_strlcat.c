/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 17:50:55 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/14 15:57:06 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

unsigned int	lencounter(char *a)
{
	unsigned int	i;

	i = 0;
	while (a[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	dlen = lencounter(dest);
	slen = lencounter(src);
	if (size <= dlen)
		return (size + slen);
	while (i < size && src[i])
	{
		dest[dlen] = src[i];
		i++;
		dlen++;
	}
	dest[dlen] = '\0';
	return (lencounter(dest) + lencounter(&src[i]));
}

// int main () 
// {
//    	char	src[] = "asdfasdf";
//    	char	dest[] = "Testtest";
//    	int i = ft_strlcat(dest, src, 9);
//    	printf("%s\n", dest);
//    	printf("%d\n", i);
// 	i = strlcat(dest, src, 9);
//    	printf("%s\n", dest);
//    	printf("%d\n", i);
//    	return(0);
// }