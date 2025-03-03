/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:40 by hakader           #+#    #+#             */
/*   Updated: 2025/03/03 19:32:22 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define ESC_KEY 65307
# define X_KEY 17

# include <mlx.h>
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
	int		P;
	int		E;
	int		C;
	int		row;
	int		column;
	char	**map;
	char	**copy;
}	t_map;


typedef struct s_mlx
{
	t_map	game;
	t_axis	axis;
	void	*mlx;
	void	*win;
}	t_mlx;

char	**read_map(char *map);
void	print_arr(char **str);
void	free_arr(char **str);
void	check_rl_walls(t_mlx *game);
void	check_fl_walls(t_mlx *game);
void	fl_walls(t_mlx *game, int y);
void	flood_fill(char **tab, t_mlx size, t_mlx begin);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *str, int fd);
void	put_err(char *str);

#endif
