/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_numbers.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:59:50 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/07 16:01:50 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	first;

	first = '0';
	while (first <= '9')
	{
		write(1, &first, 1);
		first++;
	}
}
