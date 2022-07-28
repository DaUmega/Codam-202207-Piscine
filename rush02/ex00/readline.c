/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   readline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/23 12:55:41 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/24 15:09:16 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	copy_n_chars(char *src, char *dest, int n)
{
	int	pos;

	pos = 0;
	while (pos < n)
	{
		dest[pos] = src[pos];
		++pos;
	}
}

void	read_to_buffer(int fd, char **buffer, int size)
{
	int		pos;
	int		len_read;
	char	*new_buffer;

	pos = 1;
	while (*buffer != 0)
	{
		while (pos < size)
		{
			len_read = read(fd, (*buffer) + pos, 1);
			if (len_read == 0 || (*buffer)[pos] == '\n')
			{
				(*buffer)[pos] = '\0';
				return ;
			}
			++pos;
		}
		new_buffer = malloc((sizeof(char)) * size * 2);
		if (new_buffer != 0)
			copy_n_chars(*buffer, new_buffer, size);
		free(*buffer);
		*buffer = new_buffer;
		size *= 2;
	}
}

char	*readline(int fd)
{
	char	*ans;
	int		size;

	size = 10;
	ans = malloc((sizeof (char)) * (size));
	if (read(fd, ans, 1) == 0)
	{
		free(ans);
		return (0);
	}
	if (ans[0] == '\n')
	{
		ans[0] = '\0';
		return (ans);
	}
	read_to_buffer(fd, &ans, size);
	return (ans);
}

/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	char	*line = readline(fd);
	while(line != 0)
	{
		printf("%s$\n", line);
		free(line);
		line = readline(fd);
	}
	close(fd);
}
*/
