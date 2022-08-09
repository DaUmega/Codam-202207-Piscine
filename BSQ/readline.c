/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   readline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 13:28:35 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/26 18:52:28 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	copy_n_chars(char *dest, char *src, int n)
{
	int	pos;

	pos = 0;
	while (pos < n)
	{
		dest[pos] = src[pos];
		++pos;
	}
}

void	readloop(int fd, char **ans, int size)
{
	int		pos;
	int		n_read;
	char	*new_buff;

	pos = 1;
	while (*ans != NULL)
	{
		while (pos < size - 1)
		{
			n_read = read(fd, (*ans) + pos, 1);
			if (n_read == 0 || (*ans)[pos] == '\n')
			{
				(*ans)[pos + n_read] = '\0';
				return ;
			}
			++pos;
		}
		new_buff = malloc(sizeof(char) * size * 2);
		if (new_buff != NULL)
			copy_n_chars(new_buff, *ans, pos);
		free(*ans);
		*ans = new_buff;
		size *= 2;
	}
}

/**
 * @brief reads line till the "\n" character or eof
 * If a linebreak is present, the linebreak at the eol if preserved 
 * @param fd file descriptor to read from
 * @return char* freeable string; NULL if nothing read or error
 */
char	*readline(int fd)
{
	char	*ans;
	int		size;
	int		n_read;

	size = 10;
	ans = malloc(sizeof(char) * size);
	if (ans == NULL)
		return (NULL);
	n_read = read(fd, ans, 1);
	if (n_read == 0)
	{
		free(ans);
		return (NULL);
	}
	if (ans[0] == '\n')
	{
		ans[1] = '\0';
		return (ans);
	}
	readloop(fd, &ans, size);
	return (ans);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *s = readline(fd);
	while(s != NULL)
	{
		printf("%s$\n", s);
		free(s);
		s = readline(fd);
	}
	close(fd);
}
*/
