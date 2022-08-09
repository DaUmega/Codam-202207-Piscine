/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_boolean.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdong <pdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 14:20:46 by pdong         #+#    #+#                 */
/*   Updated: 2022/07/25 14:41:21 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include	<unistd.h>
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN(nbr) (nbr % 2)

typedef int	t_bool;

#endif