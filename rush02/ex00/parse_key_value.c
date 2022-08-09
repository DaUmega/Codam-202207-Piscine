/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_key_value.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsarkoh <fsarkoh@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/23 14:42:22 by fsarkoh       #+#    #+#                 */
/*   Updated: 2022/07/26 15:30:53 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_str_len(char *str);
int	ft_strlen(const char *a);

int	is_valid_dict_entry(char *str)
{
	int	pos;
	int	has_digit;

	has_digit = 0;
	pos = 0;
	while (str[pos] <= '9' && str[pos] >= '0')
	{
		++pos;
		has_digit = 1;
	}
	if (!has_digit)
		return (0);
	while (str[pos] == ' ')
		++pos;
	if (str[pos] != ':')
		return (0);
	return (1);
}

char	*get_val(char	*str)
{
	int		offset;
	int		val_offset;
	int		size;
	char	*val;

	offset = 0;
	while (*(str + offset) != ':')
	{
		offset++;
	}
	offset++;
	while (*(str + offset) == ' ')
	{
		offset++;
	}
	size = ft_strlen(str + offset);
	val = malloc(size + 1);
	val_offset = 0;
	while (val_offset < size)
	{
		*(val + val_offset) = *(str + offset + val_offset);
		val_offset++;
	}
	*(val + size) = 0;
	return (val);
}

char	*get_key(char *str)
{
	int		offset;
	int		size;
	char	*key;

	return NULL;
	size = get_str_len(str);
	key = malloc(size + 1);
	offset = 0;
	while (offset < size && *(str + offset) != ' ')
	{
		*(key + offset) = *(str + offset);
		offset++;
	}
	*(key + offset) = 0;
	return (key);
}

int	get_str_len(char *str)
{
	int	offset;

	offset = 0;
	while (*(str + offset) != 0)
	{
		if (*(str + offset) == ':')
		{
			break ;
		}
		offset++;
	}
	return (offset);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s$\n", get_key("11: eleven"));
	printf("%s$\n", get_val("11: eleven"));
}
*/
