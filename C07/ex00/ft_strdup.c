/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/20 17:24:07 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/21 13:08:11 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		slen;
	int		i;
	char	*ans;

	slen = 0;
	while (src[slen])
		slen++;
	ans = malloc(sizeof(src) * (slen + 1));
	if (ans == '\0')
		return (0);
	i = 0;
	while (src[i])
	{
		ans[i] = src[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
