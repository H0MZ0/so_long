/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:42:15 by hakader           #+#    #+#             */
/*   Updated: 2025/03/08 03:45:31 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		return ;
	mlx->game.copy[row] = NULL;
	while (i < row)
	{
		mlx->game.copy[i] = malloc(sizeof(char) * (column + 1));
		if (!mlx->game.copy[i])
		{
			free_arr(mlx->game.copy);
			return ;
		}
		ft_strcpy(mlx->game.copy[i], mlx->game.map[i]);
		i++;
	}
}

void	find_player(t_mlx *mlx)
{
	mlx->p_y = 0;
	while (mlx->game.map[mlx->p_y])
	{
		mlx->p_x = 0;
		while (mlx->game.map[mlx->p_y][mlx->p_x])
		{
			if (mlx->game.map[mlx->p_y][mlx->p_x] == 'P')
				return ;
			mlx->p_x++;
		}
		mlx->p_y++;
	}
}
