/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dict_read.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/23 16:04:09 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/24 15:37:24 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*readline(int fd);
char	*get_key(char *str);
char	*get_val(char *str);
int		is_valid_dict_entry(char *str);
void	free_dict(char ***dict, int n_filled_arrs);
char	***allocate_dict(void);
int		assign_singles(char *key, char *value, char **singles_dict);
int		assign_tens(char *key, char *value, char **tens_dict);
int		assign_powers(char *key, char *value, char **powers_dict);

void	check_dict(char ****dict)
{
	const int	sizes[3] = {20, 9, 12};
	int			pos;
	int			i;

	pos = 0;
	while (pos < 3)
	{
		i = 0;
		while (i < sizes[pos])
		{
			if ((*dict)[pos][i] == 0)
			{
				free_dict(*dict, 3);
				*dict = 0;
				return ;
			}
			++i;
		}
		++pos;
	}
}

void	fill_dict(int fd, char ***dict)
{
	char	*line;
	char	*key;
	char	*value;
	int		was_assigned;

	line = readline(fd);
	while (line != 0)
	{
		if (is_valid_dict_entry(line))
		{
			key = get_key(line);
			value = get_val(line);
			was_assigned = assign_singles(key, value, dict[0]);
			was_assigned |= assign_tens(key, value, dict[1]);
			was_assigned |= assign_powers(key, value, dict[2]);
			if (!was_assigned)
				free(value);
			free(key);
		}
		free(line);
		line = readline(fd);
	}
}

void	prepare_dict(char ****dict, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		*dict = 0;
		return ;
	}
	*dict = allocate_dict();
	if (*dict == 0)
	{
		close(fd);
		return ;
	}
	fill_dict(fd, *dict);
	check_dict(dict);
	close(fd);
}

/*
#include <stdio.h>
int main()
{	
	int fd = open("numbers.dict", O_RDONLY);
	int sizes[] = {20, 9, 12};
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}

	char ***dict = allocate_dict();
	fill_dict(fd, dict);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < sizes[i]; ++j)
		{
			printf("%s\n", dict[i][j]);
		}
		printf("\n\n\n");
	}
	free_dict(dict, 3);
	close(fd);
}
*/
