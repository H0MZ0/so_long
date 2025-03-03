/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:40 by hakader           #+#    #+#             */
/*   Updated: 2025/03/03 00:42:12 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define ESC_KEY 65307

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "GNL/get_next_line.h"

typedef struct s_axis
{
	int		x;
	int		y;
}	t_axis;

typedef struct s_map
{
	t_axis	axis;
	int		p;
	int		e;
	int		c;
	int		row;
	int		column;
	char	**map;
	char	**copy;
}	t_map;

char	**read_map(char *map);
void	print_arr(char **str);
void	free_arr(char **str);
void	check_rl_walls(t_map *game);
void	check_fl_walls(t_map *game);
void	fl_walls(t_map *game, int y);
void	flood_fill(char **tab, t_map size, t_map begin);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *str, int fd);
void	put_err(char *str);

#endif
