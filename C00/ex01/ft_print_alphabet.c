/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_alphabet.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:59:50 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/07 16:03:59 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	first;

	first = 97;
	while (first < 123)
	{
		write(1, &first, 1);
		first++;
	}
}
