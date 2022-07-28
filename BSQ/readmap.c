/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   readmap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/27 11:41:34 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/27 16:59:38 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mapdata.h"

int	firstlinecheck(char *s, t_mapdata info)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	if (len <= 1 || s[len - 1] != '\n')
		return (0);
	while (s[i] != '\n')
	{
		if (!(s[i] == info.empty || s[i] == info.obsta))
			return (0);
		i++;
	}
	return (len);
}

int	linecheck(char *s, t_mapdata info, int len)
{
	int	i;

	i = 0;
	if (len != ft_strlen(s) || s[len - 1] != '\n')
		return (0);
	while (s[i] != '\n')
	{
		if (!(s[i] == info.empty || s[i] == info.obsta))
			return (0);
		i++;
	}
	return (1);
}

t_mapdata	read_map_header(int fd)
{
	char		*s;
	t_mapdata	info;

	s = readline(fd);
	if (s == NULL)
		return (empty_mapdata());
	info = mapdata(s);
	free(s);
	return (info);
}

t_mapdata	read_map_loop(int fd, t_mapdata info, int len)
{
	int		i;
	char	*s;

	i = 1;
	s = readline(fd);
	while (i < info.rows && s != NULL)
	{
		if (linecheck(s, info, len) == 0)
		{
			free(s);
			free_map(info);
			return (empty_mapdata());
		}
		info.map[i] = s;
		s = readline(fd);
		++i;
	}
	if (i < info.rows || s != NULL)
	{
		free_map(info);
		free(s);
		return (empty_mapdata());
	}
	return (info);
}

t_mapdata	read_map(int fd)
{
	char		*s;
	t_mapdata	info;
	int			i;
	int			len;

	info = read_map_header(fd);
	if (is_empty(info))
		return (empty_mapdata());
	s = readline(fd);
	if (s == NULL)
		return (empty_mapdata());
	len = firstlinecheck(s, info);
	info.map = malloc(sizeof(char *) * info.rows);
	if (len == 0 || info.map == NULL)
	{
		free(s);
		return (empty_mapdata());
	}
	info.map[0] = s;
	i = 1;
	while (i < info.rows)
		info.map[i++] = NULL;
	return (read_map_loop(fd, info, len));
}

/*
void	print_map(t_mapdata info);
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	t_mapdata info = read_map(fd);
	print_map(info);
	free_map(info);
	close(fd);
	return (0);
}
*/
