/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strs_to_tab.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 16:31:58 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/25 18:53:40 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ans;

	i = 1;
	ans = (t_stock_str *)malloc(sizeof(t_stock_str) * ac);
	if (!ans)
		return (0);
	while (i < ac)
	{
		ans[i].size = ft_strlen(av[i]);
		ans[i].copy = ft_strcpy(ans[i].copy, av[i]);
		ans[i].str = av[i];
		i++;
	}
	ans[i].size = 0;
	ans[i].copy = 0;
	ans[i].str = 0;
	return (ans);
}

// int main(int ac, char **av)
// {
// 	int i = 1;
// 	char *ans[] = ft_strs_to_tab(ac, av);

// 	while (i < ac)
// 		printf("%s", ans[i]);
// 	free (ans);
// }