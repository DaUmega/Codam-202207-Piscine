/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/23 12:25:45 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/26 15:28:16 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		ft_strlen(const char *a);
int		strchk(char *a);
void	arrmaker(int arr[], char *str);
void	combwriter(int arr[], char *str, char ***dict);
void	free_dict(char ***dict, int n_filled_arrs);
void	prepare_dict(char ****dict, char *filename);

void	solve(char *number, char *filename)
{
	int		arr[15];
	char	***dict;

	prepare_dict(&dict, filename);
	if (dict == 0)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	if (number[0] == '0')
	{
		write(1, dict[0][0], ft_strlen(dict[0][0]));
		write(1, "\n", 1);
		free_dict(dict, 3);
		return ;
	}
	arrmaker(arr, number);
	combwriter(arr, number, dict);
	write(1, "\n", 1);
	free_dict(dict, 3);
}
#include <stdlib.h>
int	main(int argc, char **argv)
{
	int		i;
	char	*filename;

	i = 1;
	filename = "numbers.dict";
	if (argc > 3 || argc < 2 || (argc == 2 && strchk(argv[1]) == 0)
		|| (argc == 3 && strchk(argv[2]) == 0))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if (argc == 3)
	{
		filename = argv[1];
		i = 2;
	}
	solve(argv[i], filename);
	system("leaks rush-02");
	return (0);
}
