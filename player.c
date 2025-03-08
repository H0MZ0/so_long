/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:09:16 by hakader           #+#    #+#             */
/*   Updated: 2025/03/08 02:48:33 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_mlx *mlx, int new_x, int new_y)
{
	count_things(mlx, 0);
	if (mlx->game.c == 0 && mlx->game.map[new_y][new_x] == 'E')
	{
		mlx->game.map[new_y][new_x] = 'P';
		mlx->game.map[mlx->p_y][mlx->p_x] = '0';
		close_window(mlx);
	}
	if (mlx->game.map[new_y][new_x] == '0'
		|| mlx->game.map[new_y][new_x] == 'C')
	{
		mlx->game.map[new_y][new_x] = 'P';
		mlx->game.map[mlx->p_y][mlx->p_x] = '0';
	}
}
