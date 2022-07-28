/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/23 16:39:55 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/23 19:39:29 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	are_equal(const char *s1, const char *s2)
{
	int	pos;

	pos = 0;
	while (s1[pos] != '\0' && s2[pos] != '\0' && s1[pos] == s2[pos])
	{
		++pos;
	}
	return (s1[pos] == s2[pos]);
}
