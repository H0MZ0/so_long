/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:21:31 by hakader           #+#    #+#             */
/*   Updated: 2025/03/06 22:33:40 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pars_square(t_mlx *mlx)
{
	int	check;

	check = 0;
	mlx->axis.y = 0;
	if (!mlx->game.map)
		return ;
	while (mlx->game.map[0][check] && mlx->game.map[0][check] != '\n')
		check++;
	while (mlx->game.map[mlx->axis.y])
	{
		mlx->axis.x = 0;
		while (mlx->game.map[mlx->axis.y][mlx->axis.x]
			&& mlx->game.map[mlx->axis.y][mlx->axis.x] != '\n')
			mlx->axis.x++;
		if (check != mlx->axis.x)
			put_err("Error:\nInvalid map\n");
		mlx->axis.y++;
	}
}

void	count_things(t_mlx *mlx, int check)
{
	mlx->game.P = 0;
	mlx->game.E = 0;
	mlx->game.C = 0;
	mlx->axis.y = 0;
	while (mlx->game.map[mlx->axis.y])
	{
		mlx->axis.x = 0;
		while (mlx->game.map[mlx->axis.y][mlx->axis.x])
		{
			if (mlx->game.map[mlx->axis.y][mlx->axis.x] == 'P')
				mlx->game.P++;
			if (mlx->game.map[mlx->axis.y][mlx->axis.x] == 'E')
				mlx->game.E++;
			if (mlx->game.map[mlx->axis.y][mlx->axis.x] == 'C')
				mlx->game.C++;
			mlx->axis.x++;
		}
		mlx->axis.y++;
	}
	if ((mlx->game.C < 1 || mlx->game.P != 1 || mlx->game.E != 1) && check == 1)
		put_err("Error:\nCheck your map\n");
}

void	check_others(t_mlx *mlx)
{
	mlx->axis.y = 0;
	while (mlx->game.map[mlx->axis.y])
	{
		mlx->axis.x = 0;
		while (mlx->game.map[mlx->axis.y][mlx->axis.x])
		{
			if (!(mlx->game.map[mlx->axis.y][mlx->axis.x] == 'C'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == 'E'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == 'P'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == '0'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == '1'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == '\n'))
				put_err("Error:\nInvalid character in map\n");
			mlx->axis.x++;
		}
		mlx->axis.y++;
	}
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

void	copy_map(t_mlx *mlx)
{
	int	i;
	int	row;
	int	column;

	i = 0;
	row = mlx->game.row;
	column = mlx->game.column;
	mlx->game.copy = malloc(sizeof(char *) * (row + 1));
	if (!mlx->game.copy)
		return;
	while (i < row)
	{
		mlx->game.copy[i] = malloc(sizeof(char) * (column + 1));
		if (!mlx->game.copy[i])
			return;
		ft_strcpy(mlx->game.copy[i], mlx->game.map[i]);
		i++;
	}
	mlx->game.copy[row] = NULL;
}


void	map_filter(char *map)
{
	t_mlx	mlx;

	mlx.game.map = read_map(map);
	pars_square(&mlx);
	check_fl_walls(&mlx);
	check_rl_walls(&mlx);
	check_others(&mlx);
	count_things(&mlx, 1);
	copy_map(&mlx);
	in_mlx(&mlx);
}


int	main(int ac, char **av)
{
	if (ac != 2)
		put_err("Error:\n<program> <map>\n");
	if (!(ft_strcmp(".ber", &av[1][ft_strlen(av[1]) - 4]) == 0
		&& ft_strlen(av[1]) > 4))
		put_err("Error:\nInvalid map\n");
	map_filter(av[1]);
	return (0);
}
