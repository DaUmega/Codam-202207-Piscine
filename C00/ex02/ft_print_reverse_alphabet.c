/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_reverse_alphabet.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:59:50 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/07 16:03:40 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	last;

	last = 122;
	while (last > 96)
	{
		write(1, &last, 1);
		last--;
	}
}
