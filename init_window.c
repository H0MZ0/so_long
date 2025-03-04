/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:07:21 by hakader           #+#    #+#             */
/*   Updated: 2025/03/04 01:49:28 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	key_hook(int keyhook, void *param)
{
	(void)param;
	if (keyhook == ESC_KEY)
		exit (0);
	return (0);
}

// void	xpm_to_image(t_mlx *mlx)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	mlx->tx.wall = mlx_xpm_to_image(mlx->mlx, "texture/mandatory/wall.xpm", x * 80, y * 80);
// 	mlx->tx.floor = mlx_xpm_to_image(mlx->mlx, "texture/mandatory/floor.xpm", x * 80, y * 80);
// 	mlx->tx.coin = mlx_xpm_to_image(mlx->mlx, "texture/mandatory/coin.xpm", x * 80, y * 80);
// 	mlx->tx.hold = mlx_xpm_to_image(mlx->mlx, "texture/mandatory/wall.xpm", x * 80, y * 80);
// }

void	rendre_map(t_mlx *mlx)
{
	t_axis	ax;
	ax.y = 0;

	while (mlx->game.map[ax.y])
	{
		ax.x = 0;
		while (mlx->game.map[ax.y][ax.x] && ax.x < mlx->game.column)
		{
			if(mlx->game.map[ax.y][ax.x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.wall, ax.x * 80, ax.y * 80);
			if (mlx->game.map[ax.y][ax.x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.floor, ax.x * 80, ax.y * 80);
			if (mlx->game.map[ax.y][ax.x] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.player, ax.x * 80, ax.y * 80);
				
			if (mlx->game.map[ax.y][ax.x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.walk, ax.x * 80, ax.y * 80);
			if (mlx->game.map[ax.y][ax.x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tx.coin, ax.x * 80, ax.y * 80);
			ax.x++;
		}
		ax.y++;
	}
	
}

int    init_wind(t_mlx *mlx)
{	
	mlx->tx.wall = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/coin.xpm", mlx->game.column, mlx->game.row);
	mlx->tx.floor = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/floor.xpm", mlx->game.column, mlx->game.row);
	mlx->tx.player = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/player.xpm", mlx->game.column, mlx->game.row);
	mlx->tx.coin = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/coin.xpm", mlx->game.column, mlx->game.row);
	mlx->tx.walk = mlx_xpm_file_to_image(mlx->mlx, "texture/mandatory/walk.xpm", mlx->game.column, mlx->game.row);
	rendre_map(&mlx);

	return 1;
}

void	in_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (ft_putstr("MLX initialization failed", 2));
	mlx->win = mlx_new_window(mlx->mlx, mlx->game.column * 80,
		mlx->game.row * 80, "ayoub");
	if (!mlx->win)
		return (ft_putstr("WIN initialization failed", 2));
	mlx_key_hook(mlx->win, key_hook, NULL);
	init_wind(mlx);
	mlx_loop(mlx->mlx);
}