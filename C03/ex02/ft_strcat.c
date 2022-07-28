/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 15:22:02 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/13 20:58:44 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	d;
	int	s;

	d = 0;
	s = 0;
	while (dest[d])
	{
		d++;
	}
	while (src[s])
	{
		dest[d] = src[s];
		s++;
		d++;
	}
	dest[d] = '\0';
	return (dest);
}

// int main ()
// {
//    char	src[] = " fAhowIIBqQwrSAvmLGoOFzdboDlZrWqyvzpP";
//    char	dest[] = "RDOdzWyNawJuZkUKfPefPEvDuCfA";

//    ft_strcat(dest, src);
//    printf("%s", dest);
//    return(0);
// }