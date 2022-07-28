/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapdata.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/27 11:09:02 by dkolodze      #+#    #+#                 */
/*   Updated: 2022/07/27 16:59:35 by pdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPDATA_H
# define MAPDATA_H

typedef struct s_mapdata
{
	char	empty;
	char	obsta;
	char	full;
	int		rows;
	char	**map;
}	t_mapdata;

typedef struct s_solver
{
	int	x;
	int	y;
	int	sqsize;
}	t_solver;

t_solver	solver(int **arr, t_mapdata info);
int			ft_strlen(const char *a);
t_solver	empty_solution(void);
t_mapdata	read_map(int fd);
int			is_empty(t_mapdata info);
void		free_map(t_mapdata info);
t_solver	apply_algo(t_mapdata info);
void		print_map(t_mapdata info);
void		mapwriter(t_solver ans, t_mapdata info);
t_mapdata	mapdata(char *str);
t_mapdata	empty_mapdata(void);
char		*readline(int fd);

#endif
