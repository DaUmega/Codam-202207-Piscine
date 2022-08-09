/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inputexplosion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/23 18:06:17 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/23 18:06:48 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	strchk(char *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (a[i] < '0' || a[i] > '9')
			return (0);
		i++;
	}
	if (ft_strlen(a) > 39 || ft_strlen(a) < 1)
		return (0);
	if (a[0] == '0' && a[1])
		return (0);
	return (1);
}

int	ft_atoi(char *str, int i)
{
	int	temp;
	int	ans;

	temp = 0;
	ans = 0;
	while (temp < 3)
	{
		ans = ans * 10 + str[i] - '0';
		i++;
		temp++;
	}
	return (ans);
}

void	arrmaker(int arr[], char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	arr[0] = 0;
	if (ft_strlen(str) % 3 != 0)
		j = 1;
	while (i < ft_strlen(str) % 3)
	{
		arr[0] = arr[0] * 10 + str[i] - '0';
		i++;
	}
	while (j <= ft_strlen(str) / 3)
	{
		arr[j] = ft_atoi(str, i);
		i += 3;
		j++;
	}
}
