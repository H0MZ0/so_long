/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:07:21 by hakader           #+#    #+#             */
/*   Updated: 2025/03/08 02:05:58 by hakader          ###   ########.fr       */
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
	mlx_destroy_window(mlx->mlx, mlx->win);  // Destroy the window
	free_images(mlx);  // Free the textures
	free_arr(mlx->game.map);  // Free the map (and copy if needed)
	free_arr(mlx->game.copy);  // Free the copied map
	mlx_destroy_display(mlx->mlx);  // Destroy the display connection
	free(mlx->mlx);  // Free the mlx instance
	exit(0);  // Exit the program
}

void	rendre_map(t_mlx *mlx)
{
	t_axis	ax;

	ax.y = 0;
	while (mlx->game.map[ax.y])
	{
		ax.x = 0;
		while (mlx->game.map[ax.y][ax.x] && ax.x < mlx->game.column)
		{
			if (mlx->game.map[ax.y][ax.x] == '1')
				mlx->tx.img = mlx->tx.wall;
			else if (mlx->game.map[ax.y][ax.x] == '0')
				mlx->tx.img = mlx->tx.floor;
			else if (mlx->game.map[ax.y][ax.x] == 'P')
				mlx->tx.img = mlx->tx.player;
			else if (mlx->game.map[ax.y][ax.x] == 'E')
				mlx->tx.img = mlx->tx.door;
			else if (mlx->game.map[ax.y][ax.x] == 'C')
				mlx->tx.img = mlx->tx.coin;
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->tx.img, ax.x * 80, ax.y * 80);
			ax.x++;
		}
		ax.y++;
	}
}

int	key_hook(int keyhook, t_mlx *mlx)
{
	find_player(mlx);
	if (keyhook == KEY_ESC || keyhook == ON_DESTROY)
		close_window(mlx);
	if (keyhook == KEY_W || keyhook == KEY_UP)
		move_player(mlx, mlx->p_x, mlx->p_y - 1);
	else if (keyhook == KEY_S || keyhook == KEY_DOWN)
		move_player(mlx, mlx->p_x, mlx->p_y + 1);
	else if (keyhook == KEY_A || keyhook == KEY_LEFT)
		move_player(mlx, mlx->p_x - 1, mlx->p_y);
	else if (keyhook == KEY_D || keyhook == KEY_RIGHT)
		move_player(mlx, mlx->p_x + 1, mlx->p_y);
	rendre_map(mlx);
	return (0);
}

void	init_wind(t_mlx *mlx)
{
	mlx->tx.wall = mlx_xpm_file_to_image(mlx->mlx,
			"texture/mandatory/wall.xpm",
			&mlx->game.column, &mlx->game.row);
	mlx->tx.floor = mlx_xpm_file_to_image(mlx->mlx,
			"texture/mandatory/floor.xpm",
			&mlx->game.column, &mlx->game.row);
	mlx->tx.player = mlx_xpm_file_to_image(mlx->mlx,
			"texture/mandatory/player.xpm",
			&mlx->game.column, &mlx->game.row);
	mlx->tx.coin = mlx_xpm_file_to_image(mlx->mlx,
			"texture/mandatory/coin.xpm",
			&mlx->game.column, &mlx->game.row);
	mlx->tx.door = mlx_xpm_file_to_image(mlx->mlx,
			"texture/mandatory/cave.xpm",
			&mlx->game.column, &mlx->game.row);
}

void	in_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (ft_putstr("MLX initialization failed", 2));
	mlx->win = mlx_new_window(mlx->mlx, mlx->game.column * 80,
			mlx->game.row * 80, "so_long");
	if (!mlx->win)
		return (ft_putstr("WIN initialization failed", 2));
	init_wind(mlx);
	find_player(mlx);
	rendre_map(mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->mlx);
}
