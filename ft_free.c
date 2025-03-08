/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:15:31 by hakader           #+#    #+#             */
/*   Updated: 2025/03/08 02:10:21 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_mlx *mlx)
{
	if (mlx->tx.wall)
		mlx_destroy_image(mlx->mlx, mlx->tx.wall);
	if (mlx->tx.floor)
		mlx_destroy_image(mlx->mlx, mlx->tx.floor);
	if (mlx->tx.player)
		mlx_destroy_image(mlx->mlx, mlx->tx.player);
	if (mlx->tx.coin)
		mlx_destroy_image(mlx->mlx, mlx->tx.coin);
	if (mlx->tx.door)
		mlx_destroy_image(mlx->mlx, mlx->tx.door);
}

int	close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_images(mlx);
	free_arr(mlx->game.map);
	free_arr(mlx->game.copy);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}
