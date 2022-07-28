/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assign_values.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/23 19:46:05 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/23 20:03:54 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	are_equal(const char *s1, const char *s2);

int	assign_singles(char *key, char *value, char **singles_dict)
{
	const char	*keys[20] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
		"10", "11", "12", "13", "14", "15", "16", "17", "18", "19"};
	int			pos;

	pos = 0;
	while (pos < 20)
	{
		if (are_equal(key, keys[pos]))
		{
			if (singles_dict[pos] != 0)
			{
				free(singles_dict[pos]);
			}
			singles_dict[pos] = value;
			return (1);
		}
		++pos;
	}
	return (0);
}

int	assign_tens(char *key, char *value, char **tens_dict)
{
	const char	*keys[9] = {"20", "30", "40", "50", "60",
		"70", "80", "90", "100"};
	int			pos;

	pos = 0;
	while (pos < 9)
	{
		if (are_equal(key, keys[pos]))
		{
			if (tens_dict[pos] != 0)
			{
				free(tens_dict[pos]);
			}
			tens_dict[pos] = value;
			return (1);
		}
		++pos;
	}
	return (0);
}

int	assign_powers(char *key, char *value, char **powers_dict)
{
	const char	*keys[12] = {"1000", "1000000", "1000000000", "1000000000000",
		"1000000000000000", "1000000000000000000", "1000000000000000000000",
		"1000000000000000000000000", "1000000000000000000000000000",
		"1000000000000000000000000000000",
		"1000000000000000000000000000000000",
		"1000000000000000000000000000000000000"};
	int			pos;

	pos = 0;
	while (pos < 12)
	{
		if (are_equal(key, keys[pos]))
		{
			if (powers_dict[pos] != 0)
			{
				free(powers_dict[pos]);
			}
			powers_dict[pos] = value;
			return (1);
		}
		++pos;
	}
	return (0);
}
