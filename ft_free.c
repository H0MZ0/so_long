/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:15:31 by hakader           #+#    #+#             */
/*   Updated: 2025/03/08 01:37:28 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int lines)
{
	int	i;
	i = 0;
	while (i < lines && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_images(t_mlx *mlx)
{
	// int	i;
	// i = 0;
	// while (i < 10)
	// {
	// 	if (mlx->img.collection_frames[i])
	// 		mlx_destroy_image(mlx->mlx, mlx->img.collection_frames[i]);
	// 	i++;
	// }
	if (mlx->tx.wall)
		mlx_destroy_image(mlx->mlx, mlx->tx.wall);
	if (mlx->tx.floor)
		mlx_destroy_image(mlx->mlx, mlx->tx.floor);
	if (mlx->tx.door)
		mlx_destroy_image(mlx->mlx, mlx->tx.door);
	if (mlx->tx.player)
		mlx_destroy_image(mlx->mlx, mlx->tx.player);
	// if (mlx->tx.enemy)
	// 	mlx_destroy_image(mlx->mlx, mlx->tx.enemy);
}

int	close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	free_images(mlx);
	free_map(mlx->game.map, mlx->game.column);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_loop_end(mlx->mlx);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	exit(0);
}
