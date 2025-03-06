/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:09:16 by hakader           #+#    #+#             */
/*   Updated: 2025/03/06 19:36:03 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	move_player(t_mlx *mlx, int new_x, int new_y)
{
	if (mlx->game.map[new_y][new_x] == '0'
		|| mlx->game.map[new_y][new_x] == 'C')
	{
		mlx->game.map[new_y][new_x] = 'P';
		mlx->game.map[mlx->p_y][mlx->p_x] = '0';
	}
}
