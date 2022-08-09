/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 16:36:08 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/13 20:58:42 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dcount;

	i = 0;
	dcount = 0;
	while (dest[dcount])
	{
		dcount++;
	}
	while (i < nb && src[i])
	{
		dest[dcount] = src[i];
		i++;
		dcount++;
	}
	dest[dcount] = '\0';
	return (dest);
}

// int main () 
// {
//    char src[] = "This is source";
//    char	dest[] = "This is destination";

//    ft_strncat(dest, src, 9);
//    printf("%s", dest);
//    return(0);
// }